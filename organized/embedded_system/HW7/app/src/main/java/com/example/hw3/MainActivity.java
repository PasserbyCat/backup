package com.example.hw3;

import androidx.appcompat.app.AppCompatActivity;
import androidx.recyclerview.widget.LinearLayoutManager;
import androidx.recyclerview.widget.RecyclerView;

import android.content.Intent;
import android.database.Cursor;
import android.os.Bundle;
import android.provider.BaseColumns;
import android.provider.ContactsContract;
import android.service.autofill.Dataset;
import android.text.BoringLayout;
import android.text.Editable;

import android.text.TextWatcher;
import android.util.Log;
import android.view.View;
import android.widget.ArrayAdapter;
import android.widget.Button;
import android.widget.TextView;
import android.content.ContentValues;
import android.database.sqlite.SQLiteDatabase;
import android.widget.Toast;

import java.io.File;
import java.util.ArrayList;
import java.util.List;

public class MainActivity extends AppCompatActivity {

    Button GenderButton;
    Button ModeButton;
    Button ResetButton;
    TextView Height;
    TextView Weight;
    TextView Move;
    TextView Age;
    TextView KneeHeight;
    TextView StandardWeight;
    TextView WeightRange;
    TextView Calories;

    TextView Name;
    boolean isMale = true;
    boolean calHeight = true;
    int curHeight;
    double curWeight;
    int curMove;
    int curCalories;
    int curStandardWeight;
    int curKneeHeight;
    int curAge;
    double curWeightMax;
    double curWeightMin;
    String curName;

    List dataset;
    List<Boolean>checklist;

    //private static final String DataBaseName = "DataBaseIt";
    //private static final int DataBaseVersion = 1;
    //private static String DataBaseTable = "Users";
    private SQLiteDatabase db;
    SqlDataBaseHelper sqlDataBaseHelper;
    private RecyclerView recycler_view;
    private CustomAdapter adapter;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        System.out.println("onCreate called");
        super.onCreate(savedInstanceState);
        //this.overridePendingTransition(R.xml.animation_enter,R.xml.animation_exit);
        setContentView(R.layout.activity_main);

        isMale = true;
        calHeight = false;

        GenderButton = (Button)findViewById(R.id.Gender_Button);
        ModeButton = (Button)findViewById(R.id.Mode_Button);
        ResetButton = (Button)findViewById(R.id.Reset_Button);
        Height = (TextView)findViewById(R.id.Height_Input_Text);
        Weight = (TextView)findViewById(R.id.Weight_Input_Text);
        Move = (TextView)findViewById(R.id.Move_Input_Text);
        Age = (TextView)findViewById(R.id.Age_Input_Text);
        KneeHeight = (TextView)findViewById(R.id.KneeHeight_Input_Text);
        Name = (TextView)findViewById(R.id.current_name_data);
        recycler_view = (RecyclerView)findViewById(R.id.myList);

        //StandardWeight = (TextView)findViewById(R.id.StandardWeight_Output_Text);
        //WeightRange = (TextView)findViewById(R.id.WeightRange_Output_Text);
        //Calories = (TextView)findViewById(R.id.Calories_Output_Text);
        sqlDataBaseHelper = new SqlDataBaseHelper(getBaseContext());
        db = sqlDataBaseHelper.getWritableDatabase();
        checklist = new ArrayList<>();
        //adapter = new ArrayAdapter<String>(this , android.R.layout.simple_list_item_multiple_choice, values);
        UpdateList();
        adapter = new CustomAdapter(dataset);
        recycler_view.setAdapter(adapter);
        recycler_view.setLayoutManager(new LinearLayoutManager(this));
        //
        //db.execSQL("DROP TABLE IF EXISTS " + FeedReaderContract.FeedEntry.TABLE_NAME);
        TextWatcher mTextWatcher = new TextWatcher() {
            @Override
            public void beforeTextChanged(CharSequence s, int start, int count, int after) {

            }

            @Override
            public void onTextChanged(CharSequence s, int start, int before, int count) {

            }

            @Override
            public void afterTextChanged(Editable s) {
                if(ValidateInput()){
                    if (calHeight) {
                        if (isMale) {
                            curHeight = (int)(85.1 + 1.73 * curKneeHeight - 0.11 * curAge);
                        }
                        else {
                            curHeight = (int)(91.45 + 1.53 * curKneeHeight - 0.16 * curAge);
                        }
                        Height.setText(String.valueOf(curHeight));
                    }
                }
            }
        };

        KneeHeight.addTextChangedListener(mTextWatcher);
        Age.addTextChangedListener(mTextWatcher);

        Bundle bundle = this.getIntent().getExtras();
        if(bundle != null){
            curHeight = bundle.getInt("curHeight");
            curWeight = bundle.getDouble("curWeight");
            curMove = bundle.getInt("curMove");
            calHeight = bundle.getBoolean("calHeight");
            isMale = bundle.getBoolean("isMale");
            if(calHeight){
                curKneeHeight = bundle.getInt("curKneeHeight");
                curAge = bundle.getInt("curAge");
            }
            if(isMale){
                GenderButton.setText("男性");
            }
            else{
                GenderButton.setText("女性");
            }
            if(calHeight){
                ModeButton.setText("估算身高");
                Height.setEnabled(false);
                Age.setEnabled(true);
                KneeHeight.setEnabled(true);
            }
            else{
                ModeButton.setText("自行輸入");
                Height.setEnabled(true);
                Age.setEnabled(false);
                KneeHeight.setEnabled(false);
            }
            Height.setText(String.valueOf(curHeight));
            Weight.setText(String.valueOf(curWeight));
            Move.setText(String.valueOf(curMove));
            Age.setText(String.valueOf(curAge));
            KneeHeight.setText(String.valueOf(curKneeHeight));
        }
        else{
            GenderButton.setText("男性");
            ModeButton.setText("自行輸入");

            Height.setEnabled(true);
            Age.setEnabled(false);
            KneeHeight.setEnabled(false);
            Height.setText("");
            Weight.setText("");
            Move.setText("");
            Age.setText("");
            KneeHeight.setText("");
            //StandardWeight.setText("");
            //WeightRange.setText("");
            //Calories.setText("");
        }
    }
    /*
    @Override
    protected void onStart(){
        super.onStart();
        this.overridePendingTransition(R.xml.animation_exit,
                R.xml.animation_enter);
        setContentView(R.layout.activity_main);
    }*/

    public void GenderButtonOnClick(View view){
        isMale = !isMale;
        if(isMale){
            GenderButton.setText("男性");
        }
        else{
            GenderButton.setText("女性");
        }
        if(ValidateInput()){
            System.out.println("Validated input");
            Compute();
            //StandardWeight.setText(String.valueOf(curStandardWeight));
            //WeightRange.setText(getWeightRange());
            //Calories.setText(String.valueOf(curCalories));
            if(calHeight){
                Height.setText(String.valueOf(curHeight));
            }
        }
    }
    public void AppButtonOnClick(View view){
        Intent intent = new Intent();
        intent.setClass(MainActivity.this,introduction_activity.class);
        intent.putExtras(getMyBundle());
        // start the new activity
        startActivity(intent);
        this.overridePendingTransition(R.xml.animation_left_enter,R.xml.animation_left_exit);
    }
    public void IdealButtonOnClick(View view){
        Intent intent = new Intent();
        intent.setClass(MainActivity.this,weight_activity.class);
        intent.putExtras(getMyBundle());
        startActivity(intent);
        this.overridePendingTransition(R.xml.animation_right_enter,R.xml.animation_right_exit);
    }
    public void ModeButtonOnClick(View view){
        calHeight = !calHeight;
        if(calHeight){
            ModeButton.setText("估算身高");
            Height.setEnabled(false);
            Age.setEnabled(true);
            KneeHeight.setEnabled(true);
        }
        else {
            ModeButton.setText("自行輸入");
            Height.setEnabled(true);
            Age.setEnabled(false);
            KneeHeight.setEnabled(false);
        }
        Height.setText("");
        Weight.setText("");
        Move.setText("");
        Age.setText("");
        KneeHeight.setText("");
        //StandardWeight.setText("");
        //WeightRange.setText("");
        //Calories.setText("");
    }
    public void ResetButtonOnClick(View view){
        System.out.println("Reset Button Clicked");
        Height.setEnabled(true);
        curHeight = 0;

        Height.setText("");
        Weight.setText("");
        Move.setText("");
        //StandardWeight.setText("");
        //WeightRange.setText("");
        //Calories.setText("");
        Age.setText("");
        KneeHeight.setText("");
        calHeight = false;
        ModeButton.setText("自行輸入");
        Age.setEnabled(false);
        KneeHeight.setEnabled(false);
        isMale = true;
        GenderButton.setText("男性");
    }
    public Integer SqlAccountCheck(String newAccount){
        Cursor c = db.rawQuery("SELECT * FROM " + FeedReaderContract.FeedEntry.TABLE_NAME + " WHERE Name = '" +newAccount+"'",null);
        if(c==null){
            return 0;
        }
        c.moveToFirst();
        return c.getCount();
    }
    public void AddButtonOnClick(View view){
        //db = sqlDataBaseHelper.getWritableDatabase();
        String curName = Name.getText().toString();
        if(curName.length() > 0) {
            if(DataBaseisEmpty()){
                long id;
                ContentValues contentValues = new ContentValues();
                contentValues.put(FeedReaderContract.FeedEntry.COLUMN_NAME,curName);
                contentValues.put(FeedReaderContract.FeedEntry.COLUMN_HEIGHT,curKneeHeight);
                contentValues.put(FeedReaderContract.FeedEntry.COLUMN_AGE,curAge);
                contentValues.put(FeedReaderContract.FeedEntry.COLUMN_HEIGHT,curHeight);
                if(isMale){
                    contentValues.put(FeedReaderContract.FeedEntry.COLUMN_MALE,1);
                }
                else{
                    contentValues.put(FeedReaderContract.FeedEntry.COLUMN_MALE,0);
                }
                contentValues.put(FeedReaderContract.FeedEntry.COLUMN_WEIGHT,curWeight);
                contentValues.put(FeedReaderContract.FeedEntry.COLUMN_MOVE,curMove);
                id = db.insert(FeedReaderContract.FeedEntry.TABLE_NAME,null,contentValues);
                Toast.makeText(MainActivity.this,"帳號新增成功:"+id,Toast.LENGTH_LONG).show();
                UpdateList();
                adapter = new CustomAdapter(dataset);
                recycler_view.setAdapter(adapter);
            }
            else{
                if(SqlAccountCheck(curName) > 0){
                    Toast.makeText(MainActivity.this,"該名稱已存在!!",Toast.LENGTH_LONG).show();
                    //UpdateListView();
                }
                else {
                    long id;
                    ValidateInput();
                    ContentValues contentValues = new ContentValues();
                    contentValues.put(FeedReaderContract.FeedEntry.COLUMN_NAME,curName);
                    contentValues.put(FeedReaderContract.FeedEntry.COLUMN_HEIGHT,curKneeHeight);
                    contentValues.put(FeedReaderContract.FeedEntry.COLUMN_AGE,curAge);
                    contentValues.put(FeedReaderContract.FeedEntry.COLUMN_HEIGHT,curHeight);
                    if(isMale){
                        contentValues.put(FeedReaderContract.FeedEntry.COLUMN_MALE,1);
                    }
                    else{
                        contentValues.put(FeedReaderContract.FeedEntry.COLUMN_MALE,0);
                    }
                    contentValues.put(FeedReaderContract.FeedEntry.COLUMN_WEIGHT,curWeight);
                    contentValues.put(FeedReaderContract.FeedEntry.COLUMN_MOVE,curMove);
                    id = db.insert(FeedReaderContract.FeedEntry.TABLE_NAME,null,contentValues);
                    Toast.makeText(MainActivity.this,"帳號新增成功:"+id,Toast.LENGTH_LONG).show();
                    UpdateList();
                    adapter = new CustomAdapter(dataset);
                    recycler_view.setAdapter(adapter);
                }
            }
        }
        else {
            Toast.makeText(MainActivity.this,"請輸入名字",Toast.LENGTH_LONG).show();
        }
    }

    public void LoadButtonOnClick(View view){
        String[] projection = {
                BaseColumns._ID,
                FeedReaderContract.FeedEntry.COLUMN_NAME,
                FeedReaderContract.FeedEntry.COLUMN_AGE,
                FeedReaderContract.FeedEntry.COLUMN_KNEEHEIGHT,
                FeedReaderContract.FeedEntry.COLUMN_HEIGHT,
                FeedReaderContract.FeedEntry.COLUMN_WEIGHT,
                FeedReaderContract.FeedEntry.COLUMN_MOVE,
                FeedReaderContract.FeedEntry.COLUMN_MALE
        };

        if(adapter.myCheckBox.size()>0){
            if(adapter.curChecked.size()==1){
                for(int i=0;i<adapter.myCheckBox.size();i++){
                    if(adapter.myCheckBox.get(i)){
                        String selection = FeedReaderContract.FeedEntry.COLUMN_NAME + " = ?";
                        String []selectionArgs = {adapter.localDataSet.get(i)};
                        Cursor cursor = db.query(
                                FeedReaderContract.FeedEntry.TABLE_NAME,   // The table to query
                                projection,             // The array of columns to return (pass null to get all)
                                selection,              // The columns for the WHERE clause
                                selectionArgs,          // The values for the WHERE clause
                                null,                   // don't group the rows
                                null,                   // don't filter by row groups
                                null//sortOrder               // The sort order
                        );
                        while(cursor.moveToNext()) {
                            curName = cursor.getString(cursor.getColumnIndexOrThrow(FeedReaderContract.FeedEntry.COLUMN_NAME));
                            curWeight = cursor.getDouble(cursor.getColumnIndexOrThrow(FeedReaderContract.FeedEntry.COLUMN_WEIGHT));
                            curHeight =cursor.getInt(cursor.getColumnIndexOrThrow(FeedReaderContract.FeedEntry.COLUMN_HEIGHT));
                            curMove = cursor.getInt(cursor.getColumnIndexOrThrow(FeedReaderContract.FeedEntry.COLUMN_MOVE));
                            curAge = cursor.getInt(cursor.getColumnIndexOrThrow(FeedReaderContract.FeedEntry.COLUMN_AGE));
                            curKneeHeight =cursor.getInt(cursor.getColumnIndexOrThrow(FeedReaderContract.FeedEntry.COLUMN_KNEEHEIGHT));
                            if(cursor.getInt(cursor.getColumnIndexOrThrow(FeedReaderContract.FeedEntry.COLUMN_MALE))==0){
                                isMale = false;
                                GenderButton.setText("女性");
                            }
                            else if(cursor.getInt(cursor.getColumnIndexOrThrow(FeedReaderContract.FeedEntry.COLUMN_MALE))==1){
                                isMale = true;
                                GenderButton.setText("男性");
                            }
                            Name.setText(curName);
                            Weight.setText(String.valueOf(curWeight));
                            Height.setText(String.valueOf(curHeight));
                            Move.setText(String.valueOf(curMove));
                            Age.setText(String.valueOf(curAge));
                            KneeHeight.setText(String.valueOf(curKneeHeight));
                        }
                    }
                }
            }
            else{
                Toast.makeText(MainActivity.this,"只能選取一個名字",Toast.LENGTH_LONG).show();
            }
        }

    }
    public void DeleteButtonOnClick(View view){
        //db = sqlDataBaseHelper.getWritableDatabase();

        if(adapter.myCheckBox.size()>0){
            if(adapter.curChecked.size()>0){
                for(int i=adapter.myCheckBox.size()-1;i>=0;i--){
                    if(adapter.myCheckBox.get(i)){
                        String selection =  FeedReaderContract.FeedEntry.COLUMN_NAME + " = ?";
                        String []selectionArgs = {adapter.localDataSet.get(i)};
                        db.delete(FeedReaderContract.FeedEntry.TABLE_NAME, selection, selectionArgs);
                        adapter.myCheckBox.remove(i);
                        Toast.makeText(MainActivity.this,"帳號刪除成功:"+String.valueOf(i),Toast.LENGTH_SHORT).show();
                    }
                }
                UpdateList();
                adapter = new CustomAdapter(dataset);
                recycler_view.setAdapter(adapter);
            }
            else{
                Toast.makeText(MainActivity.this,"請選取名字",Toast.LENGTH_LONG).show();
            }
        }
    }
    private boolean DataBaseisEmpty(){
        File file = this.getDatabasePath("BodyData.db");
        long dbSize = file.length();
        return dbSize>0?false:true;
    }
    private void UpdateList(){
        if(DataBaseisEmpty()){
           return;
        }
        //db = sqlDataBaseHelper.getWritableDatabase();
        // Define a projection that specifies which columns from the database
        // you will actually use after this query.

        // Filter results WHERE "title" = 'My Title'
        //String selection = FeedReaderContract.FeedEntry.COLUMN_NAME + " = ?";
        //String []selectionArgs = {"*"};
        String []Column_Args = {
                FeedReaderContract.FeedEntry.COLUMN_NAME
        };
        // How you want the results sorted in the resulting Cursor
        //String sortOrder = FeedReaderContract.FeedEntry.COLUMN_NAME_SUBTITLE + " DESC";
        Cursor cursor =  db.query(
                FeedReaderContract.FeedEntry.TABLE_NAME,   // The table to query
                Column_Args,             // The array of columns to return (pass null to get all)
                null,              // The columns for the WHERE clause
                null,          // The values for the WHERE clause
                null,                   // don't group the rows
                null,                   // don't filter by row groups
                null//sortOrder               // The sort order
        );

        dataset = new ArrayList<>();
        while(cursor.moveToNext()) {
            String NameStr = cursor.getString(cursor.getColumnIndexOrThrow(FeedReaderContract.FeedEntry.COLUMN_NAME));
            //long itemId = cursor.getLong(cursor.getColumnIndexOrThrow(FeedReaderContract.FeedEntry._ID));
            dataset.add(NameStr);
        }
        cursor.close();
    }

    private Bundle getMyBundle(){
        Bundle bundle = new Bundle();
        if(ValidateInput()){
            Compute();
            bundle.putString("curStandardWeight",String.valueOf(curStandardWeight));
            bundle.putString("curWeightRange", getWeightRange());
            bundle.putString("curCalories", String.valueOf(curCalories));
        }
        bundle.putInt("curHeight", curHeight);
        bundle.putDouble("curWeight",curWeight);
        bundle.putInt("curMove",curMove);
        bundle.putBoolean("calHeight",calHeight);
        bundle.putBoolean("isMale",isMale);
        bundle.putInt("curKneeHeight",curKneeHeight);
        bundle.putInt("curAge",curAge);
        return bundle;
    }

    private boolean ValidateInput(){
        if(!calHeight) {
            if (!Height.getText().toString().equals("")) {
                curHeight = Integer.parseInt(Height.getText().toString());
                System.out.println("curHeight");
                if (curHeight < 0) {
                    return false;
                }
            }
            else {
                return false;
            }
        }
        else{
            if(!KneeHeight.getText().toString().equals("")) {
                curKneeHeight = Integer.parseInt(KneeHeight.getText().toString());
                System.out.println("curKneeHeight");
                if(curKneeHeight<0){
                    return false;
                }
            }
            else{
                return false;
            }
            if(!Age.getText().toString().equals("")) {
                curAge = Integer.parseInt(Age.getText().toString());
                System.out.println("curAge");
                return curAge >= 0;
            }
            else{
                return false;
            }
        }
        String temp = Weight.getText().toString();
        if(!temp.equals("")) {
            curWeight = Double.parseDouble(temp);
            System.out.println("curWeight");
            int index = temp.indexOf(".");
            if(index > temp.length()-1){
                return false;
            }
            if(curWeight<0){
                return false;
            }
        }
        else{
            return false;
        }

        if(!Move.getText().toString().equals("")) {
            curMove = Integer.parseInt(Move.getText().toString());
            System.out.println("curMove");
            return curMove >= 1 && curMove <= 3;
        }
        else{
            return false;
        }
    }

    private void Compute(){
        if (calHeight) {
            if (isMale) {
                curHeight = (int)(85.1 + 1.73 * curKneeHeight - 0.11 * curAge);
            }
            else {
                curHeight = (int)(91.45 + 1.53 * curKneeHeight - 0.16 * curAge);
            }
        }

        if (isMale) {
            curStandardWeight =  (int)((curHeight - 80) * 0.7);
        }
        else {
            curStandardWeight =  (int)((curHeight - 70) * 0.6);
        }

        curWeightMax = curStandardWeight * 1.1;
        curWeightMin = curStandardWeight * 0.9;
        if (curMove == 1) {
            if (curWeight > curWeightMax) {
                curCalories = 25 * curStandardWeight;
            }
            else if (curWeight < curWeightMin) {
                curCalories = 35 * curStandardWeight;
            }
            else {
                curCalories = 30 * curStandardWeight;
            }
        }
        else if (curMove == 2) {
            if (curWeight > curWeightMax) {
                curCalories = 30 * curStandardWeight;
            }
            else if (curWeight < curWeightMin) {
                curCalories = 40 * curStandardWeight;
            }
            else {
                curCalories = 35 * curStandardWeight;
            }
        }
        else if (curMove == 3) {
            if (curWeight > curWeightMax) {
                curCalories = 35 * curStandardWeight;
            }
            else if (curWeight < curWeightMin) {
                curCalories = 35 * curStandardWeight;
            }
            else {
                curCalories = 40 * curStandardWeight;
            }
        }
        else {
            System.out.println(curMove);
            Log.d("Tag", "Invalid input Move");
        }

    }

    private String getWeightRange(){
        java.text.DecimalFormat myFormat=new java.text.DecimalFormat("0.0");
        String strMax = myFormat.format(curWeightMax);
        String strMin = myFormat.format(curWeightMin);
        return  strMin + "-" +  strMax;
    }
}