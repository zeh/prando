#!/usr/bin/env python3

#Count the number of times the element needle occurs in sorted array haystack
def sorted_array_count(needle, haystack):
    count = 0
    found_first_element = False
    for element in haystack:
        if element != needle:
            if found_first_element:
                return count
            else:
                continue
        count += 1
    return count



test_array = [1,1,1,2,2,3]

print(sorted_array_count(1, test_array))
print(sorted_array_count(2, test_array))
print(sorted_array_count(3, test_array))
