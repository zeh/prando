#!/usr/bin/python3

def trim_extra_spaces(s: str) -> str:
	return ' '.join(s.split())

# For python2 users, please uncomment and use the function provided below
# def trim_extra_spaces(s):
	# return ' '.join(s.split())

s1 = 'My   name is    Diptangsu         Goswami'
s1_trimmed = trim_extra_spaces(s1)
print(s1_trimmed)