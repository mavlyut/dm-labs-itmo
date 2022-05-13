n, k = map(int, input().split())
a = [int(i) for i in input().split()]
 
i = k - 1
while i >= 0 and a[i] == n - k + 1 + i:
    i -= 1
 
if i == -1:
    print(-1)
else:
    b = a[:i] + [a[i] + 1] + [j for j in range(a[i] + 2, a[i] + 1 + k - i)]
    print(*b)
