#!/usr/bin/python3

"""
Python function to test if a given number is a power of two
"""

import sys
from os.path import basename

def main():
	if len(sys.argv) > 1:
		for arg in sys.argv[1:]:
			try:
				x = int(arg)
				is_pwr = 'a' if (x > 0 and (x & (x-1)) == 0) else 'not a'
				print("{} is {} power of two.".format(arg, is_pwr))
			except:
				print("Error: {} is not an integer!".format(arg))
	else:
		print("Usage: {} <number> [additional numbers]".format(basename(sys.argv[0])))

if __name__ == '__main__':
	main()
