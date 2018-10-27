def p(x,l,r):
  if l == r:
    print (''.join(x))
  else:
    for i in range(l,r+1):
      x[i], x[l] = x[l], x[i]
      p(x,l+1,r)
      x[i], x[l] = x[l], x[i]
      

def permute(a):
  return p(list(a),0,len(a)-1)
  
str = input("Input the string:")
permute(str)
