package com.example.zjhammons.project2;


import android.content.Intent;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
//import android.util.Log;
import android.view.View;
import android.widget.EditText;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {
    public static CaesarEncryption caesarEncryption;
    //store the int entered
    public int userNumber;

    @Override
    protected void onCreate(Bundle savedInstanceState)
    {
        super.onCreate(savedInstanceState);
        caesarEncryption = new CaesarEncryption(this);
        setContentView(R.layout.activity_main);
    }

    public void onStart( )
    {
        super.onStart();
        //Log.w( "MainActivity", "MainActivity onStart called" );

    }

    public void modifyData(  )
    {
        //Log.w( "MainActivity", "Inside modifyData" );
        // Go to DataActivity screen
        Intent intent = new Intent(this, DataActivity.class);
        intent.putExtra("userInt", userNumber);
        startActivity(intent);
        overridePendingTransition(R.anim.bounce, 0);
    }

    public void updateView(View v)
    {

        //Log.w("MainActivity", "inside updateView");
       //Get view

        //TRY AND SET AMOUNT IN CASEAR CLASS AND COMPARE THERE AND JUST SET TEXT HERE
       EditText num = (EditText) findViewById(R.id.userInt);
       String userNum = num.getText().toString();
         userNumber = Integer.parseInt(userNum);

        if (userNumber >= 1 && userNumber <= 25)
        {
            //Retrieve/Set error message to invisible, call modifyData
            TextView message = (TextView) findViewById(R.id.intLabel);
            message.setVisibility(View.INVISIBLE);
            modifyData();

        }
        else
        {
            //Retrieve/Set error message to visible, try again.
            TextView message = (TextView) findViewById(R.id.intLabel);
            message.setVisibility(View.VISIBLE);
        }
    }
}