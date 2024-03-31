package com.example.s1081406_1081447_final;

import android.graphics.Color;
import android.os.Bundle;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.TextView;

import androidx.annotation.Nullable;
import androidx.fragment.app.Fragment;
public class IndexFragment extends Fragment{
    private TextView mTextTitle;
    private int red = 0;
    private int green = 0;
    private int blue = 0;
    public IndexFragment() {
        // Requires empty public constructor
    }

    @Nullable
    @Override
    public View onCreateView(LayoutInflater inflater, @Nullable ViewGroup container, Bundle savedInstanceState) {
        View root = inflater.inflate(R.layout.index_layout, container, false);
        mTextTitle = (TextView) root.findViewById(R.id.Index_Content);
        Bundle bundle = getArguments();
        if(bundle!=null){
            red = bundle.getInt("Red");
            green = bundle.getInt("Green");
            blue = bundle.getInt("Blue");
        }

        return root;
    }

    @Override
    public void onViewCreated(View view, @Nullable Bundle savedInstanceState) {
        super.onViewCreated(view, savedInstanceState);
        mTextTitle.setText(getResources().getString(R.string.Index_Content));
        mTextTitle.setTextSize(50);
        mTextTitle.setTextColor(Color.argb(255,red,green,blue));
    }
}
