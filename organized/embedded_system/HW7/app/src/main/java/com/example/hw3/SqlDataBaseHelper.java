package com.example.hw3;

import android.content.Context;
import android.database.sqlite.SQLiteDatabase;
import android.database.sqlite.SQLiteOpenHelper;
import android.util.Log;
import android.widget.Toast;

import androidx.annotation.Nullable;

public class SqlDataBaseHelper extends SQLiteOpenHelper {

    private static final String DataBaseName = "BodyData.db";
    private static final int DataBaseVersion = 1;
    private static final String SQL_CREATE_ENTRIES =
                    "CREATE TABLE IF NOT EXISTS "+FeedReaderContract.FeedEntry.TABLE_NAME+" (" +
                    FeedReaderContract.FeedEntry._ID +" INTEGER PRIMARY KEY AUTOINCREMENT," +
                    FeedReaderContract.FeedEntry.COLUMN_NAME+" TEXT," +
                    FeedReaderContract.FeedEntry.COLUMN_AGE +" INTEGER," +
                    FeedReaderContract.FeedEntry.COLUMN_HEIGHT+ " INTEGER," +
                    FeedReaderContract.FeedEntry.COLUMN_KNEEHEIGHT+" INTEGER," +
                    FeedReaderContract.FeedEntry.COLUMN_MALE+" BOOLEAN," +
                    FeedReaderContract.FeedEntry.COLUMN_WEIGHT+" INTEGER," +
                    FeedReaderContract.FeedEntry.COLUMN_MOVE+" INTEGER" +
                    ")";
    private static final String SQL_DELETE_ENTRIES =
            "DROP TABLE IF EXISTS " + FeedReaderContract.FeedEntry.TABLE_NAME;
    public SqlDataBaseHelper(Context context) {
        super(context, DataBaseName, null, DataBaseVersion);
    }

    @Override
    public void onCreate(SQLiteDatabase sqLiteDatabase) {
        Log.d("MainActivity", "Creating");
        sqLiteDatabase.execSQL(SQL_CREATE_ENTRIES);
        Log.d("Tag", "Created");
    }

    @Override
    public void onUpgrade(SQLiteDatabase sqLiteDatabase, int i, int i1) {
        sqLiteDatabase.execSQL(SQL_DELETE_ENTRIES);
        onCreate(sqLiteDatabase);
    }
}