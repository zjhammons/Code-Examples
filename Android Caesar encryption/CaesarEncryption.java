package com.example.zjhammons.project2;


import android.content.Context;
import android.content.SharedPreferences;
import android.preference.PreferenceManager;



public class CaesarEncryption extends MainActivity {
    String message;
    int shiftNumber;
    private static final String PREFERENCE_SHIFT = "shift";


    public CaesarEncryption(String message, int shiftNumber) {
        this.message = message;
        this.shiftNumber = shiftNumber;
        setShiftNumber(shiftNumber);
    }

    public CaesarEncryption( Context context ) {
        SharedPreferences pref = PreferenceManager.getDefaultSharedPreferences( context );
        setShiftNumber( pref.getInt( PREFERENCE_SHIFT, -1));

    }

    public void setShiftNumber( int shiftNumber ) {

            this.shiftNumber = shiftNumber;
    }


    //This method encypts the message without changing spaces, If you comment out the first if
    //statement it will change spaces.
    public String encrypt()
    {
        //set string to char array and go through each char
        char space = ' ';
        char[] c = message.toCharArray();

        for (int i = 0; i < c.length; i++)
        {
            char letter = c[i];
            //If char is a space, do not change it... Comment out if spaces need to be encrypted
            if (letter == space)
            {
                letter = space;
            }
            else
            {
                //Change letters according to their ASCII Valyes
                letter = (char) (letter + shiftNumber);
                if (letter > 'z')
                {
                    letter = (char) (letter - 26);
                }
                else if (letter < 'a')
                {
                    letter = (char) (letter + 26);
                }
            }
          //Create new char array of encypted message
          c[i] = letter;
        }
       //Return a new String of char array c
       return new String(c);
    }

    public void setPreferences( Context context ) {
        // get a SharedPreferences.Editor reference
        SharedPreferences pref = PreferenceManager.getDefaultSharedPreferences( context );
        SharedPreferences.Editor editor = pref.edit( );
        // write mortgage data to user preferences
        editor.putInt( PREFERENCE_SHIFT, shiftNumber );
        editor.commit( );
    }
}


















