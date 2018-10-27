import random
import math
rate=int(raw_input("Enter rate at the server end:"))
rate1=int(raw_input("Enter rate at the client end:"))

add=0
#for i in range(0,30):
x= random.uniform(0, 1)
print x
delayfloat = -math.log(1-x)*rate
delay=round(delayfloat)
delayfloat1= -math.log(1-x)*rate1
delay1=round(delayfloat1)
print delay
print delay1

