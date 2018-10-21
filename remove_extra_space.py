# Python program to remove extra spaces in string
# Author - Ramya Easwaran

import re
text = 'hacktober fest   contribute'
print("Without extra spaces:",re.sub(' +',' ',text))
