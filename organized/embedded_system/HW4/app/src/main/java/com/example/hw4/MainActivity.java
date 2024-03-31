package com.example.hw4;

import androidx.appcompat.app.AppCompatActivity;
import androidx.core.app.NotificationCompatExtras;

import android.graphics.Color;
import android.os.Bundle;
import android.os.CountDownTimer;
import android.os.Handler;
import android.os.SystemClock;
import android.util.Log;
import android.util.Pair;
import android.widget.TextView;
import android.widget.Button;
import android.view.View;

import java.util.Timer;
import java.util.TimerTask;


public class MainActivity extends AppCompatActivity {
int textviewarray[][]={
        {R.id.textView1_1,R.id.textView1_2,R.id.textView1_3,R.id.textView1_4,R.id.textView1_5,R.id.textView1_6,R.id.textView1_7,R.id.textView1_8},
        {R.id.textView2_1,R.id.textView2_2,R.id.textView2_3,R.id.textView2_4,R.id.textView2_5,R.id.textView2_6,R.id.textView2_7,R.id.textView2_8},
        {R.id.textView3_1,R.id.textView3_2,R.id.textView3_3,R.id.textView3_4,R.id.textView3_5,R.id.textView3_6,R.id.textView3_7,R.id.textView3_8},
        {R.id.textView4_1,R.id.textView4_2,R.id.textView4_3,R.id.textView4_4,R.id.textView4_5,R.id.textView4_6,R.id.textView4_7,R.id.textView4_8},
        {R.id.textView5_1,R.id.textView5_2,R.id.textView5_3,R.id.textView5_4,R.id.textView5_5,R.id.textView5_6,R.id.textView5_7,R.id.textView5_8},
        {R.id.textView6_1,R.id.textView6_2,R.id.textView6_3,R.id.textView6_4,R.id.textView6_5,R.id.textView6_6,R.id.textView6_7,R.id.textView6_8},
        {R.id.textView7_1,R.id.textView7_2,R.id.textView7_3,R.id.textView7_4,R.id.textView7_5,R.id.textView7_6,R.id.textView7_7,R.id.textView7_8},
        {R.id.textView8_1,R.id.textView8_2,R.id.textView8_3,R.id.textView8_4,R.id.textView8_5,R.id.textView8_6,R.id.textView8_7,R.id.textView8_8}
};
boolean textviexbackground[][]={
        {false,false,false,false,false,false,false,false},
        {false,false,false,false,false,false,false,false},
        {false,false,false,false,false,false,false,false},
        {false,false,false,false,false,false,false,false},
        {false,false,false,false,false,false,false,false},
        {false,false,false,false,false,false,false,false},
        {false,false,false,false,false,false,false,false},
        {false,false,false,false,false,false,false,false}
};

int allpos[][]={
        {1,2},
        {2,1},
        {2,-1},
        {1,-2},
        {-1,-2},
        {-2,-1},
        {-2,1},
        {-1,2}
};
boolean canwalk[] = new boolean[8];
TextView myKnight;
TextView CurPosText;
TextView result;
boolean isEnd = false;
int curx;
int cury;
Button nextButton;
Button restartButton;
Button consecutiveButton;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
         Log.d("MainActivity","aaaa");
         super.onCreate(savedInstanceState);
         setContentView(R.layout.activity_main);
         for(int i =0;i < 8;i++){
             for(int j = 0;j < 8;j++){
                 myKnight = (TextView) findViewById(textviewarray[i][j]);
             }
         }
        nextButton = findViewById(R.id.next_button);
        restartButton = findViewById(R.id.Restart_Button);
        consecutiveButton = findViewById(R.id.Consecutive_Button);
        CurPosText = (TextView) findViewById(R.id.Current_Position_Text);
        result = (TextView) findViewById(R.id.Result_Text);
        Log.d("MainActivity","start");
        Start();
    }

    public void onClickRestartButton(View v){
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                TextView temp = (TextView) findViewById(textviewarray[i][j]);
                if ((i + j) % 2 == 1) {
                    temp.setBackgroundColor(0xFFFFFFFF);
                } else {
                    temp.setBackgroundColor(0xFF0000FF);
                }
                textviexbackground[i][j] = false;
                temp.setText("");
            }
        }
        Start();
        result.setText("");
    }
    Handler handler = new Handler();
    Runnable runner = new Runnable() {
        @Override
        public void run() {
            if(Check()) {
                Next();
                handler.postDelayed(runner, 500);
            }
            else {
                boolean breaking = false;
                for (int i = 0; i < 8; i++) {
                    for (int j = 0; j < 8; j++) {
                        if (!textviexbackground[i][j]) {
                            breaking = true;
                            break;
                        }
                    }
                    if (breaking) {
                        break;
                    }
                }
                if (breaking) {
                    result.setText("Oops!");
                }
                else {
                    result.setText("Great!");
                }
                restartButton.setEnabled(true);
            }
        }
    };
    public void onClickConsecutiveButton(View v){
        restartButton.setEnabled(false);
        consecutiveButton.setEnabled(false);
        nextButton.setEnabled(false);
        runner.run();


    }
    public void onClickNextButton(View v){
        if (!Check()) {
            boolean breaking = false;
            for (int i = 0; i < 8; i++) {
                for (int j = 0; j < 8; j++) {
                    if (!textviexbackground[i][j]) {
                        breaking = true;
                        break;
                    }
                }
                if (breaking) {
                    break;
                }
            }
            if (breaking) {
                result.setText("Oops!");
            }
            else {
                result.setText("Great!");
            }
            consecutiveButton.setEnabled(false);
            nextButton.setEnabled(false);
        }
        else{
            Next();
        }

    }
    void Start(){
        restartButton.setEnabled(true);
        consecutiveButton.setEnabled(true);
        nextButton.setEnabled(true);
        curx = (int)(Math.random()*8);
        cury = (int)(Math.random()*8);
        TextView temp = (TextView) findViewById(textviewarray[curx][cury]);
        temp.setText("@");
        String tempstr = String.valueOf(curx+1)+","+String.valueOf(cury+1);
        CurPosText.setText(tempstr);
        Log.d("MainActivity",tempstr);
    }
    void Next(){
        TextView temp = (TextView) findViewById(textviewarray[curx][cury]);
        if (Check()) {
            int rand = (int)(Math.random()*8);
            for (int i = 0; i < 8; i++) {
                if (canwalk[(i + rand) % 8]) {
                    temp.setText("");
                    temp.setBackgroundColor(0xffff0000);
                    textviexbackground[curx][cury] = true;
                    curx = curx + allpos[(i + rand) % 8][0];
                    cury = cury + allpos[(i + rand) % 8][1];
                    temp = (TextView) findViewById(textviewarray[curx][cury]);
                    temp.setText("@");
                    String tempstr = String.valueOf(curx+1)+","+String.valueOf(cury+1);
                    CurPosText.setText(tempstr);
                    break;
                }
            }
        }
    }
    boolean Check(){
        for(int i=0;i<8;i++){
            canwalk[i] = true;
            if(curx+allpos[i][0]<0||curx+allpos[i][0]>7){
                Log.d("MainActivity","x "+String.valueOf(curx+allpos[i][0]));
                canwalk[i] = false;
            }
            if(cury+allpos[i][1]<0||cury+allpos[i][1]>7){
                Log.d("MainActivity","y "+String.valueOf(cury+allpos[i][1]));
                canwalk[i] = false;
            }
            if(canwalk[i]) {
                Color.argb(100, 255, 0, 0);
                TextView temp = (TextView) findViewById(textviewarray[curx + allpos[i][0]][cury + allpos[i][1]]);
                if (!textviexbackground[curx + allpos[i][0]][cury + allpos[i][1]]) {
                    canwalk[i] = true;
                }
                else {
                    canwalk[i] = false;
                }
            }
        }
        for (int i=0;i<8;i++){
            if (canwalk[i]) {
                return true;
            }
        }
        return false;
    }
}