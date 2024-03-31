package com.example.hw8;

import android.app.FragmentManager;
import android.app.FragmentTransaction;
import android.os.Bundle;
import android.util.Log;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.TextView;

import androidx.appcompat.app.AppCompatActivity;
import androidx.recyclerview.widget.RecyclerView;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class CustomAdapter extends RecyclerView.Adapter<CustomAdapter.ViewHolder> {


    int rangemin = 0;
    int rangemax = 10;
    List<String> shadelisting = new ArrayList<String>(Arrays.asList(DummyData.shade_name));
    List<String> shadeNameDetail = new ArrayList<String>(Arrays.asList(DummyData.shade_detail));
    /**
     * Provide a reference to the type of views that you are using
     * (custom ViewHolder).
     */
    public static class ViewHolder extends RecyclerView.ViewHolder {
        private final TextView mtextView;
        ItemClickListener itemClickListener;

        public ViewHolder(View view) {
            super(view);
            // Define click listener for the ViewHolder's View
            mtextView = (TextView) view.findViewById(R.id.list_item_shade_textview);
            mtextView.setOnClickListener(new View.OnClickListener() {
                @Override
                public void onClick(View v) {
                    itemClickListener.onItemClick(v,getLayoutPosition());
                }
            });

        }

        public TextView getTextView() {
            return mtextView;
        }
        public void onClick(View v) {
            itemClickListener.onItemClick(v,getLayoutPosition());
        }
        public void setItemClickListener(ViewHolder.ItemClickListener ic)
        {
            this.itemClickListener=ic;
        }
        interface ItemClickListener {
            void onItemClick(View v,int pos);
        }
    }


    public CustomAdapter(int min,int max) {
        rangemax = max;
        rangemin = min;
    }

    // Create new views (invoked by the layout manager)
    @Override
    public ViewHolder onCreateViewHolder(ViewGroup viewGroup, int viewType) {
        // Create a new view, which defines the UI of the list item
        View view = LayoutInflater.from(viewGroup.getContext()).inflate(R.layout.list_item_shade, viewGroup, false);
        return new ViewHolder(view);
    }

    // Replace the contents of a view (invoked by the layout manager)
    @Override
    public void onBindViewHolder(ViewHolder viewHolder, final int position) {

        // Get element from your dataset at this position and replace the
        // contents of the view with that element
       if(position>rangemin&&position<rangemax){
           viewHolder.getTextView().setText(shadelisting.get(position));
       }
        viewHolder.setItemClickListener(new ViewHolder.ItemClickListener() {
            @Override
            public void onItemClick(View v, int pos) {
                //MyActivity.switchFragment("ListFragment","InfoFragment");
                Log.d("debug","Clicked");
                AppCompatActivity activity = (AppCompatActivity) v.getContext();
                //MyListFragment myListFragment = new MyListFragment();
                InformationFragment myInformationFragment = new InformationFragment();
                Bundle bundle = new Bundle();
                if(pos>=0&&pos<shadeNameDetail.size()){
                    bundle.putString("information",shadeNameDetail.get(pos));
                    myInformationFragment.setArguments(bundle);
                    activity.getFragmentManager().beginTransaction().replace(R.id.fragment2, myInformationFragment).commit();
                }

                /*
                FragmentManager fragmentManager = activity.getFragmentManager();
                FragmentTransaction fragmentTransaction =fragmentManager.beginTransaction();
                if(myInformationFragment.isAdded()){
                    myInformationFragment.setArguments(bundle);
                    fragmentTransaction.add(R.id.fragment2,myInformationFragment,"InfoFragment");
                }
                else{
                    fragmentTransaction.remove(myInformationFragment);
                    myInformationFragment.setArguments(bundle);
                    fragmentTransaction.add(R.id.fragment2,myInformationFragment,"InfoFragment");
                }
                */
            }
        });
    }

    // Return the size of your dataset (invoked by the layout manager)
    @Override
    public int getItemCount() {
        return shadelisting.size();
    }

    public void setRangemin(int min){
        rangemin = min;
    }

    public void setRangemax(int max){
        rangemax = max;
    }
}
