#!/usr/bin/python3

array = [1, 1, 3, 5, 6, 9, 7, 2, 8, 2, 5, 2, 7, 3, 6]
fbig = sbig = array[0]

for v in array[1:]:
    if v > fbig:
        sbig = fbig
        fbig = v
    else: 
        if v > sbig:
            sbig = v

print(sbig)
