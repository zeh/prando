#python program to find whether one input is the substring of the other(without using in-built functions)
string=input("enter the string:")
substring=input("enter the substring:")
for i in range(len(string)):
    if string[i:i+len(substring)]==substring :
        count=1
if count==1:
    print("It is a substring")
else:
    print("It is not a substring")
