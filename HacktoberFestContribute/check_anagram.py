#!/usr/bin/env python

#Given two strings, determine if they are anagrams of each other
# test procedure
# make each string lowercase
# for each string, itemize the total occurrences of each character
# compare the data

def compute_char_counts(s):
	char_counts = {}
	for char in s.lower():
		
		# ignore non alphabet chars
		if char not in 'abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUFWXYZ':
			continue
			
		if not char in char_counts:
			char_counts[char] = 0
		char_counts[char] += 1
	return char_counts
	
#returns only True or False
def check_anagram(a, b):
	print ('Checking for Anagram')
	print ('Comparing "%s" to "%s"' % (a, b))
	
	# compute the count of each occurrence of each character
	char_counts_1 = compute_char_counts(a)
	char_counts_2 = compute_char_counts(b)

	for char in char_counts_1:
		if not char in char_counts_2:
			print('Not an anagram... %s is not shared.' % char)
			return False
			
		if char_counts_1[char] != char_counts_2[char]:
			print('Not an anagram... %s is not shared equally.' % char)
			return False
	
	return True


# tests
if __name__ == '__main__':
	possible_pairs = [
		("Damon Albarn" , "Dan Abnormal"),
		("Dave Barry" , "Ray Adverb"),
		("Arrigo Boito" , "Tobia Gorrio"),
		("Buckethead" , "Death Cube K"),
		("Daniel Clowes" , "Enid Coleslaw"),
		("William Shakespeare","I am a weakish speller"),
		("Anagrams","pseudonyms"),
		("aaaa", "aaaaa"),
		("aaaab", "aaaaa"),
		("aaaaa", "aaaab"),
	]
	
	for pair in possible_pairs:
		print(check_anagram(pair[0], pair[1]))
