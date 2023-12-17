# 1193 분수찾기
a = int(input())

list1 = []
i = 1
while a > i:
	a -= i
	i+=1 
for j in range(1, i + 1):
	if i % 2 == 1:
		str1 = str(i - j + 1) + "/" + str(j)
	else:
		str1 = str(j) + "/" + str(i - j + 1)
	list1.append(str1)


print(list1[a-1])