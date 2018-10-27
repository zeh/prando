mat=input("enter the matrix:")
lis=mat.split(';')
count=0
for j in range(len(lis)-1):
    if lis[j][0]==lis[j+1][len(lis[j])-1]:
        for i in range(1,len(lis[j])):
            if lis[j][i]==lis[j+1][i-1]:
                count+=1
if count==(len(lis)-1)*(len(lis[0])-1) :
    print("matrix is circulant")
else :
    print("matrix is not circulant")                
