import random 
res1 = []
def Rand(start, end, num):
    for j in range(num): 
        res1.append(random.uniform(start, end))
        
    return res1

# Driver Code 
num = 400

start = 0
end = 1
print "the random values generated for n=400"
print(Rand(start, end, num))
r=0
print "\nthe sorted random values for n=400"
res1.sort()
res=(res1)
print res

#num=float(100)
print "\n let the value of intervals be 150"
print " Each interval:"
c=float(1.0/150)

print c
c1=0
print "\n the range for fi"
g=[]
for i in range(150):
    c1+=c
    g.append(c1)
print g


f=[]
print "\n fi be the pseudo random number that fall within that ith subinterval"
for i in g:
    print i
    d=0
    for z in res:
      #print z
      print res
      if z<i:
        d+=1
        #res.remove(z)
        print z
        print d
        print "\nupdated res list"
        
        print res
    res=res[d:]
    f.append(d)
print "\nthe final list"
print f
#       f.append()     
#Chi-square==X1, here
X=0
k=150
for i in range(150):
      print float(f[i])
      print float(num)
      print float(k)
      print X
      X=X+ float(f[i]-(num/k))*(f[i]-(num/k))
      print "\n this is the value of X"
      print X
      print "\n"
print "\nCH-Square value X1"
print X
print num
print k
X1= float(k*(float(X/(num))))
print X1


