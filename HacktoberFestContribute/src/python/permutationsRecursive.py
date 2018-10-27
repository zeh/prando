import sys

#Recursive solution to find all the permutations of a string

def perm(mem, chars):
    if len(chars) == 0:
        print(mem)
        return

    for i in range(0, len(chars)):
        copy = list(chars)
        prefix = mem + copy[i]
        copy.pop(i)
        perm(prefix, copy)


#print(list(sys.argv[1]))
perm("", list(sys.argv[1]))
