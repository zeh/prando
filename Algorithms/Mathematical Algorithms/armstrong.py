lower = int(input("Input the start point: "))
limit = int(input("Input the end point: "))
for i in range(lower, limit + 1):
   order = len(str(i))
   sum = 0
   temp = i
   while temp > 0:
       digit = temp % 10
       sum += digit ** order
       temp //= 10
   if i == sum:
       print(i)