package com.example.hw8;
import android.app.Fragment;
import android.os.Bundle;
import android.util.Log;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.TextView;
public class InformationFragment extends Fragment {
    @Override
    public View onCreateView(LayoutInflater inflater, ViewGroup container, Bundle savedInstanceState) {
        View view = inflater.inflate(R.layout.information_fragment, container, false);
        TextView view2 = (TextView) view.findViewById(R.id.myTextView);
        if(getArguments() != null){
            String temp = getArguments().getString("information");
            view2.setText(temp);
        }
        return view;
    }
}
