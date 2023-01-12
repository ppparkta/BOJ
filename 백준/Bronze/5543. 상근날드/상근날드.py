a = 2001
b = 2001
for _ in range(3):
    n = int(input())
    if a > n:
        a = n
for _ in range(2):
    n = int(input())
    if b > n:
        b = n
print(a+b-50)
