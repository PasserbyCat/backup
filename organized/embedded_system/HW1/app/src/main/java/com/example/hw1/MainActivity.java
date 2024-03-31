package com.example.hw1;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {


    private int temperature = 28;
    private int humidity = 28;
    private final double c1 = -8.78469475556;
    private final double c2 = 1.61139411;
    private final double c3 = 2.33854883889;
    private final double c4 = -0.14611605;
    private final double c5 = -0.012308094;
    private final double c6 = -0.0164248277778;
    private final double c7 = 0.002211732;
    private final double c8 = 0.00072546;
    private final double c9 = -0.000003582;
    private TextView temp;
    private TextView hum;
    private TextView result;
    private Button tempplus;
    private Button tempminus;
    private Button humplus;
    private Button humminus;
    private Button compute;
    private Button reset;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        tempplus = (Button)findViewById(R.id.button);
        tempminus = (Button)findViewById(R.id.button2);
        humplus = (Button)findViewById(R.id.button3);
        humminus = (Button)findViewById(R.id.button4);
        compute = (Button)findViewById(R.id.button5);
        reset = (Button)findViewById(R.id.button6);
        tempplus.setOnClickListener(toggletempplus);
        tempminus.setOnClickListener(toggletempminus);
        humplus.setOnClickListener(togglehumplus);
        humminus.setOnClickListener(togglehumminus);
        compute.setOnClickListener(togglecompute);
        reset.setOnClickListener(togglereset);
        temp = findViewById(R.id.textView2);
        hum = findViewById(R.id.textView6);
        result = findViewById(R.id.textView5);
    }



    private final View.OnClickListener toggletempplus =
            new View.OnClickListener() {
                public void onClick(View btn) {
                    if (temperature<50) {
                        temperature++;
                    }
                    else{
                        temperature = 15;
                    }
                    temp.setText(String.valueOf(temperature));
                }
            };
    private final View.OnClickListener toggletempminus =
            new View.OnClickListener() {
                public void onClick(View btn) {
                    if (temperature>15) {
                        temperature--;
                    }
                    else{
                        temperature = 50;
                    }
                    temp.setText(String.valueOf(temperature));
                }
            };
    private final View.OnClickListener togglehumplus =
            new View.OnClickListener() {
                public void onClick(View btn) {
                    if (humidity<90) {
                        humidity++;
                    }
                    else{
                        humidity = 40;
                    }
                    hum.setText(String.valueOf(humidity));
                }
            };
    private final View.OnClickListener togglehumminus =
            new View.OnClickListener() {
                public void onClick(View btn) {
                    if (humidity>40) {
                        humidity--;
                    }
                    else{
                        humidity = 90;
                    }
                    hum.setText(String.valueOf(humidity));
                }
            };
    private final View.OnClickListener togglecompute =
            new View.OnClickListener() {
                public void onClick(View btn) {
                    double myres = CaculateHeatIndex(temperature,humidity);
                    java.text.DecimalFormat myformat=new java.text.DecimalFormat("0.0");
                    String str = myformat.format(myres);
                    result.setText(str);
                }
            };
    private final View.OnClickListener togglereset =
            new View.OnClickListener() {
                public void onClick(View btn) {
                        temperature = 28;
                        humidity = 50;
                        temp.setText(String.valueOf(temperature));
                        hum.setText(String.valueOf(humidity));
                        result.setText("");
                }
            };
    private double CaculateHeatIndex(int T,int R){
        double HI = c1 + c2*T+c3*R+c4*T*R+c5*T*T+c6*R*R+c7*T*T*R+c8*T*R*R+c9*T*T*R*R;
        return HI;
    }
}