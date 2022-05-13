n = int(input())
a = [int(i) for i in input().split()]
 
ind = -1
for i in range(n - 2, -1, -1):
    if a[i] < a[i + 1]:
        ind = i
        break
 
if ind == -1:
    print('0 ' * n)
else:
    left = ind + 1
    while left < n - 1 and a[left + 1] > a[ind]:
        left += 1
 
    r = a[ind]
    a[ind] = a[left]
    a[left] = r
 
    print(*(a[0 : ind + 1] + a[ind + 1 : n][::-1]))
