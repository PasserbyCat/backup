package com.example.hw4;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.SeekBar;
import android.widget.TextView;

public class MenuActivity extends AppCompatActivity {

    SeekBar Diff_Bar;
    TextView Level_Text;
    Button NewGame_Button;
    Button Continue_Button;
    Button Quit_Button;
    Bundle MainBundle;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_menu);
        MainBundle = this.getIntent().getExtras();
        Diff_Bar = (SeekBar) findViewById(R.id.barbarbarbar);
        Level_Text = (TextView)findViewById(R.id.level_input_text);
        NewGame_Button = (Button)findViewById(R.id.new_game_button);
        Continue_Button = (Button)findViewById(R.id.continue_button);
        Quit_Button = (Button)findViewById(R.id.quit_button);
        Diff_Bar.setOnSeekBarChangeListener(new SeekBar.OnSeekBarChangeListener(){
            int progressChangedValue = 0;

            public void onProgressChanged(SeekBar seekBar, int progress, boolean fromUser) {
                progressChangedValue = progress;
                Level_Text.setText(String.valueOf(progress));
            }

            public void onStartTrackingTouch(SeekBar seekBar) {
            }

            public void onStopTrackingTouch(SeekBar seekBar) {
            }
        });
        MainBundle = this.getIntent().getExtras();
        if(MainBundle==null){
            Continue_Button.setEnabled(false);
            Diff_Bar.setProgress(1);
            Level_Text.setText("1");
        }
        else{
            int Diff = MainBundle.getInt("Diff_Level");
            if(Diff == 2000){
                Diff = 1;
            }
            else if(Diff == 1000){
                Diff = 2;
            }
            else if(Diff == 500){
                Diff = 3;
            }
            Diff_Bar.setProgress(Diff);
            Level_Text.setText(String.valueOf(Diff));
        }
    }

    public void NewGameOnClick(View view){
        Continue_Button.setEnabled(true);
        Intent intent = new Intent();
        intent.setClass(MenuActivity.this,MainActivity.class);
        MainBundle = new Bundle();
        MainBundle.putInt("Diff_Level", Diff_Bar.getProgress());
        MainBundle.putBoolean("first",true);
        intent.putExtras(MainBundle);
        startActivity(intent);
    }
    public void ContinueOnClick(View view){
        if(MainBundle == null){
            return;
        }
        else{
            Intent intent = new Intent();
            intent.setClass(MenuActivity.this,MainActivity.class);
            MainBundle.putInt("Diff_Level",Diff_Bar.getProgress());
            MainBundle.putBoolean("first",false);
            intent.putExtras(MainBundle);
            startActivity(intent);
        }
    }
    public void QuitOnClick(View view){
        finishAffinity();
    }

}