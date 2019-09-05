//Calculate bill and tip
function calculateTip() {
    "use strict";
   // get values from form
   var amnt = document.getElementById("amount").value;
   var tipamnt = document.getElementById("tipselect").value;
   var numpeople = document.getElementById("numpeople").value;
   
   // check for valid and complete input
   if (amnt === "" || tipamnt == 0 || numpeople === "" || numpeople == 0)
       {
           alert("Please fill in all values!");
           return;
       }
    
   // remove per person/each if only one    
   if (numpeople == 1)
       {
           document.getElementById("perperson").style.display = "none";
           document.getElementById("billperperson").style.display = "none";

       }
   else 
       {
           document.getElementById("perperson").style.display = "block";
           document.getElementById("billperperson").style.display = "block";
       }
    
    // display tip and bill amounts
    document.getElementById("totals").style.display = "block";
    
    // calculate tip per person
    var tipsplit = (amnt * tipamnt) / numpeople;
    tipsplit = Math.round( tipsplit * 100 ) / 100;
    tipsplit = tipsplit.toFixed(2);
    document.getElementById("tipamount").innerHTML = tipsplit;

    // calculate bill per person
    var billsplit = (+amnt * +tipamnt + +amnt) / +numpeople;
    billsplit = Math.round( billsplit * 100 ) / 100;
    billsplit = billsplit.toFixed(2);
    document.getElementById("billamount").innerHTML = billsplit;
}

// hide tip and bill amounts and call calculate function
document.getElementById("totals").style.display = "none";
document.getElementById("calculate").onclick= function() { calculateTip(); };