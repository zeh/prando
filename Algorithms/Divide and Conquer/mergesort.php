<?php
/*
 * @Author: Sushma Kure
 * @ProblemStatement: Merge Sort in PHP using divide and conquer algorithm
 * @AboutCode: MergeSort is best example of a divide-and-conquer algorithm. 
 * The algorithm divides the array in two halves, recursively sorts them and 
 * finally merges the two sorted halves.
 *
 */

function merge_sort( $sourceArr ){
	if( count( $sourceArr ) == 1 ) {
		return $sourceArr;
	}

	$mid = count( $sourceArr ) / 2;
    $left = array_slice( $sourceArr, 0, $mid );
    $right = array_slice( $sourceArr, $mid );
	$left = merge_sort( $left );
	$right = merge_sort( $right );

	return merge_function( $left, $right );
}

function merge_function( $left, $right ) {
	$res = array();
	while ( count( $left ) > 0 && count( $right ) > 0 ) {
		if( $left[0] > $right[0] ) {
			$res[] = $right[0];
			$right = array_slice( $right , 1 );
		} else {
			$res[] = $left[0];
			$left = array_slice( $left, 1 );
		}
	}
	while ( count( $left ) > 0 ) {
		$res[] = $left[0];
		$left = array_slice( $left, 1 );
	}
	while ( count( $right ) > 0 ) {
		$res[] = $right[0];
		$right = array_slice( $right, 1 );
	}
	return $res;
}
$sourceArr = array( 100, 9, 207, 2, 8, 4, 1 );
echo "Original Array : ";
echo implode( ', ', $sourceArr );
echo "</br>";
echo "Sorted Array :";
echo implode( ', ', merge_sort( $sourceArr ) ) . "</br>";
?>
