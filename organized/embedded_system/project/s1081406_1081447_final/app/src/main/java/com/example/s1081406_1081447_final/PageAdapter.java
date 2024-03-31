package com.example.s1081406_1081447_final;

import android.os.Bundle;
import android.text.style.UpdateLayout;
import android.util.Log;

import androidx.annotation.NonNull;
import androidx.fragment.app.Fragment;
import androidx.fragment.app.FragmentManager;
import androidx.lifecycle.Lifecycle;
import androidx.viewpager2.adapter.FragmentStateAdapter;

import java.lang.reflect.Array;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class PageAdapter extends FragmentStateAdapter {
    private float mtextSize = 12;
    private int red = 0;
    private int green = 0;
    private int blue = 0;
    FragmentManager fragmentManager;
    Lifecycle lifecycle;

    public PageAdapter(@NonNull FragmentManager fragmentManager, @NonNull Lifecycle lifecycle) {
        super(fragmentManager, lifecycle);
    }

    @NonNull
    @Override
    public Fragment createFragment(int position) {
        if(position== 0){
            IndexFragment indexFragment = new IndexFragment();
            Bundle bundle = new Bundle();
            bundle.putFloat("TextSize",mtextSize);
            bundle.putInt("Red",red);
            bundle.putInt("Green",green);
            bundle.putInt("Blue",blue);
            indexFragment.setArguments(bundle);
            return indexFragment;
        }
        else if(position == 1){
            NPProblemIntroductionFragment npProblemIntroductionFragment = new NPProblemIntroductionFragment();
            Bundle bundle = new Bundle();
            bundle.putFloat("TextSize",mtextSize);
            bundle.putInt("Red",red);
            bundle.putInt("Green",green);
            bundle.putInt("Blue",blue);
            npProblemIntroductionFragment.setArguments(bundle);
            return npProblemIntroductionFragment;
        }
        else if(position == 2){
            NPProblemApplicationFragment npProblemApplicationFragment = new NPProblemApplicationFragment();
            Bundle bundle = new Bundle();
            bundle.putFloat("TextSize",mtextSize);
            bundle.putInt("Red",red);
            bundle.putInt("Green",green);
            bundle.putInt("Blue",blue);
            npProblemApplicationFragment.setArguments(bundle);
            return npProblemApplicationFragment;
        }
        else if(position == 3){
            MoreInformationFragment moreInformationFragment = new MoreInformationFragment();
            Bundle bundle = new Bundle();
            bundle.putFloat("TextSize",mtextSize);
            bundle.putInt("Red",red);
            bundle.putInt("Green",green);
            bundle.putInt("Blue",blue);
            moreInformationFragment.setArguments(bundle);
            return moreInformationFragment;
        }

        else if(position ==4){
            ProductIntroductionFragment productIntroductionFragment = new ProductIntroductionFragment();
            Bundle bundle = new Bundle();
            bundle.putFloat("TextSize",mtextSize);
            bundle.putInt("Red",red);
            bundle.putInt("Green",green);
            bundle.putInt("Blue",blue);
            productIntroductionFragment.setArguments(bundle);
            return productIntroductionFragment;
        }
        else{
            Log.d("Debug","Invalid position");
            return null;
        }
    }

    @Override
    public int getItemCount() {
        return 5;
    }

    public void setTextSize(float textSize){
        mtextSize = textSize;
    }

    public void setColor(int newred,int newgreen, int newblue){
        red = newred;
        green = newgreen;
        blue = newblue;
    }
}

