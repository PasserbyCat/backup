package com.example.hw3;

import android.provider.BaseColumns;

public class FeedReaderContract {
    // To prevent someone from accidentally instantiating the contract class,
    // make the constructor private.
    private FeedReaderContract() {}

    /* Inner class that defines the table contents */
    public static class FeedEntry implements BaseColumns {
        public static final String TABLE_NAME = "BodyData";
        public static final String COLUMN_NAME = "Name";
        public static final String COLUMN_KNEEHEIGHT = "KneeHeight";
        public static final String COLUMN_AGE = "Age";
        public static final String COLUMN_HEIGHT = "Height";
        public static final String COLUMN_MALE = "Male";
        public static final String COLUMN_WEIGHT = "Weight";
        public static final String COLUMN_MOVE = "Move";
    }
}
