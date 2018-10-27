def dpMakeChange(V,C,d=[]):
   for cents in range(V+1):
      coinCount = cents
      for j in [c for c in C if c <= cents]:
            if d[cents-j] + 1 < coinCount:
               coinCount = d[cents-j]+1
      d[cents] = coinCount
   return d[V]
V,n=raw_input().split(' ')
V=int(V)
n=int(n)
C=[int(x) for x in raw_input().split(' ')]
C.sort(reverse=True)

print dpMakeChange(V,C)

