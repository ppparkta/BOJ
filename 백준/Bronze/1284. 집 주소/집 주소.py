while True:
    n = input()
    if n == "0":
        break
    ans = 1
    for i in n:
        if i == "1":
            ans += 2
        elif i == "0":
            ans += 4
        else:
            ans += 3
        ans += 1
    print(ans)
