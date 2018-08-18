package com.example.myifeelnavercom.myapplication;

import android.os.Message;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.telephony.TelephonyManager;
import android.content.Context;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;
import java.util.UUID;
import java.text.SimpleDateFormat;
import java.util.Date;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;

import com.estimote.sdk.Beacon;
import com.estimote.sdk.BeaconManager;
import com.estimote.sdk.Region;
import com.estimote.sdk.SystemRequirementsChecker;

import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.UUID;
import static android.R.attr.button;

public class MainActivity extends AppCompatActivity {
    public static final String sIP = "118.219.241.229";
    //사용할 통신 포트
    public static final int sPORT = 4421;
    //데이터 보낼 클랙스
    public SendData mSendData;
    DatagramSocket socket;
    InetAddress serverAddr;
    //화면 표시용 TextView
    public TextView txtView;
    long now = System.currentTimeMillis();
    String deviceId;
    String formatDate;
    long time;
    String BBID = "null";
    String ABID = "null";
    TextView dateNow;
    private BeaconManager beaconManager;
    private BeaconManager beaconManager2;
    private BeaconManager beaconManager3;
    private Region region;
    private Region region2;
    private Region region3;
    private TextView ttid, tvId, taId, mmax;
    public int rss1, rss2, rss3, max, maxB;
    public Max Max ;
    private List<Beacon> beaconList = new ArrayList<>();
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        final String androidId;
        androidId = "" + android.provider.Settings.Secure.getString(getContentResolver(), android.provider.Settings.Secure.ANDROID_ID);
        UUID deviceUuid = new UUID(androidId.hashCode(), (long) 0xbb << 32);
        deviceId = androidId.toString();
        TextView textView1 = (TextView) findViewById(R.id.text1);
        textView1.setText(deviceId);
        Log.d("Test", "device");
        Max = new Max();
        Max.run();
        //setContentView(R.layout.activity_main);
        tvId = (TextView) findViewById(R.id.tvId);
        ttid = (TextView) findViewById(R.id.ttId);
        taId = (TextView) findViewById(R.id.taId);
        mmax = (TextView) findViewById(R.id.mmax);
        max = -500;
        rss1 = -500;
        rss2 = -500;
        rss3 = -500;
        maxB = 0;
        beaconManager = new BeaconManager(this);
        beaconManager2 = new BeaconManager(this);
        beaconManager3 = new BeaconManager(this);
        //add this below:
        beaconManager.setRangingListener(new BeaconManager.RangingListener() {
            @Override
            public void onBeaconsDiscovered(Region region, List<Beacon> list) {
                if (!list.isEmpty()) {
                    Beacon beacon1 = list.get(0);
                    Log.d("Airport", "Nearest places: " + beacon1.getRssi());
                    tvId.setText(beacon1.getRssi() + "");
                    rss1 = beacon1.getRssi();

                }
            }
        });
        beaconManager2.setRangingListener(new BeaconManager.RangingListener() {
            public void onBeaconsDiscovered(Region region2, List<Beacon> list) {
                if (!list.isEmpty()) {
                    Beacon beacon2 = list.get(0);
                    Log.d("Airport", "Nearest places: " + beacon2.getRssi());
                    ttid.setText(beacon2.getRssi() + "");
                    rss2 = beacon2.getRssi();

                }
            }
        });
        beaconManager3.setRangingListener(new BeaconManager.RangingListener() {
            public void onBeaconsDiscovered(Region region3, List<Beacon> list) {
                if (!list.isEmpty()) {
                    Beacon beacon3 = list.get(0);
                    Log.d("Airport", "Nearest places: " + beacon3.getRssi());
                    taId.setText(beacon3.getRssi() + "");
                    rss3 = beacon3.getRssi();

                }
            }
        });

        region = new Region("Beacon 1",
                UUID.fromString("E2C56DB5-DFFB-48D2-B060-D0F5A71096E0"), 40001, 10602);
        region2 = new Region("Beacon 2",
                UUID.fromString("E2C56DB5-DFFB-48D2-B060-D0F5A71096E0"), 40001, 10596);
        region3 = new Region("Beacon 3",
                UUID.fromString("E2C56DB5-DFFB-48D2-B060-D0F5A71096E0"), 40001, 10595);


        time = System.currentTimeMillis();
        long time = System.currentTimeMillis();
        SimpleDateFormat dayTime = new SimpleDateFormat("yyyy/MM/dd HH:mm:ss");
        formatDate = dayTime.format(new Date(time));
        //현재 시간 측정 저장.
        //SendData 클래스 생성
        mSendData = new SendData();
        //보내기 시작
        mSendData.run();
        try {
            Thread.sleep(2000);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    } class SendData extends Thread{
        public void run() {
            if (BBID != ABID) {
                BBID=ABID;
                try {
                    serverAddr = InetAddress.getByName("118.219.241.229");
                } catch (Exception e) {
                    Log.e("InetAddress", "S: Error", e);
                }
                try {
                    //UDP 통신용 소켓 생성
                    socket = new DatagramSocket();
                    //서버 주소 변수
                    //보낼 데이터 생성
                    byte[] buf = ("Hello, World").getBytes();
                    //패킷으로 변경
                    String line = deviceId + '|' + BBID + '|' + formatDate;
                    DatagramPacket packet = new DatagramPacket(line.getBytes(), line.getBytes().length, serverAddr, 4421);
                    //DatagramPacket packet = new DatagramPacket(buf, buf.length, serverAddr, 4421);
                    //패킷 전송!
                    TextView textView1 = (TextView) findViewById(R.id.text1);
                    socket.send(packet);
                    textView1.setText(line);
                    Log.d("Test", "s:send packet" + buf.length);
                    socket.close();

                } catch (Exception e) {
                    Log.e("UDP", "S: Error", e);
                }
            }
        }
    }
    class Max extends Thread {
        public void run() {
            if (rss1 > rss2 && rss1 > rss3) {
                max = rss1;
                maxB = 1;
                ABID = region.getProximityUUID().toString()+region.getMajor()+region.getMinor();
                mmax.setText("max:"+max + "||"+maxB);

            }
            else if (rss2 > rss1 && rss2 > rss3){
                max = rss2;
                maxB = 2;
                ABID = region2.getProximityUUID().toString()+region2.getMajor()+region2.getMinor();
                mmax.setText("max:"+max + "||"+maxB);

            }
            else if (rss3 > rss1 && rss3 > rss2) {
                max = rss3;
                maxB = 3;
                ABID = region2.getProximityUUID().toString()+region2.getMajor()+region2.getMinor();
                mmax.setText("max:"+max + "||"+maxB);

            }
        }
    }
    protected void onResume() {
        super.onResume();
        SystemRequirementsChecker.checkWithDefaultDialogs(this);

        beaconManager.connect(new BeaconManager.ServiceReadyCallback() {
            @Override
            public void onServiceReady() {
                beaconManager.startRanging(region);
            }
        });
        beaconManager2.connect(new BeaconManager.ServiceReadyCallback() {
            @Override
            public void onServiceReady() {
                beaconManager2.startRanging(region2);
            }
        });
        beaconManager3.connect(new BeaconManager.ServiceReadyCallback() {
            @Override
            public void onServiceReady() {
                beaconManager3.startRanging(region3);
            }
        });
    }

    @Override
    protected void onPause() {
        //beaconManager.stopRanging(region);

        super.onPause();
    }
}
