function validateForm( event ) 
{
  var form = event.target;
    
  if( form.user.value.length == 0 )
  {
     var userdiv = document.getElementById( "usermsg" );
     userdiv.innerHTML = "Mandatory field. Enter a username"; // could style in red
     event.preventDefault();
  }
  else if ( form.pwd1.value != form.pwd.value || form.pwd.value.length == 0 || form.pwd1.value.length == 0 )
  {
     var pwddiv = document.getElementById( "pwdmsg" );
     pwddiv.innerHTML = "Mandatory field. Enter a password"; // could style in red
     event.preventDefault();
  }
  else if( form.zip.value.length != 5 )
  {      
     var zipdiv = document.getElementById( "zipmsg" );
     zipdiv.innerHTML = "Mandatory field. Enter a 5 digit zip code"; // could style in red
     event.preventDefault();
  }
  else
  {
   userdiv.innerHTML = "";
   pwddiv.innerHTML = " ";      
   zipdiv.innerHTML = "";
  }    
}

var password = document.getElementById("pwd");

password.addEventListener("keyup", function(){
    var checkNum = /[0-9]/; 
    
    if( password.value.length < 8 || (!checkNum.test(password.value)) )
    {
        document.getElementById("image").style.display = "block";
        document.getElementById("image").src = "redX.png";
    }
    
    else
    {
        document.getElementById("image").src = "greencheck.png";

    }
})
                         
                         
document.getElementById("image").style.display = "none";