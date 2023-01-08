for i in range(3):
    a=sum(map(int,input().split()))
    if a==0:
        print('D')
    elif a==1:
        print('C')
    elif a==2:
        print('B')
    elif a==3:
        print('A')
    else:
        print('E')