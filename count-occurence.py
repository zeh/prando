def count_occurence(list, key):
    count = 0
    for item in list:
        if item == key:
            count = count + 1
    return count

my_list = [8, 88, -6, 21, 10, 36, 12, 88, 0, 88]
sorted_list = sorted(my_list)
number_of_occurences = count_occurence(sorted_list, 88)
print("88 occurs in " + str(sorted_list) + ": " + str(number_of_occurences) + " times")