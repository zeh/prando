#!/usr/bin/python3

"""
Python function that returns the indexes of the 2 biggest numbers in an array.
The function only swipes across the array once, for better runtime {O(n)}

Important: Please remember that arrays in python starts from index 0
"""


def maxPairSum(arr):
	biggest_num_index = second_biggest_index = 1
	for index, value in enumerate(arr):
		if value > arr[biggest_num_index]:
			second_biggest_index = biggest_num_index
			biggest_num_index = index
		elif value > arr[second_biggest_index]:
			second_biggest_index = index
	return biggest_num_index, second_biggest_index	


def main():
	arr = [1,2,4,8,16,32,64,128,256,512,1024,2048,4096,3,27,9,81,243,729,8,7]
	index1, index2 = maxPairSum(arr)

	print("The maximal sum of the array is recieved by adding the items at indexes {} and {}.".format(index1, index2))
	print("The sum is", arr[index1] + arr[index2])


if __name__ == '__main__':
	main()
