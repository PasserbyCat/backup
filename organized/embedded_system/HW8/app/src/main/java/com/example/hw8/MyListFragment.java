package com.example.hw8;
import android.app.Activity;
import android.app.Fragment;
import android.content.Intent;
import android.os.Bundle;
import android.util.Log;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.AdapterView;
import android.widget.ArrayAdapter;
import android.widget.ListView;

import androidx.recyclerview.widget.LinearLayoutManager;
import androidx.recyclerview.widget.RecyclerView;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
public class MyListFragment extends Fragment {
    private EndlessRecyclerViewScrollListener scrollListener;
    private static int firstVisibleInListview = 0;
    @Override
    public View onCreateView(LayoutInflater inflater, ViewGroup container, Bundle savedInstanceState) {
        // Now that we have some dummy shade data, create an ArrayAdapter.
        // The ArrayAdapter will take data from a source (like our dummy shades) and
        // use it to populate the ListView it's attached to.
        View rootView = inflater.inflate(R.layout.color_list_fragment, container, false);
        RecyclerView myView = (RecyclerView)rootView.findViewById(R.id.listview_shades);
        LinearLayoutManager linearLayoutManager= new LinearLayoutManager(getContext());
        CustomAdapter adapter = new CustomAdapter(0,10);
        myView.setAdapter(adapter);
        myView.setLayoutManager(linearLayoutManager);
        /*
        int currentFirstVisible =  linearLayoutManager.findFirstVisibleItemPosition();
        myView.setOnScrollChangeListener(new View.OnScrollChangeListener() {
            @Override
            public void onScrollChange(View v, int scrollX, int scrollY, int oldScrollX, int oldScrollY) {
                int currentFirstVisible = linearLayoutManager.findFirstVisibleItemPosition();
                if(currentFirstVisible > firstVisibleInListview)
                    Log.i("RecyclerView scrolled: ", "scroll up!");
                else
                    Log.i("RecyclerView scrolled: ", "scroll down!");

                if(firstVisibleInListview>currentFirstVisible){
                    adapter.setRangemax(firstVisibleInListview);
                    adapter.setRangemin(currentFirstVisible);
                }
                else{
                    adapter.setRangemax(currentFirstVisible);
                    adapter.setRangemin(firstVisibleInListview);
                }
                firstVisibleInListview = currentFirstVisible;
                adapter.notifyDataSetChanged();
            }
        });
        */

        /*
        scrollListener = new EndlessRecyclerViewScrollListener(linearLayoutManager) {
            @Override
            public void onLoadMore(int page, int totalItemsCount, RecyclerView view) {
                Log.d("debug",String.valueOf(page));

            }
        };
        myView.addOnScrollListener(scrollListener);
        */
        return rootView;
    }
}
