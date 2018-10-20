import re

str = input()
regex = r'[aeiouyAEIOUY]{2,}'
result = re.sub(regex,'',str)

print(result)
