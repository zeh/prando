import random
import math
rate=int(raw_input("Enter rate:"))
add=0
for i in range(0,30):
	
	x= random.uniform(0, 1)
	print x
	delayfloat =  -math.log(1-x)*rate
	print round(delayfloat)
	add=round(add+round(delayfloat))
print add/30
