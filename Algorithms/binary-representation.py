# run with python 3

def binary_representation(number):
    if number > 1:
        binary_representation(number//2)
    print(number%2, end="")

binary_representation(4)
print()
binary_representation(7)
print()