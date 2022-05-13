s = input()
eq = ''
for i in range(ord('a'), ord('z') + 1):
	eq += chr(i)
for i in s:
	k = eq.find(i)
	print(k + 1, end = ' ')
	eq = i + eq[:k] + eq[k + 1:]
