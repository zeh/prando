<?php
/*
 * @Author: Sushma Kure
 * @ProblemStatement: Program for Fibonacci numbers in PHP.
 * It gives a series of numbers in which each number ( Fibonacci number ) is the sum of the two preceding 
 * numbers. The simplest is the series 1, 1, 2, 3, 5, 8, etc.
 *
 */

function fibonacci( $number ){ 
      
    // if and else if to generate first two numbers 
    if ( $number == 0 ) {
        return 0;     
    } else if ( $number == 1 ) {
    	return 1;     
    } else {
        return ( fibonacci( $number-1 ) + fibonacci( $number-2 ) ); 
    }
   
} 
  
// Test case for first 10 numbers
$number = 10; 
for ( $counter = 0; $counter < $number; $counter++ ){   
	echo fibonacci( $counter ) . ' '; 
} 
?> 