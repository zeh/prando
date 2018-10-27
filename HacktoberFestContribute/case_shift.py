def case_shift(s):
  
  swapped = ""
  
  for c in s:
    if c.islower():
      swapped = swapped + c.upper()      
    elif c.isupper():
      swapped = swapped + c.lower()

  return swapped 

print(case_shift("HacktoberFestContribute"))
