def tern(a, n):
    res1, res2, res3 = [], [], []
    for i in range(n):
        res1.append(a % 3)
        res2.append((a + 1) % 3)
        res3.append((a + 2) % 3)
        a //= 3
    print(*res1[::-1], sep = '')
    print(*res2[::-1], sep = '')
    print(*res3[::-1], sep = '')
 
n, a = int(input()), []
for i in range(3 ** (n - 1)):
    tern(i, n)
