package com.example.s1081406_1081447_final;

import androidx.annotation.NonNull;
import androidx.appcompat.app.AppCompatActivity;
import androidx.fragment.app.FragmentManager;
import androidx.lifecycle.Lifecycle;
import androidx.viewpager2.widget.ViewPager2;
import androidx.appcompat.widget.Toolbar;

import android.graphics.Color;
import android.os.Bundle;
import android.util.Log;
import android.view.Menu;
import android.view.MenuItem;


import com.google.android.material.tabs.TabLayout;

import java.util.Random;

public class MainActivity extends AppCompatActivity {
    ViewPager2 viewPager2;
    TabLayout tabLayout;
    PageAdapter pageAdapter;
    int red = 0;
    int green = 0;
    int blue = 0;
    private float mTextSize = 12;
    String[] tab_title= {
            "本產品介紹",
            "NP問題介紹",
            "NP經典問題",
            "了解更多",
            "設定",
    };
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        viewPager2 = findViewById(R.id.pager);
        tabLayout = findViewById(R.id.tabLayout);
        setToolBar();
        tabLayout.addTab(tabLayout.newTab().setText(getResources().getString(R.string.Index)));
        tabLayout.addTab(tabLayout.newTab().setText(getResources().getString(R.string.NP_Introduction)));
        tabLayout.addTab(tabLayout.newTab().setText(getResources().getString(R.string.NP_Problems)));
        tabLayout.addTab(tabLayout.newTab().setText(getResources().getString(R.string.More_Information)));
        tabLayout.addTab(tabLayout.newTab().setText(getResources().getString(R.string.Product_Introduction)));

        FragmentManager fragmentManager = getSupportFragmentManager();
        Lifecycle lifecycle = getLifecycle();
        pageAdapter = new PageAdapter(fragmentManager,lifecycle);
        pageAdapter.setTextSize(mTextSize);
        viewPager2.setAdapter(pageAdapter);


        tabLayout.addOnTabSelectedListener(new TabLayout.OnTabSelectedListener() {
            @Override
            public void onTabSelected(TabLayout.Tab tab) {
                viewPager2.setCurrentItem(tab.getPosition());
            }

            @Override
            public void onTabUnselected(TabLayout.Tab tab) {

            }

            @Override
            public void onTabReselected(TabLayout.Tab tab) {

            }
        });

        viewPager2.registerOnPageChangeCallback(new ViewPager2.OnPageChangeCallback() {
            @Override
            public void onPageSelected(int position) {
                tabLayout.selectTab(tabLayout.getTabAt(position));
            }
        });
    }

    private void setToolBar() {
        /**初始化Toolbar*/
        Toolbar toolbar = findViewById(R.id.toolbar);
        /**將Toolbar綁定到setSupportActionBar*/
        setSupportActionBar(toolbar);
        /**設置大標題*/
        getSupportActionBar().setTitle(getResources().getString(R.string.App_Name));
        /**設置大標題字體顏色*/
        toolbar.setTitleTextColor(Color.WHITE);

        /**設置標題前方的Icon圖樣*/
        toolbar.setOverflowIcon(getDrawable(R.drawable.ic_baseline_settings_24));

    }

    /**程式中新增MenuItem選項*/
    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        /**itemId為稍後判斷點擊事件要用的*/
        menu.add(0,0,0,"字體放大");
        menu.add(0,1,1,"字體縮小");
        menu.add(0,2,2,"隨機顏色");
        menu.add(0,3,3,"字體黑色");
        return super.onCreateOptionsMenu(menu);
    }

    /**此處為設置點擊事件*/
    @Override
    public boolean onOptionsItemSelected(@NonNull MenuItem item) {
        /**取得Item的ItemId，判斷點擊到哪個元件*/
        switch (item.getItemId()){
            case 0:
                if (mTextSize>=20){
                    break;
                }
                mTextSize++;
                pageAdapter.setTextSize(mTextSize);
                Log.d("Debug",String.valueOf(mTextSize));
                viewPager2.setAdapter(pageAdapter);
                break;
            case 1:
                if (mTextSize<=5){
                    break;
                }
                mTextSize--;
                pageAdapter.setTextSize(mTextSize);
                Log.d("Debug",String.valueOf(mTextSize));
                viewPager2.setAdapter(pageAdapter);
                break;
            case 2:
                 Random random = new Random();
                 red = random.nextInt(256);
                 green = random.nextInt(256);
                 blue = random.nextInt(256);
                 pageAdapter.setColor(red,green,blue);
                 viewPager2.setAdapter(pageAdapter);
                break;
            case 3:
                red = 0;
                green = 0;
                blue = 0;
                pageAdapter.setColor(red,green,blue);
                viewPager2.setAdapter(pageAdapter);
                break;
        }

        return super.onOptionsItemSelected(item);
    }
}