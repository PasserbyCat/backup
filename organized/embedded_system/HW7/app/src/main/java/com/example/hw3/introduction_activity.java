package com.example.hw3;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;

public class introduction_activity extends AppCompatActivity {

    Bundle MainValue = new Bundle();
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        //this.overridePendingTransition(R.xml.animation_enter,R.xml.animation_exit);
        setContentView(R.layout.activity_introduction);
        MainValue = this.getIntent().getExtras();
    }
    /*
    @Override
    protected void onStart(){
        super.onStart();
        this.overridePendingTransition(R.xml.animation_exit,
                R.xml.animation_enter);
        setContentView(R.layout.activity_main);
    }*/

    public void IdealButtonOnClick(View view){
        Intent intent = new Intent();
        intent.setClass(introduction_activity.this,weight_activity.class);
        if(MainValue!=null){
            intent.putExtras(MainValue);
        }
        startActivity(intent);
        this.overridePendingTransition(R.xml.animation_left_enter,R.xml.animation_left_exit);
    }

    public void informationButtonOnClick(View view){
        Intent intent = new Intent();
        intent.setClass(introduction_activity.this,MainActivity.class);
        if(MainValue!=null){
            intent.putExtras(MainValue);
        }
        startActivity(intent);
        this.overridePendingTransition(R.xml.animation_right_enter,R.xml.animation_right_exit);
    }

    public void ExitButtonOnClick(View view){
        finishAffinity();
        /*
        Intent intent = new Intent(getApplicationContext(), MainActivity.class);
        intent.setFlags(Intent.FLAG_ACTIVITY_CLEAR_TOP);
        intent.putExtra("EXIT", true);
        startActivity(intent);
        //intent = new Intent(getApplicationContext(), weight_activity.class);
        //intent.setFlags(Intent.FLAG_ACTIVITY_CLEAR_TOP);
        //intent.putExtra("EXIT", true);
        //startActivity(intent);
        if (getIntent().getBooleanExtra("EXIT", false)) {
            finish();
        }*/
    }

}