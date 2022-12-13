n = int(input())
arr = []
y = 0
m = 0
arr = list(map(int, input().split()))
for i in arr:
    y += i//30*10+10
    m += i//60*15+15
if y == m:
    print(f"Y M {y}")
elif y > m:
    print(f"M {m}")
else:
    print(f"Y {y}")
