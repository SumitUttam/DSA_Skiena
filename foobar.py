count = 0
n = 6
for i in range(1,n//2+1):
    print()
    for j in range(i,n-i+1):
        print()
        for k in range(1,j+1):
            count+=1
            print(i,j,k,end=" # ")

print (count)
