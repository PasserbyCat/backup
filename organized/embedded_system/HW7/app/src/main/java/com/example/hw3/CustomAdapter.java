package com.example.hw3;

import android.util.Log;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.CheckBox;
import android.widget.TextView;
import android.widget.Toast;

import androidx.recyclerview.widget.RecyclerView;

import java.util.ArrayList;
import java.util.List;

public class CustomAdapter extends RecyclerView.Adapter<CustomAdapter.ViewHolder> {

    List<String> localDataSet;
    ArrayList<Boolean> myCheckBox = new ArrayList<>();
    ArrayList<Boolean> curChecked = new ArrayList<>();
    /**
     * Provide a reference to the type of views that you are using
     * (custom ViewHolder).
     */
    public static class ViewHolder extends RecyclerView.ViewHolder implements View.OnClickListener {
        private CheckBox checkBox;
        private TextView textView;
        ItemClickListener itemClickListener;

        public ViewHolder(View view) {
            super(view);
            // Define click listener for the ViewHolder's View
            textView = (TextView) view.findViewById(R.id.textView);
            checkBox = (CheckBox) view.findViewById(R.id.checkbox);
            checkBox.setOnClickListener(this);
        }
        @Override
        public void onClick(View v) {
            this.itemClickListener.onItemClick(v,getLayoutPosition());
        }

        public void setItemClickListener(ItemClickListener ic)
        {
            this.itemClickListener=ic;
        }

        interface ItemClickListener {
            void onItemClick(View v,int pos);
        }

        public CheckBox getCheckBox() {
            return checkBox;
        }

        public TextView getTextView(){
            return textView;
        }
    }

    /**
     * Initialize the dataset of the Adapter.
     *
     * @param dataSet String[] containing the data to populate views to be used
     * by RecyclerView.
     */
    public CustomAdapter(List dataSet) {
        localDataSet = dataSet;
        if(localDataSet==null){
            localDataSet = new ArrayList<>();
        }
    }

    // Create new views (invoked by the layout manager)
    @Override
    public ViewHolder onCreateViewHolder(ViewGroup viewGroup, int viewType) {
        // Create a new view, which defines the UI of the list item
        View view = LayoutInflater.from(viewGroup.getContext())
                .inflate(R.layout.text_row_item, viewGroup, false);

        return new ViewHolder(view);
    }

    // Replace the contents of a view (invoked by the layout manager)
    @Override
    public void onBindViewHolder(ViewHolder viewHolder, final int position) {
        // Get element from your dataset at this position and replace the
        // contents of the view with that element
        viewHolder.getTextView().setText(String.valueOf(position));
        viewHolder.getCheckBox().setText(localDataSet.get(position));
        while(myCheckBox.size()<localDataSet.size()){
            myCheckBox.add(false);
        }
        viewHolder.getCheckBox().setChecked(myCheckBox.get(position));
        viewHolder.setItemClickListener(new ViewHolder.ItemClickListener() {
            @Override
            public void onItemClick(View v, int pos) {
                CheckBox curCheckBox= (CheckBox) v;
                boolean Checked= CustomAdapter.this.myCheckBox.get(pos);

                if(curCheckBox.isChecked()) {
                    CustomAdapter.this.myCheckBox.set(pos,true);
                    CustomAdapter.this.curChecked.add(true);
                    Log.d("Tag", String.valueOf(pos)+" is Checked");
                }
                else if(!curCheckBox.isChecked()) {
                    CustomAdapter.this.myCheckBox.set(pos,false);
                    CustomAdapter.this.curChecked.remove(true);
                    Log.d("Tag", String.valueOf(pos)+" is unChecked");
                }
            }
        });
    }


    // Return the size of your dataset (invoked by the layout manager)
    @Override
    public int getItemCount() {
        if(localDataSet==null)
            return 0;
        return localDataSet.size();
    }
}