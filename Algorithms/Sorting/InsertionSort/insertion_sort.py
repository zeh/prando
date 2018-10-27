def insertion_sort(array):
    for i in range(1,len(array)):
        j = i
        while j > 0:
            if int(array[j]) < int(array[j-1]):
                array[j],array[j-1] = array[j-1],array[j]
            j -= 1

def array_to_string(array):
    string = ""
    for i in array:
        string += i + " "
        
    return string.strip()

string = raw_input("Enter your array as a String, separating the numbers by spaces:\n> ")
array = string.split()
insertion_sort(array)
result = array_to_string(array)

print("\nSorted:\n> %s" % result)
