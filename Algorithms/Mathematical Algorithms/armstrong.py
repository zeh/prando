limit = int(input("Input the range: "))
for i in range(1, limit + 1):
   order = len(str(i))
   sum = 0
   temp = i
   while temp > 0:
       digit = temp % 10
       sum += digit ** order
       temp //= 10
   if i == sum:
       print(i)