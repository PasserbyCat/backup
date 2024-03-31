package com.example.hw3;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.TextView;
import android.util.Log;

public class weight_activity extends AppCompatActivity {

    TextView StandardWeight;
    TextView WeightRange;
    TextView Calories;
    Bundle MainValue = new Bundle();
    String curStandardWeight;
    String curWeightRange;
    String curCalories;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        //this.overridePendingTransition(R.xml.animation_enter,R.xml.animation_exit);
        setContentView(R.layout.activity_weight);

        StandardWeight = (TextView)findViewById(R.id.StandardWeight_Output_Text);
        WeightRange = (TextView)findViewById(R.id.WeightRange_Output_Text);
        Calories = (TextView)findViewById(R.id.Calories_Output_Text);

        MainValue = this.getIntent().getExtras();
        if(MainValue != null){
            Log.d("Tag", MainValue.getInt("curHeight")+"in Weight Activity");
            curStandardWeight = MainValue.getString("curStandardWeight");
            curWeightRange = MainValue.getString("curWeightRange");
            curCalories = MainValue.getString("curCalories");

            StandardWeight.setText(curStandardWeight);
            WeightRange.setText(curWeightRange);
            Calories.setText(curCalories);
        }

    }
    /*
    @Override
    protected void onStart(){
        super.onStart();
        this.overridePendingTransition(R.xml.animation_exit,
                R.xml.animation_enter);
        setContentView(R.layout.activity_main);
    }
    */
    public void AppButtonOnClick(View view){
        Intent intent = new Intent();
        intent.setClass(weight_activity.this,introduction_activity.class);
        Log.d("Tag", String.valueOf(MainValue.getInt("curHeight"))+"in Weight Activity");
        if(MainValue!=null){

            intent.putExtras(MainValue);
        }
        startActivity(intent);
        this.overridePendingTransition(R.xml.animation_right_enter,R.xml.animation_right_exit);
    }

    public void informationButtonOnClick(View view){
        Intent intent = new Intent();
        intent.setClass(weight_activity.this,MainActivity.class);
        Log.d("Tag", String.valueOf(MainValue.getInt("curHeight"))+"in Weight Activity");
        if(MainValue!=null){
            intent.putExtras(MainValue);
        }
        startActivity(intent);
        this.overridePendingTransition(R.xml.animation_left_enter,R.xml.animation_left_exit);
    }
}