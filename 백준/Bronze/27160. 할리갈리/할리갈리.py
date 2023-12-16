n = int(input())
check = False
dic = {'BANANA':0, 'PLUM':0, 'STRAWBERRY':0, 'LIME':0}
for i in range(n):
	a, C = input().split(' ')
	c = int(C)
	dic[a] += c
for i in dic.values():
	if i == 5:
		print("YES")
		check = True
		break;
if check == False:
	print("NO")