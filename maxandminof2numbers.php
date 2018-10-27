<?php 
// PHP program to Compute the minimum 
// or maximum of two integers without  
// branching 
  
// Function to find minimum 
// of x and y 
function m_in($x, $y) 
{ 
    return $y ^ (($x ^ $y) &  
               - ($x < $y)); 
} 
  
// Function to find maximum  
// of x and y 
function m_ax($x, $y) 
{ 
    return $x ^ (($x ^ $y) &  
              - ($x < $y));  
} 
  
// Driver Code 
$x = 15; 
$y = 6; 
echo"Minimum of"," ", $x," ","and",  
    " ",$y," "," is "," "; 
      
echo m_in($x, $y); 
  
echo "\nMaximum of"," ",$x," ", 
     "and"," ",$y," ", " is "; 
       
echo m_ax($x, $y); 
  
 
?> 