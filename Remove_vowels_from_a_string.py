##Code to remove vowels from a string##

#User Input
test_string = input("Enter a String : ")

#Create a dictionary of vowels
vowels = str.maketrans(dict.fromkeys('aeiouAEIOU'))

#Remove vowels from the string
new_string = test_string.translate(vowels)

#Print new string without vowels
print(new_string)
