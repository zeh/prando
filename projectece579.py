import random
import math
rate=int(raw_input("Enter rate for the server side:"))
#add=0
rate1=int(raw_input("Enter rate for the client side:"))

delayone=[]
delaytwo=[]
for i in range(0,4):
        x=random.uniform(0,1)
        y=random.uniform(0,1)
        delayfloat= -math.log(1-x)*rate
        delayfloat2= -math.log(1-y)*rate1
        delay=round(delayfloat)
        delay2=round(delayfloat2)
        delayone.append(delay)
        #print delay_1
        delaytwo.append(delay2)
print delayone
print delaytwo

#def event1(MCL,delayone)


