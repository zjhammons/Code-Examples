function countdownTimer()
{
    // Add five days to current date and time, then set duration in milliseconds 
    var addDaysToDate = new Date();
    addDaysToDate.setDate(addDaysToDate.getDate() + 5);
    var duration = addDaysToDate.getTime();

 // count down every second
 var x = setInterval(function() {

  // Todays date and time in milliseconds 
    var now = new Date().getTime();
  // span between dates
    var span = duration - now;

    var days = Math.floor(span / (1000 * 60 * 60 * 24));
    var hours = Math.floor((span % (1000 * 60 * 60 * 24)) / (1000 * 60 * 60));
    var minutes = Math.floor((span % (1000 * 60 * 60)) / (1000 * 60));
    var seconds = Math.floor((span % (1000 * 60)) / 1000);

  // Display result in timer tag
  document.getElementById("timer").innerHTML = days + "D " + hours + "H " 
  + minutes + "M " + seconds + "S ";

  // If finished close registration, disable buttons
  if (span < 0) {
    clearInterval(x);
    document.getElementById("timer").innerHTML = "Registration period has ended!";
    var y = document.getElementById("registerbutton").disabled = true;
    var z = document.getElementById("reservebutton").disabled = true;
  }
 }, 1000);
}

// sync up bottom checkbox with top
function syncBottomBox(){
    var box = document.getElementById("topcheckbox").checked;
        if(box == true)
            {
                document.getElementById("bottomcheckbox").checked = true;
            }
        else{
                document.getElementById("bottomcheckbox").checked = false;
        }
    }

// sync up top checkbox with bottom
function syncTopBox(){
    var box = document.getElementById("bottomcheckbox").checked;
        if(box == true)
            {
                document.getElementById("topcheckbox").checked = true;
            }
        else{
                document.getElementById("topcheckbox").checked = false;
        }  
    }

// Register for seminar 
function register()
{
    var topbox = document.getElementById("topcheckbox").checked;
    var bottombox = document.getElementById("bottomcheckbox").checked;
    if(topbox == false || bottombox == false)
        {
            alert("Please check the checkbox before preceeding!");
        }
    else{
        var request = new XMLHttpRequest();
        request.open("GET", "https://bl45immth4.execute-api.us-east-1.amazonaws.com/production/");
        request.onload = function(){
            var data = JSON.parse(this.response);
            if(request.status >= 200 && request.status < 400)
                {
                // I think below is how to parse the nested submitok of the body element in the JSON call...
                // it comes back as undefined because the body is being parsed as a string.
                   // document.getElementById("responsetop").innerHTML = data.body.submitok;
                   // document.getElementById("responsebottom").innerHTML = data.statusCode;

                // parse status
                   // document.getElementById("responsetop").innerHTML = data.statusCode;
                   // document.getElementById("responsebottom").innerHTML = data.statusCode;

                //parse body
                    document.getElementById("responsetop").innerHTML = data.body;
                    document.getElementById("responsebottom").innerHTML = data.body;                
                }
            else{ console.log("ERROR");}  
            }
        request.send();
      }
}