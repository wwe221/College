package com.example.myifeelnavercom.myapplication;

        import android.support.v7.app.AppCompatActivity;
        import android.os.Bundle;

        import android.util.Log;

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

        import java.util.List;

public class MainActivity extends AppCompatActivity {
    public static final String sIP = "117.16.44.94";
    //사용할 통신 포트
    public static final int sPORT = 4423;
    //데이터 보낼 클랙스
    DatagramSocket socket;
    InetAddress serverAddr;

    String deviceId;
    String formatDate;
    long time;
    String ABID = "No Beacon";
    String noiseB = "No Beacon";
    Boolean BConnect = false;
    private BeaconManager beaconManager;
    private BeaconManager beaconManager2;
    private BeaconManager beaconManager3;
    private Region regions[] = new Region[500];
    private TextView ttid, tvId, taId, mmax;
    public int rss1, rss2, rss3, max, numbofB, maxB;
    //           각 비콘의 신호세기 , 가장큰세기, 비콘갯수, 가장큰비콘의 넘버
    public int rss[]=new int[500];

    private List<Beacon> beaconList = new ArrayList<>();
    public static final int f = 10; // noise

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
        numbofB = 0;
        beaconManager = new BeaconManager(this);
        beaconManager2 = new BeaconManager(this);
        beaconManager3 = new BeaconManager(this);
        //add this below:

        regions[0] = new Region("Beacon 1",
                UUID.fromString("E2C56DB5-DFFB-48D2-B060-D0F5A71096E0"), 40001, 10602);
        regions[1] = new Region("Beacon 2",
                UUID.fromString("E2C56DB5-DFFB-48D2-B060-D0F5A71096E0"), 40001, 10596);
        regions[2] = new Region("Beacon 3",
                UUID.fromString("E2C56DB5-DFFB-48D2-B060-D0F5A71096E0"), 40001, 10595);
        numbofB = 3;
        for(int i=0;i<numbofB-1;i++)
            rss[i]=-500;
        beaconCheck();
        Thread thread = new Thread(new Runnable() {
            @Override
            public void run() {
                while (true) {
                    try {
                        Thread.sleep(2000);
                        MMax();
                    } catch (Exception e) {
                        Log.e("run", "S: Error", e);
                    }
                }
            }
        });
        thread.start();
    }
    public void MMax() {
        if (rss1 > rss2 && rss1 > rss3 && maxB != 1) {
            max = rss1;
            maxB = 1;
            ABID = regions[0].getProximityUUID().toString() + regions[0].getMajor() + regions[0].getMinor();
            mmax.setText("max:" + max + "||" + maxB);
        } else if (rss2 > rss1 && rss2 > rss3 && maxB != 2) {
            max = rss2;
            maxB = 2;
            ABID = regions[1].getProximityUUID().toString() + regions[1].getMajor() + regions[1].getMinor();
            mmax.setText("max:" + max + "||" + maxB);
        } else if (rss3 > rss1 && rss3 > rss2 && maxB != 3) {
            max = rss3;
            maxB = 3;
            ABID = regions[2].getProximityUUID().toString() + regions[2].getMajor() + regions[2].getMinor();
            mmax.setText("max:" + max + "||" + maxB);
        }
        time = System.currentTimeMillis();
        long time = System.currentTimeMillis();
        SimpleDateFormat dayTime = new SimpleDateFormat("yyyy/MM/dd HH:mm:ss.SSS");
        formatDate = dayTime.format(new Date(time));
        noiseB = noBid(maxB, numbofB);
        //현재 시간 측정 저장.
        //SendData 클래스 생성
        try {
            serverAddr = InetAddress.getByName(sIP);
        } catch (Exception e) {
            Log.e("InetAddress", "S: Error", e);
        }
        if(BConnect) {
            try {
                //UDP 통신용 소켓 생성
                socket = new DatagramSocket();
                //서버 주소 변수
                //보낼 데이터 생성
                byte[] buf = ("Hello, World").getBytes();
                //패킷으로 변경
                String line = deviceId + '|' + noiseB + '|' + formatDate;
                DatagramPacket packet = new DatagramPacket(line.getBytes(), line.getBytes().length, serverAddr, sPORT);
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

    public void beaconCheck() {
        beaconManager.setRangingListener(new BeaconManager.RangingListener() {
            @Override
            public void onBeaconsDiscovered(Region region, List<Beacon> list) {
                if (!list.isEmpty()) {
                    Beacon beacon1 = list.get(0);
                    BConnect = true;
                    Log.d("Airport", "First Beacon " + beacon1.getRssi());
                    tvId.setText(beacon1.getRssi() + "");
                    rss1 = beacon1.getRssi();
                    rss[0] = beacon1.getRssi();

                }
            }
        });
        beaconManager2.setRangingListener(new BeaconManager.RangingListener() {
            public void onBeaconsDiscovered(Region region2, List<Beacon> list) {
                if (!list.isEmpty()) {
                    Beacon beacon2 = list.get(0);
                    BConnect = true;
                    Log.d("Airport", "Second Beacon: " + beacon2.getRssi());
                    ttid.setText(beacon2.getRssi() + "");
                    rss2 = beacon2.getRssi();
                    rss[1] = beacon2.getRssi();
                }
            }
        });
        beaconManager3.setRangingListener(new BeaconManager.RangingListener() {
            public void onBeaconsDiscovered(Region region3, List<Beacon> list) {
                if (!list.isEmpty()) {
                    Beacon beacon3 = list.get(0);
                    BConnect = true;
                    Log.d("Airport", "Third Beacon " + beacon3.getRssi());
                    taId.setText(beacon3.getRssi() + "");
                    rss3 = beacon3.getRssi();
                    rss[2] = beacon3.getRssi();
                }
            }
        });
    }

    public static String noBid(int maxB, int numbofB) {
        String s = "", t = "";
        for (int i = 0; i < numbofB; i++) {
            int a = (int) (Math.random() * 100 + 1);   // 1~ 100
            if (a <= f) {
                int b = (int) (Math.random() * 2);
                if (b == 0)
                    s = s + "0";
                else {
                    s = s + "1";
                    t = t + (i + 1) + " ";
                }

            } else {
                if (maxB != i + 1)
                    s = s + "0";
                else {
                    s = s + "1";
                    t = t + (i + 1) + " ";
                }
            }

        }
        t = t.trim();
        return t;
    }

    protected void onResume() {
        super.onResume();
        SystemRequirementsChecker.checkWithDefaultDialogs(this);

        beaconManager.connect(new BeaconManager.ServiceReadyCallback() {
            @Override
            public void onServiceReady() {
                beaconManager.startRanging(regions[0]);

            }
        });
        beaconManager2.connect(new BeaconManager.ServiceReadyCallback() {
            @Override
            public void onServiceReady() {
                beaconManager2.startRanging(regions[1]);

            }
        });
        beaconManager3.connect(new BeaconManager.ServiceReadyCallback() {
            @Override
            public void onServiceReady() {
                beaconManager3.startRanging(regions[2]);

            }
        });
    }

    @Override
    protected void onPause() {
        //beaconManager.stopRanging(region);

        super.onPause();
    }
}
