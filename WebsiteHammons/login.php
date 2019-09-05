<?php
// database info
$servername = "cs-database.cs.loyola.edu";
$username = "zjhammons";
$password = "password"; 

// get form data
$username = $_POST['username'];
$password = $_POST['password'];


// create connection
$mysqli = new mysqli($servername, $username, $password);

//check connection
if( $mysqli->connect_error)
    die('Could not connect' . $mysqli->connect_error);

// succesful connection
$sql = "SELECT 'password' FROM UserLogin WHERE username = $username";

$result = $mysqli->real_query($sql);
if( $result === TRUE)
{
   echo "Hi " . $username . ". You have succesfully created an account!";
}
else
{
    echo "Error, account not created. " . $mysqli->error; 
}
?>

