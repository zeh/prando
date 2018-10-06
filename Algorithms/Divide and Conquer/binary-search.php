<?php
/*
 * @Author: Vrunda Kansara 
 * @Website: http://iamvrunda.com 
 * @ProblemStatement: Binary search in PHP using divide and conquer algorithm
 * @AboutCode: As the algorithm divide and conquer is also applied to algorithms that 
 * reduce each problem to only one sub-problem, the binary search algorithm is 
 * considered as divide and conquer algorithm.
 *
 * In binary search the search space is reduced in each step where the sub-problem is 
 * of roughly half the original size. The binary search is also called decrease and 
 * conquer algorithm as search space is reduced in each step. In binary search the 
 * sub-problem can be solved using iterative or recursive approaches. Following is the 
 * iterative approach for solving binary search in PHP
 */
function binarySearch($sourceArr, $keyword)
{
  $start  = 0;
  $end    = count($sourceArr) - 1;
  while ($start <= $end)
  {
    $middle = ($start + $end) / 2;
    if($keyword == $sourceArr[$middle]) {
      return $middle;
    }
    elseif($keyword < $sourceArr[$middle]) {
      $end = $middle - 1;
    }
    else{
      $start = $middle + 1;
    }
  }
  return -1;
}

$sourceArr = range(1, 100, 7);
$keyword   = $sourceArr[array_rand($sourceArr)];  
$position  = binarySearch($sourceArr, $keyword);
echo '<xmp><pre>'; print_r($sourceArr); echo '</pre></xmp>';
echo ($position >= 0) ? 'Keyword ' . $keyword . ' is found at position: ' . $position :  'Your keyword is not found.';