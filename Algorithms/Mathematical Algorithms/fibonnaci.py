#!/usr/bin/python3

"""
Python functions to calculate Fibonacci series
"""


def fibonacciAtIndex(index):
	"""
	Returns the fibonacci number at a given index.
	Algorithm is using 3 variables instead of recursion in order to reduce memory usage and runtime
	"""
	a1, a2 = 1,1
	position = 3
	# while position <= index:
	while index > 2:
		temp = a1
		a1 = a2
		a2 += temp
		# position += 1
		index -= 1
	return a2


def fibonacciUntilIndex(index):
	"""
	Prints the fibonacci series up until a given index (included).
	Algorithm is using 3 variables instead of recursion in order to reduce memory usage and runtime
	"""
	if index < 1:
		raise ValueError
	a1 = 0
	a2 = 1
	position = 1
	while position <= index:
		temp = a1
		a1 = a2
		a2 += temp
		print("Fibonacci number at index {} = {}".format(position, a1))
		position += 1
