<?php
/*
 * @Author: Vrunda Kansara 
 * @Website: http://iamvrunda.com 
 * @ProblemStatement: PHP code to get the factorial of a number.
 */
function vk_factorial($number){ 
    $factorial = 1; 
    for ($i = 1; $i <= $number; $i++){ 
      $factorial = $factorial * $i; 
    } 
    return $factorial; 
} 
  
// Test Cases
echo vk_factorial(10);
echo vk_factorial(2); 
echo vk_factorial(5); 
?> 