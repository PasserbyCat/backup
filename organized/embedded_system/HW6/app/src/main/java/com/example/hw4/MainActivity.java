package com.example.hw4;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.graphics.Color;
import android.os.Bundle;
import android.os.Handler;
import android.util.Log;
import android.view.Menu;
import android.widget.TextView;
import android.widget.Button;
import android.view.View;

import org.w3c.dom.Text;


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
 boolean textviewbackground[][]={
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
Button restartButton;
Button pauseButton;
TextView HitText;
TextView MissText;
TextView ScoreText;

boolean isEnd = false;
int curX;
int curY;
int Delay = 2000;
int Score = 0;
int Hit = 0;
int Miss = 0;
int Red = 0;
boolean hitting = false;
boolean stoprunning = false;


Bundle MenuBundle = new Bundle();
    @Override
    protected void onCreate(Bundle savedInstanceState) {
         //Log.d("MainActivity","aaaa");
         super.onCreate(savedInstanceState);
         setContentView(R.layout.activity_main);
         restartButton = (Button)findViewById(R.id.Restart_Button);
         pauseButton = (Button)findViewById(R.id.Pause_Button);
         CurPosText = (TextView) findViewById(R.id.Current_Position_Text);
         HitText = (TextView) findViewById(R.id.current_hit_Text);
         MissText = (TextView) findViewById(R.id.current_miss_Text);
         ScoreText = (TextView)findViewById(R.id.current_score_Text);
         MenuBundle = this.getIntent().getExtras();
         Delay = MenuBundle.getInt("Diff_Level");
         if(Delay == 1){
             Delay = 2000;
         }
         else if(Delay ==2){
             Delay = 1000;
         }
         else if(Delay ==3){
             Delay = 500;
         }

         for(int i =0;i < 8;i++){
             for(int j = 0;j < 8;j++){
                 myKnight = (TextView) findViewById(textviewarray[i][j]);
                 myKnight.setOnClickListener(new View.OnClickListener() {
                     @Override
                     public void onClick(View v) {
                         TextView temp = (TextView)v;
                         if(temp.getText()=="@"&&!hitting){
                             Hit++;
                             HitText.setText(String.valueOf(Hit));
                             hitting = true;
                         }
                         else if(!hitting){
                            Miss++;
                            MissText.setText(String.valueOf(Miss));
                         }
                         Score = CalculateScore();
                         ScoreText.setText(String.valueOf(Score));
                     }
                 });
             }
         }

        //Log.d("MainActivity","start");
        if(MenuBundle.getBoolean("first")){
            Start();
        }
        else{
            Resume();
        }
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
                textviewbackground[i][j] = false;
                temp.setText("");
            }
        }
        Start();
    }
    Handler handler = new Handler();
    Runnable runner = new Runnable() {
        @Override
        public void run() {
            if(Check()) {
                stoprunning = true;
                handler.postDelayed(runner, Delay);
                Next();
            }
            else {
                boolean breaking = false;
                for (int i = 0; i < 8; i++) {
                    for (int j = 0; j < 8; j++) {
                        if (!textviewbackground[i][j]) {
                            breaking = true;
                            stoprunning = false;
                            break;
                        }
                    }
                    if (breaking) {
                        break;
                    }
                }
            }
        }
    };

    void Start(){
        Hit = 0;
        Miss = 0;
        Red = 1;
        Score = 0;
        HitText.setText(String.valueOf(Hit));
        MissText.setText(String.valueOf(Miss));
        ScoreText.setText(String.valueOf(Score));
        curX = (int)(Math.random()*8);
        curY = (int)(Math.random()*8);
        TextView temp = (TextView) findViewById(textviewarray[curX][curY]);
        temp.setText("@");
        String tempstr = String.valueOf(curX +1)+","+String.valueOf(curY +1);
        CurPosText.setText(tempstr);
        Log.d("MainActivity",tempstr);
        if (!stoprunning) {
            runner.run();
        }
    }

    void Next(){
        TextView temp = (TextView) findViewById(textviewarray[curX][curY]);
        if (Check()) {
            int rand = (int)(Math.random()*8);
            for (int i = 0; i < 8; i++) {
                if (canwalk[(i + rand) % 8]) {
                    temp.setText("");
                    temp.setBackgroundColor(0xffff0000);
                    textviewbackground[curX][curY] = true;
                    curX = curX + allpos[(i + rand) % 8][0];
                    curY = curY + allpos[(i + rand) % 8][1];
                    temp = (TextView) findViewById(textviewarray[curX][curY]);
                    temp.setText("@");
                    String tempstr = String.valueOf(curX +1)+","+String.valueOf(curY +1);
                    CurPosText.setText(tempstr);
                    Red++;
                    Score = CalculateScore();
                    ScoreText.setText(String.valueOf(Score));
                    break;
                }
            }
        }
        hitting = false;
    }

    boolean Check(){
        for(int i=0;i<8;i++){
            canwalk[i] = true;
            if(curX +allpos[i][0]<0|| curX +allpos[i][0]>7){
                Log.d("MainActivity","x "+String.valueOf(curX +allpos[i][0]));
                canwalk[i] = false;
            }
            if(curY +allpos[i][1]<0|| curY +allpos[i][1]>7){
                Log.d("MainActivity","y "+String.valueOf(curY +allpos[i][1]));
                canwalk[i] = false;
            }
            if(canwalk[i]) {
                Color.argb(100, 255, 0, 0);
                TextView temp = (TextView) findViewById(textviewarray[curX + allpos[i][0]][curY + allpos[i][1]]);
                canwalk[i] = !textviewbackground[curX + allpos[i][0]][curY + allpos[i][1]];
            }
        }
        for (int i=0;i<8;i++){
            if (canwalk[i]) {
                return true;
            }
        }
        return false;
    }

    public void PauseOnClick(View view){
        Intent intent = new Intent();
        intent.setClass(MainActivity.this,MenuActivity.class);
        MenuBundle = new Bundle();
        MenuBundle.putInt("Diff_Level",Delay);
        MenuBundle.putBooleanArray("Walked[0]",textviewbackground[0]);
        MenuBundle.putBooleanArray("Walked[1]",textviewbackground[1]);
        MenuBundle.putBooleanArray("Walked[2]",textviewbackground[2]);
        MenuBundle.putBooleanArray("Walked[3]",textviewbackground[3]);
        MenuBundle.putBooleanArray("Walked[4]",textviewbackground[4]);
        MenuBundle.putBooleanArray("Walked[5]",textviewbackground[5]);
        MenuBundle.putBooleanArray("Walked[6]",textviewbackground[6]);
        MenuBundle.putBooleanArray("Walked[7]",textviewbackground[7]);
        MenuBundle.putInt("Hit",Hit);
        MenuBundle.putInt("Miss",Miss);
        MenuBundle.putInt("Score",Score);
        MenuBundle.putInt("Red",Red);
        MenuBundle.putInt("curX",curX);
        MenuBundle.putInt("curY",curY);
        intent.putExtras(MenuBundle);
        stoprunning = true;
        startActivity(intent);
    }

    void Resume(){
        Hit = MenuBundle.getInt("Hit");
        Miss = MenuBundle.getInt("Miss");
        Red = MenuBundle.getInt("Red");
        Score = MenuBundle.getInt("Score");

        HitText.setText(String.valueOf(Hit));
        MissText.setText(String.valueOf(Miss));
        ScoreText.setText(String.valueOf(Score));

        textviewbackground[0] = MenuBundle.getBooleanArray("Walked[0]");
        textviewbackground[1] = MenuBundle.getBooleanArray("Walked[1]");
        textviewbackground[2] = MenuBundle.getBooleanArray("Walked[2]");
        textviewbackground[3] = MenuBundle.getBooleanArray("Walked[3]");
        textviewbackground[4] = MenuBundle.getBooleanArray("Walked[4]");
        textviewbackground[5] = MenuBundle.getBooleanArray("Walked[5]");
        textviewbackground[6] = MenuBundle.getBooleanArray("Walked[6]");
        textviewbackground[7] = MenuBundle.getBooleanArray("Walked[7]");

        curX = MenuBundle.getInt("curX");
        curY = MenuBundle.getInt("curY");

        for(int i = 0;i < 8;i++){
            for(int j = 0;j < 8;j++){
                if(textviewbackground[i][j]){
                    TextView temp = (TextView) findViewById(textviewarray[i][j]);
                    temp.setBackgroundColor(0xffff0000);
                }
            }
        }

        TextView temp = (TextView) findViewById(textviewarray[curX][curY]);
        temp.setText("@");
        String tempstr = String.valueOf(curX +1)+","+String.valueOf(curY +1);
        CurPosText.setText(tempstr);
        Log.d("MainActivity",tempstr);
        if (!stoprunning){
            runner.run();
        }
    }

    private int CalculateScore(){
        if (Hit * 100 % Red == 0) {
            return Math.max((Hit * 100 / Red) - Miss, 0);
        }
        return Math.max((Hit * 100 / Red)  + 1 - Miss, 0);
    }

}