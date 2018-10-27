import random 
res = []
def Rand(start, end, num):
    for j in range(num): 
        res.append(random.uniform(start, end))
    return res 
 
num = 400
start = 0
end = 1
print "the random values generated for n=400"
print(Rand(start, end, num))
r=0
num=float(100)
#r=[2,1,1,2,3,1,5,6,1,5,6,7,8,2,3,4,5,1]
reg=1
c1=0
list=[]
for i in xrange(len(res)):
    if (i+1)>(len(res)-1):
        list.append(reg)
        break
    if res[i]<res[i+1]:
        reg+=1
        continue
    list.append(reg) 
    reg=1
print"\nThe run up"
print list
c1=0
c2=0
c3=0
c4=0
c5=0
c6=0
c=[]
var = 100
for i in list:
    if i == 1:
        c1+=1
    elif i==2:
        c2+=1
    elif i == 3:
        c3+=1
    elif i == 4:
        c4+=1
    elif i == 5:
        c5+=1
    else:
        c6+=1
c.append(c1)
c.append(c2)
c.append(c3)
c.append(c4)
c.append(c5)
c.append(c6)
print"\n"
print "the list containing ri,rj values from 1 to 6"
print c 
from numpy import * 
a = array([[4529.4,9044.9,13568,18091,22615,27892],[9044.9,18097,27139,36187,45234,55789],[13568,27139,40721,54281,67852,83685],[18091,36187,54281,72414,90470,111580],[22615,45234,67852,90470,113262,139476],[27892,55789,83685,111580,139476 ,172860]])
m = reshape(a,(6,6))
print"\n"
print " the matrix containing the aij values"
print m

b1=float(1.0/6)
b2=float(5.0/24)
b3=float(11.0/120)
b4=float(19.0/720)
b5=float(29.0/5040)
b6=float(1.0/840)
b=[]
b.append(b1)
b.append(b2)
b.append(b3)
b.append(b4)
b.append(b5)
b.append(b6)
print"\n"
print "The values of bi,bj in range from 1 to 6"
print b
R=0
print "\n"
print num
for i in range(6):
    for j in range(6):
        R+=(c[i]-num*b[i])*((c[j]-num*b[j])*a[i][j])
R=float(R/num)
print "\nThe value of R"
print R

