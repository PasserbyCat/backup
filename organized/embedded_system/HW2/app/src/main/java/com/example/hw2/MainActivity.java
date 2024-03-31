package com.example.hw2;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {

    Button GenderButton;
    Button CompButton;
    Button ResetButton;
    TextView Height;
    TextView Weight;
    TextView Move;
    TextView StandardWeight;
    TextView WeightRange;
    TextView Calories;
    TextView ErrorMessage;
    boolean isMale = true;

    int curHeight;
    double curWeight;
    int curMove;
    int curCalories;
    int curStandardWeight;
    double curWeightMax;
    double curWeightMin;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        isMale = true;
        GenderButton = (Button)findViewById(R.id.Gender_Button);
        CompButton = (Button)findViewById(R.id.Comp_Button);
        ResetButton = (Button)findViewById(R.id.Reset_Button);
        Height = (TextView)findViewById(R.id.Height_Input_Text);
        Weight = (TextView)findViewById(R.id.Weight_Input_Text);
        Move = (TextView)findViewById(R.id.Move_Input_Text);
        StandardWeight = (TextView)findViewById(R.id.StandardWeight_Output_Text);
        WeightRange = (TextView)findViewById(R.id.WeightRange_Output_Text);
        Calories = (TextView)findViewById(R.id.Calories_Output_Text);
        ErrorMessage = (TextView)findViewById(R.id.ErrorMessage_Text);
    }

    public void GenderButtonOnClick(View view){
        isMale = !isMale;
        if(isMale){
            GenderButton.setText("男性");
        }
        else{
            GenderButton.setText("女性");
        }
    }
    public void CompButtonOnClick(View view){
        if(ValidateInput()){
            Compute();
            StandardWeight.setText(String.valueOf(curStandardWeight));
            WeightRange.setText(getWeightRange());
            Calories.setText(String.valueOf(curCalories));
        }
    }
    public void ResetButtonOnClick(View view){
        Height.setText("");
        Weight.setText("");
        Move.setText("");
        StandardWeight.setText("");
        WeightRange.setText("");
        Calories.setText("");
        ErrorMessage.setVisibility(View.INVISIBLE);
        isMale = true;
        GenderButton.setText("男性");
    }

    private boolean ValidateInput(){
        curHeight = Integer.parseInt(Height.getText().toString());
        if(curHeight<0){
            ErrorMessage.setVisibility(View.VISIBLE);
            return false;
        }
        String temp = Weight.getText().toString();
        curWeight = Double.parseDouble(temp);
        if(curWeight<0){
            ErrorMessage.setVisibility(View.VISIBLE);
            return false;
        }
        int index = temp.indexOf(".");
        if(index > temp.length()-1){
            ErrorMessage.setVisibility(View.VISIBLE);
            return false;
        }
        curMove = Integer.parseInt(Move.getText().toString());
        if(curMove<1||curMove>3){
            ErrorMessage.setVisibility(View.VISIBLE);
            return false;
        }
        return true;
    }

    private void Compute(){
        double temp;
        if(isMale){
            temp = (curHeight - 80) * 0.7;
        }
        else{
            temp = (curHeight - 70) * 0.6;
        }
        curStandardWeight = (int)temp;

        curWeightMax= curStandardWeight*1.1;
        curWeightMin = curStandardWeight*0.9;
        if(curMove==1){
            if(curWeight>curWeightMax){
                curCalories = 25*curStandardWeight;
            }
            else if(curWeight<curWeightMin){
                curCalories = 35*curStandardWeight;
            }
            else{
                curCalories = 30*curStandardWeight;
            }
        }
        else if(curMove==2){
            if(curWeight>curWeightMax){
                curCalories = 30*curStandardWeight;
            }
            else if(curWeight<curWeightMin){
                curCalories = 40*curStandardWeight;
            }
            else{
                curCalories = 35*curStandardWeight;
            }
        }
        else if(curMove==3){
            if(curWeight>curWeightMax){
                curCalories = 35*curStandardWeight;
            }
            else if(curWeight<curWeightMin){
                curCalories = 35*curStandardWeight;
            }
            else{
                curCalories = 40*curStandardWeight;
            }
        }
        else{
            Log.d("Tag","Invalid input Move");
        }
    }

    private String getWeightRange(){
        java.text.DecimalFormat myFormat=new java.text.DecimalFormat("0.0");
        String strMax = myFormat.format(curWeightMax);
        String strMin = myFormat.format(curWeightMin);
        String strWeightRange = strMin+ "-" +  strMax;
        return strWeightRange;
    }
}