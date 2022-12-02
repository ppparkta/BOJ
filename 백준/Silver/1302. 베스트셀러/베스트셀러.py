num=int(input())
a={}
arr=[]
for i in range(num):
    b=input()
    if b not in a:
        a[b]=1
    else:
        a[b]+=+1
ans=max(a.values())
for i in a:
    if a[i]==ans:
        arr.append(i)
arr.sort()
print(arr[0])