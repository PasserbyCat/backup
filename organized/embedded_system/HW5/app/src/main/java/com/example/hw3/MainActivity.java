package com.example.hw3;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.text.Editable;

import android.text.TextWatcher;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {

    Button GenderButton;
    Button ModeButton;
    Button ResetButton;
    TextView Height;
    TextView Weight;
    TextView Move;
    TextView Age;
    TextView KneeHeight;
    TextView StandardWeight;
    TextView WeightRange;
    TextView Calories;
    boolean isMale = true;
    boolean calHeight = true;
    int curHeight;
    double curWeight;
    int curMove;
    int curCalories;
    int curStandardWeight;
    int curKneeHeight;
    int curAge;
    double curWeightMax;
    double curWeightMin;



    @Override
    protected void onCreate(Bundle savedInstanceState) {
        System.out.println("onCreate called");
        super.onCreate(savedInstanceState);
        //this.overridePendingTransition(R.xml.animation_enter,R.xml.animation_exit);
        setContentView(R.layout.activity_main);

        isMale = true;
        calHeight = false;

        GenderButton = (Button)findViewById(R.id.Gender_Button);
        ModeButton = (Button)findViewById(R.id.Mode_Button);
        ResetButton = (Button)findViewById(R.id.Reset_Button);
        Height = (TextView)findViewById(R.id.Height_Input_Text);
        Weight = (TextView)findViewById(R.id.Weight_Input_Text);
        Move = (TextView)findViewById(R.id.Move_Input_Text);
        Age = (TextView)findViewById(R.id.Age_Input_Text);
        KneeHeight = (TextView)findViewById(R.id.KneeHeight_Input_Text);
        //StandardWeight = (TextView)findViewById(R.id.StandardWeight_Output_Text);
        //WeightRange = (TextView)findViewById(R.id.WeightRange_Output_Text);
        //Calories = (TextView)findViewById(R.id.Calories_Output_Text);

        TextWatcher mTextWatcher = new TextWatcher() {
            @Override
            public void beforeTextChanged(CharSequence s, int start, int count, int after) {

            }

            @Override
            public void onTextChanged(CharSequence s, int start, int before, int count) {

            }

            @Override
            public void afterTextChanged(Editable s) {
                if(ValidateInput()){
                    if (calHeight) {
                        if (isMale) {
                            curHeight = (int)(85.1 + 1.73 * curKneeHeight - 0.11 * curAge);
                        }
                        else {
                            curHeight = (int)(91.45 + 1.53 * curKneeHeight - 0.16 * curAge);
                        }
                        Height.setText(String.valueOf(curHeight));
                    }
                }
            }
        };

        KneeHeight.addTextChangedListener(mTextWatcher);
        Age.addTextChangedListener(mTextWatcher);

        Bundle bundle = this.getIntent().getExtras();
        if(bundle != null){
            curHeight = bundle.getInt("curHeight");
            curWeight = bundle.getDouble("curWeight");
            curMove = bundle.getInt("curMove");
            calHeight = bundle.getBoolean("calHeight");
            isMale = bundle.getBoolean("isMale");
            if(calHeight){
                curKneeHeight = bundle.getInt("curKneeHeight");
                curAge = bundle.getInt("curAge");
            }
            if(isMale){
                GenderButton.setText("男性");
            }
            else{
                GenderButton.setText("女性");
            }
            if(calHeight){
                ModeButton.setText("估算身高");
                Height.setEnabled(false);
                Age.setEnabled(true);
                KneeHeight.setEnabled(true);
            }
            else{
                ModeButton.setText("自行輸入");
                Height.setEnabled(true);
                Age.setEnabled(false);
                KneeHeight.setEnabled(false);
            }
            Height.setText(String.valueOf(curHeight));
            Weight.setText(String.valueOf(curWeight));
            Move.setText(String.valueOf(curMove));
            Age.setText(String.valueOf(curAge));
            KneeHeight.setText(String.valueOf(curKneeHeight));
        }
        else{
            GenderButton.setText("男性");
            ModeButton.setText("自行輸入");

            Height.setEnabled(true);
            Age.setEnabled(false);
            KneeHeight.setEnabled(false);
            Height.setText("");
            Weight.setText("");
            Move.setText("");
            Age.setText("");
            KneeHeight.setText("");
            //StandardWeight.setText("");
            //WeightRange.setText("");
            //Calories.setText("");
        }
    }
    /*
    @Override
    protected void onStart(){
        super.onStart();
        this.overridePendingTransition(R.xml.animation_exit,
                R.xml.animation_enter);
        setContentView(R.layout.activity_main);
    }*/

    public void GenderButtonOnClick(View view){
        isMale = !isMale;
        if(isMale){
            GenderButton.setText("男性");
        }
        else{
            GenderButton.setText("女性");
        }
        if(ValidateInput()){
            System.out.println("Validated input");
            Compute();
            //StandardWeight.setText(String.valueOf(curStandardWeight));
            //WeightRange.setText(getWeightRange());
            //Calories.setText(String.valueOf(curCalories));
            if(calHeight){
                Height.setText(String.valueOf(curHeight));
            }
        }
    }
    /* */

    public void AppButtonOnClick(View view){
        Intent intent = new Intent();
        intent.setClass(MainActivity.this,introduction_activity.class);
        intent.putExtras(getMyBundle());
        // start the new activity
        startActivity(intent);
        this.overridePendingTransition(R.xml.animation_left_enter,R.xml.animation_left_exit);
    }

    public void IdealButtonOnClick(View view){
        Intent intent = new Intent();
        intent.setClass(MainActivity.this,weight_activity.class);
        intent.putExtras(getMyBundle());
        startActivity(intent);
        this.overridePendingTransition(R.xml.animation_right_enter,R.xml.animation_right_exit);
    }
    /*
        public void informationButtonOnClick(View view){
            Intent intent = new Intent();
            intent.setClass(MainActivity.this,introduction_activity.class);
            intent.putExtras(getMyBundle());
            startActity(intent);
        }
    /*
        public void ExitButtonOnClick(View view){
            Intent intent = new Intent();
            intent.setClass(MainActivity.this,introduction_activity.class);
            startActivity(intent);
        }
    */
    public void ModeButtonOnClick(View view){
        calHeight = !calHeight;
        if(calHeight){
            ModeButton.setText("估算身高");
            Height.setEnabled(false);
            Age.setEnabled(true);
            KneeHeight.setEnabled(true);
        }
        else {
            ModeButton.setText("自行輸入");
            Height.setEnabled(true);
            Age.setEnabled(false);
            KneeHeight.setEnabled(false);
        }
        Height.setText("");
        Weight.setText("");
        Move.setText("");
        Age.setText("");
        KneeHeight.setText("");
        //StandardWeight.setText("");
        //WeightRange.setText("");
        //Calories.setText("");
    }
    public void ResetButtonOnClick(View view){
        System.out.println("Reset Button Clicked");
        Height.setEnabled(true);
        curHeight = 0;

        Height.setText("");
        Weight.setText("");
        Move.setText("");
        //StandardWeight.setText("");
        //WeightRange.setText("");
        //Calories.setText("");
        Age.setText("");
        KneeHeight.setText("");
        calHeight = false;
        ModeButton.setText("自行輸入");
        Age.setEnabled(false);
        KneeHeight.setEnabled(false);
        isMale = true;
        GenderButton.setText("男性");
    }

    private Bundle getMyBundle(){
        Bundle bundle = new Bundle();
        if(ValidateInput()){
            Compute();
            bundle.putString("curStandardWeight",String.valueOf(curStandardWeight));
            bundle.putString("curWeightRange", getWeightRange());
            bundle.putString("curCalories", String.valueOf(curCalories));
        }
        bundle.putInt("curHeight", curHeight);
        bundle.putDouble("curWeight",curWeight);
        bundle.putInt("curMove",curMove);
        bundle.putBoolean("calHeight",calHeight);
        bundle.putBoolean("isMale",isMale);
        bundle.putInt("curKneeHeight",curKneeHeight);
        bundle.putInt("curAge",curAge);
        return bundle;
    }

    private boolean ValidateInput(){
        if(!calHeight) {
            if (!Height.getText().toString().equals("")) {
                curHeight = Integer.parseInt(Height.getText().toString());
                System.out.println("curHeight");
                if (curHeight < 0) {
                    return false;
                }
            }
            else {
                return false;
            }
        }
        else{
            if(!KneeHeight.getText().toString().equals("")) {
                curKneeHeight = Integer.parseInt(KneeHeight.getText().toString());
                System.out.println("curKneeHeight");
                if(curKneeHeight<0){
                    return false;
                }
            }
            else{
                return false;
            }
            if(!Age.getText().toString().equals("")) {
                curAge = Integer.parseInt(Age.getText().toString());
                System.out.println("curAge");
                return curAge >= 0;
            }
            else{
                return false;
            }
        }
        String temp = Weight.getText().toString();
        if(!temp.equals("")) {
            curWeight = Double.parseDouble(temp);
            System.out.println("curWeight");
            int index = temp.indexOf(".");
            if(index > temp.length()-1){
                return false;
            }
            if(curWeight<0){
                return false;
            }
        }
        else{
            return false;
        }

        if(!Move.getText().toString().equals("")) {
            curMove = Integer.parseInt(Move.getText().toString());
            System.out.println("curMove");
            return curMove >= 1 && curMove <= 3;
        }
        else{
            return false;
        }
    }

    private void Compute(){
        if (calHeight) {
            if (isMale) {
                curHeight = (int)(85.1 + 1.73 * curKneeHeight - 0.11 * curAge);
            }
            else {
                curHeight = (int)(91.45 + 1.53 * curKneeHeight - 0.16 * curAge);
            }
        }

        if (isMale) {
            curStandardWeight =  (int)((curHeight - 80) * 0.7);
        }
        else {
            curStandardWeight =  (int)((curHeight - 70) * 0.6);
        }

        curWeightMax = curStandardWeight * 1.1;
        curWeightMin = curStandardWeight * 0.9;
        if (curMove == 1) {
            if (curWeight > curWeightMax) {
                curCalories = 25 * curStandardWeight;
            }
            else if (curWeight < curWeightMin) {
                curCalories = 35 * curStandardWeight;
            }
            else {
                curCalories = 30 * curStandardWeight;
            }
        }
        else if (curMove == 2) {
            if (curWeight > curWeightMax) {
                curCalories = 30 * curStandardWeight;
            }
            else if (curWeight < curWeightMin) {
                curCalories = 40 * curStandardWeight;
            }
            else {
                curCalories = 35 * curStandardWeight;
            }
        }
        else if (curMove == 3) {
            if (curWeight > curWeightMax) {
                curCalories = 35 * curStandardWeight;
            }
            else if (curWeight < curWeightMin) {
                curCalories = 35 * curStandardWeight;
            }
            else {
                curCalories = 40 * curStandardWeight;
            }
        }
        else {
            System.out.println(curMove);
            Log.d("Tag", "Invalid input Move");
        }

    }

    private String getWeightRange(){
        java.text.DecimalFormat myFormat=new java.text.DecimalFormat("0.0");
        String strMax = myFormat.format(curWeightMax);
        String strMin = myFormat.format(curWeightMin);
        return  strMin + "-" +  strMax;
    }
}