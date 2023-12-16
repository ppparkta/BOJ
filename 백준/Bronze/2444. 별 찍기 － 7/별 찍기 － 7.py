a = int(input())
for i in range(a):
    print(f'{" "*(a-i-1)}{"*"*(i*2+1)}')
b = a-1
for i in range(b):
    print(f'{" "*(1+i)}{"*"*((b-i)*2-1)}')