package com.example.zjhammons.project2;

import android.content.Intent;
import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.util.Log;
import android.view.View;
import android.widget.EditText;
import android.widget.TextView;

public class DataActivity extends AppCompatActivity {

    int shiftNumber;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_data);
    }

    public void getUserNumber(View v)
    {
        CaesarEncryption caesarEncryption = MainActivity.caesarEncryption;
        //Retrieve the int stored in the previous screen
        Intent intent = getIntent();
         shiftNumber = intent.getIntExtra("userInt", -1);
        //Log.w("DataActivity", "Shift number is " + shiftNumber);

        //Retrieve userText and cast to a String
        EditText input = (EditText) findViewById(R.id.userText);
        String userText = input.getText().toString();
        //Log.w("DataActivity", "Usertext is " + userText);

        //Call CaesarEncryption class with userText and the retrieved int passed
        CaesarEncryption ciph = new CaesarEncryption(userText,shiftNumber);
        String encryptedText = ciph.encrypt();
        //Retrieve and update encryptedText label
        TextView updateLabel = (TextView) findViewById(R.id.encryptedText);
        updateLabel.setText(encryptedText);

        /*caesarEncryption.setShiftNumber(shiftNumber);
        caesarEncryption.setPreferences(this);*/


    }

    //Go back to first screen
    public void goBack( View v ) {
        CaesarEncryption caesarEncryption = MainActivity.caesarEncryption;
        caesarEncryption.setShiftNumber(shiftNumber);
        caesarEncryption.setPreferences(this);
        finish( );
        overridePendingTransition( R.anim.rotate, 0 );
    }

}
