package com.example.hw8;

import android.app.Activity;
import android.app.Fragment;
import android.app.FragmentManager;
import android.app.FragmentTransaction;
import android.content.Intent;
import android.content.res.Configuration;
import android.os.Bundle;
import android.util.Log;

import androidx.appcompat.app.AppCompatActivity;

public class MyActivity extends AppCompatActivity {
    //boolean afterRotate;
    //Fragment curFragment;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        MyListFragment myListFragment = new MyListFragment();
        InformationFragment myinformationFragment = new InformationFragment();
        FragmentManager fragmentManager = getFragmentManager();
        //afterRotate = true;
        setContentView(R.layout.activity_my);

        FragmentTransaction fragmentTransaction = fragmentManager.beginTransaction();
        //fragmentTransaction.add(R.id.fragment1, myListFragment);

        //fragmentTransaction.add(R.id.fragment2,myinformationFragment,"InfoFragment");
        //fragmentTransaction.hide(myinformationFragment);
        //Log.d("Debug","AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAa");
        fragmentTransaction.replace(R.id.fragment1,myListFragment, "ListFragment");
        fragmentTransaction.commit();
    }

    /*
    public void switchFragment(String fromTag, String toTag){
        FragmentManager fragmentManager = getFragmentManager();
        Fragment from = fragmentManager.findFragmentByTag(fromTag);
        Fragment to = fragmentManager.findFragmentByTag(toTag);
        if(curFragment != to){
            curFragment = to;
            FragmentTransaction transaction = fragmentManager.beginTransaction();
            if(!to.isAdded()){
                transaction.hide(from).add(to.getId(),to).commit();
            }
            else{
                transaction.hide(from).show(to).commit();
            }
        }
    }
    */

/*
    @Override
    public void onDestroy () {
        if (!(afterRotate || this == null)) {
            final androidx.fragment.app.FragmentManager fragmentManager = getSupportFragmentManager();
            final androidx.fragment.app.Fragment fragment = fragmentManager.findFragmentById(R.id.fragment1);
            if (fragment != null)
                fragmentManager.beginTransaction().remove(fragment).commit();
            final Fragment fragment2 = fragmentManager.findFragmentById(R.id.fragment2);
            if (fragment2 != null)
                fragmentManager.beginTransaction().remove(fragment2).commit();
        }
        super.onDestroy();
    }

    @Override
    public void onConfigurationChanged(Configuration newConfig) {
        super.onConfigurationChanged(newConfig);
        if (newConfig.orientation == Configuration.ORIENTATION_LANDSCAPE) {
            Log.d("debug","LandScape");
            setContentView(R.layout.layout_land);
        } else if (newConfig.orientation == Configuration.ORIENTATION_PORTRAIT){
            Log.d("debug","Portrait");
            setContentView(R.layout.layout_portrait);
        }
    }
*/
}
