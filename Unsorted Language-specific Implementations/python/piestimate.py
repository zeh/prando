#python program to estimate value of pi using randomly distributed points
#radius of circle=1 unit
#sidelength of square=4 unit  
import matplotlib.pyplot as plt
import numpy as np
import random
t=np.arange(-1,1,0.01)
s=np.arange(-1,1,0.01)
#plot the graph of a circle 
plt.plot(t,(1-t**2)**0.5)
plt.plot(t,-((1-t**2)**0.5))
p=[]
q1=[]
q2=[]
r=[]
w1=[]
w2=[]
for i in range(100):
    p.append((random.randint(-200,200))/100)
    r.append((random.randint(-200,200))/100)
for j in range(100):
    if (p[j]**2+r[j]**2)>1 :
        q1.append(p[j])
        q2.append(r[j])
    else:
        w1.append(p[j])
        w2.append(r[j])
#estimate the value of pi
#area of the circle/area of the square=(pi*(2)**2/4*(2)**2)=(pi/16)
#points in square=100
#points in circle=len(w1)
pi=0
pi=4*(len(w1))/25
print(pi)
#plot randomly distributed points
#points inside circle have different colour than points outside
plt.scatter(q1,q2,color="red")
plt.scatter(w1,w2,color="blue")
