package com.example.s1081406_1081447_final;

import android.content.res.ColorStateList;
import android.graphics.Color;
import android.os.Bundle;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.TextView;

import androidx.annotation.Nullable;
import androidx.fragment.app.Fragment;

public class MoreInformationFragment extends Fragment{
    private TextView mTextTitle;
    private float mTextSize = 12;
    private int red = 0;
    private int green = 0;
    private int blue = 0;
    public MoreInformationFragment() {
        // Requires empty public constructor
    }

    @Nullable
    @Override
    public View onCreateView(LayoutInflater inflater, @Nullable ViewGroup container, Bundle savedInstanceState) {
        View root = inflater.inflate(R.layout.more_information, container, false);
        mTextTitle = (TextView) root.findViewById(R.id.More_Information_Content);
        Bundle bundle = getArguments();
        if(bundle!=null){
            mTextSize = bundle.getFloat("TextSize");
            red = bundle.getInt("Red");
            green = bundle.getInt("Green");
            blue = bundle.getInt("Blue");
        }

        return root;
    }

    @Override
    public void onViewCreated(View view, @Nullable Bundle savedInstanceState) {
        super.onViewCreated(view, savedInstanceState);
        mTextTitle.setText(getResources().getString(R.string.More_Information_Content));
        mTextTitle.setTextSize(mTextSize);
        mTextTitle.setTextColor(Color.argb(255,red,green,blue));
    }
}
