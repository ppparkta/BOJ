arr=[0 for i in range(5)]
idx=0
m=0
for i in range(5):
    a,b,c,d=map(int,input().split())
    arr[i]=a+b+c+d
for i in range(5):
    if m<arr[i]:
        m=arr[i]
        idx=i
print(idx+1, m)
