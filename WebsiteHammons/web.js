"use strict";
function check(i) 
{  
  if (i < 10) {i = "0" + i};  // add zero in front of numbers < 10
  return i;
}

function getTime()
{
  var d = new Date();
  var day = d.getUTCDate();
  var month = d.getMonth() + 1;
  var year = d.getFullYear();
  var hours = d.getHours();
  var min = d.getMinutes();
  var sec = d.getSeconds();
  var ampm = "AM";
  
  if(hours == 0)
  {
      hours = 12;
  }
  if(hours > 12)
  {
      hours = hours - 12;
      ampm = "PM";
  }
    
  hours = check(hours);    
  min = check(min);
  sec = check(sec);
    
  document.getElementById("datetime").innerHTML = month + "/" + day + "/" + year + " <br> " + hours + ":" + min + ":" + sec + ampm;
  document.getElementById("datetime").style.textAlign = "left";    
    
  setTimeout(getTime, 500);
}














