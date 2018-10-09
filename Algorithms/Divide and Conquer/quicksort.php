<?php
/*
 * @Author: Sushma Kure
 * @ProblemStatement: Quick Sort in PHP using divide and conquer algorithm
 * @Algorithm: The algorithm picks a pivot element, rearranges the array elements in such a way that all 
 * elements smaller than the picked pivot element move to left side of pivot, and all greater elements 
 * move to right side. Finally, the algorithm recursively sorts the subarrays on left and right of pivot 
 * element.
 *
 */

function quick_sort( $sourceArr )
 {
	$lower = $greater = array();
	if( count( $sourceArr ) < 2)
	{
		return  $sourceArr ;
	}
	$pivot_key = key( $sourceArr );
	$pivot = array_shift( $sourceArr );
	foreach( $sourceArr as $val )
	{
		if( $val <= $pivot )
		{
			$lower[] = $val;
		}elseif ( $val > $pivot )
		{
			$greater[] = $val;
		}
	}
	return array_merge( quick_sort( $lower ), array( $pivot_key=>$pivot ), quick_sort( $greater ) );
}
 
$sourceArr  = array( 100, 9, 207, 2, 8, 4, 1 );
echo "Original Array : ";
echo implode( ',', $sourceArr );
echo "</br>";
echo "Sorted Array : ";
echo implode( ',', quick_sort( $sourceArr ) ) . "</br>";
?>


