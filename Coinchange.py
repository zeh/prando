def return_change(V,C,d=0):
   if V==0:
       return d
   else:
       for i in C:
 	   print i	
           if V >= i:
               q=V/i
               V=V-(i*q)
               d+=q
	       print "thi is:\n"
	       print d
       return return_change(V,C,d)


#V,n=map(int,raw_input().split(' '))
V,n = raw_input().split(' ')
V= int(V)
n=int(n)
C=[int(x) for x in raw_input().split(' ')]
#C.sort(reverse=True)

print return_change(V,C)


