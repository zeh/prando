array = [12, 30, 733, 1, 2754, 6]

print("Array: ")
print(array)
array.sort()

print("Sorted array: ")
print(array)

array_length = len(array)

first_element = array[array_length-2]
second_element = array[array_length-1]
sum_of_two_largest_elements_in_array = first_element + second_element
print("Second largest element: " + str(first_element))
print("Largest element: " + str(second_element))
print("Sum: " + str(sum_of_two_largest_elements_in_array))
