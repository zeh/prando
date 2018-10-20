days=["Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"]
day=input()
x=int(input())
for i in range(len(days)):
    if day==days[i]:
        newday=days[i+x]
print(newday)
