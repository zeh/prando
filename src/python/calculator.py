a=int(input())
b=int(input())
c=int(input())
print("choose any of the below operations:")
print("[A]dd\n[M]ultiply\nm[I]n\ne[X]it")
x=input("enter A, M, I or X:")
if x=='A' or x=='a' :
    print(a+b+c)
elif x=='M' or x=='m' :
    print(a*b*c)
elif x=='I' or x=='i' :
    print(min(a,b,c))
elif x=='E' or x=='e' :
    pass
else:
    print("error! invalid input")
    
