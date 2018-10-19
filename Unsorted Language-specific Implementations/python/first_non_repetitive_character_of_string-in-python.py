def firstNonRepeat(s):
        counter = {}

        for char in s:
            if char in counter:
                counter[char] += 1
            else:
                counter[char] =  1

        for char in s:
            if counter[char] == 1:
                print (char)
                return

    firstNonRepeat('aabccbdcbe')
