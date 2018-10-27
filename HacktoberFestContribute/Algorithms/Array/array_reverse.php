/*
*Program to Print reverser of array without array_reverse function
*/


<?php
  $array = array(1, 2, 3, 4);
  $size = sizeof($array);

  for($i=$size-1; $i>=0; $i--){
      echo $array[$i];
  }
?>
