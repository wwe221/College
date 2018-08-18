package com.example.myifeelnavercom.beacontest;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.widget.TextView;

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

public class MainActivity extends AppCompatActivity {
    private BeaconManager beaconManager;
    private BeaconManager beaconManager2;
    private BeaconManager beaconManager3;

    private Region region;
    private Region region2;
    private Region region3;
    private TextView ttid, tvId, taId, mmax, strings;
    public int rss1, rss2, rss3, max, maxB;

    public Max Max = null;
    private List<Beacon> beaconList = new ArrayList<>();
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        Max = new Max();
        setContentView(R.layout.activity_main);
        tvId = (TextView) findViewById(R.id.tvId);
        ttid = (TextView) findViewById(R.id.ttId);
        taId = (TextView) findViewById(R.id.taId);
        strings = (TextView) findViewById(R.id.strings);
        mmax = (TextView) findViewById(R.id.mmax);
        max=-500;
        rss1=-500; rss2=-500; rss3=-500;
        maxB=0;
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
                    rss1=beacon1.getRssi();
                    Max.run();
                }
            }
        });
        beaconManager2.setRangingListener(new BeaconManager.RangingListener() {
            public void onBeaconsDiscovered(Region region2, List<Beacon> list) {
                if (!list.isEmpty()) {
                    Beacon beacon2 = list.get(0);
                    Log.d("Airport", "Nearest places: " + beacon2.getRssi());
                    ttid.setText(beacon2.getRssi()+"");
                    rss2=beacon2.getRssi();
                    Max.run();
                }
            }
        });
        beaconManager3.setRangingListener(new BeaconManager.RangingListener() {
            public void onBeaconsDiscovered(Region region3, List<Beacon> list) {
                if (!list.isEmpty()) {
                    Beacon beacon3 = list.get(0);
                    Log.d("Airport", "Nearest places: " + beacon3.getRssi());
                    taId.setText(beacon3.getRssi()+"");
                    rss3=beacon3.getRssi();
                    Max.run();
                }
            }
        });
        region = new Region("ranged region",
                UUID.fromString("E2C56DB5-DFFB-48D2-B060-D0F5A71096E0"), 40001, 10602);
        region2 = new Region("ranged region2",
                UUID.fromString("E2C56DB5-DFFB-48D2-B060-D0F5A71096E0"), 40001, 10596);
        region3 = new Region("ranged region3",
                UUID.fromString("E2C56DB5-DFFB-48D2-B060-D0F5A71096E0"), 40001, 10595);
        strings.setText(region.getProximityUUID().toString()+region.getMajor()+region.getMinor());
    }
    @Override

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

    class Max extends Thread {
        public void run() {
            if (rss1 > rss2 && rss1 > rss3) {
                max = rss1;
                maxB = 1;
            }
            else if (rss2 > rss1 && rss2 > rss3){
                max = rss2;
               maxB = 2;
            }
            else if (rss3 > rss1 && rss3 > rss2) {
                max = rss3;
                maxB = 3;
            }
            mmax.setText("max:"+max + "||"+maxB);
        }
    }
    @Override
    protected void onPause() {
        //beaconManager.stopRanging(region);

        super.onPause();
    }
}
