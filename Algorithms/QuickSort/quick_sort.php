<?php
function quick_sort(Array $arrayToSort): Array
{
    // stop condition: only a single item left to sort
    if (count($arrayToSort) < 2) { return $arrayToSort; }

    $smaller = $bigger = array();
    $pivot_position = key($arrayToSort);
    $pivot_value = array_shift($arrayToSort);

    // sort into corresponding smaller and bigger sub-arrays
    foreach ($arrayToSort as $value) {
        if ($value <= $pivot_value) {
            $smaller[] = $value;
        } elseif ($value > $pivot_value) {
            $bigger[] = $value;
        }
    }
    // recursive magic
    return array_merge(quick_sort($smaller), array($pivot_position => $pivot_value), quick_sort($bigger));
}