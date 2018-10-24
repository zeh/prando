<?php

function findFirstNonRepeatingCharacter($inputString)
{
    $stringParts = str_split($inputString);

    foreach ($stringParts as $index => $part) {
        $foundMatches = array_filter($stringParts, function ($element) use ($part) {
            return $element === $part;
        });

        if (count($foundMatches) === 1) {
            return $part;
        }
    }
}

