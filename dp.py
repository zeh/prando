def recDC(change,coinValueList,knownResults):
   minCoins = change
   if change in coinValueList:
      knownResults[change] = 1
      return 1
   elif knownResults[change] > 0:
      return knownResults[change]
   else:
       for i in [c for c in coinValueList if c <= change]:
         numCoins = 1 + recDC(coinValueList, change-i,
                              knownResults)
         if numCoins < minCoins:
            minCoins = numCoins
            knownResults[change] = minCoins
   return minCoins

#print(recDC([1,5,10,25],63,[0]*64))
#V,n=map(int,raw_input().split(' '))
change,n = raw_input().split(' ')
change= int(change)
n=int(n)
coinValueList=[int(x) for x in raw_input().split(' ')]
#C.sort(reverse=True)

print recDC(change,coinValueList)

