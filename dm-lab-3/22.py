# dp[n][m] - количество способов разбить n на слагаемые >=m
# dp[n][m] = dp[n - m][m] + dp[n][m + 1]
# dp[n][m] = 0 if m > n and 1 if m == n
# dp[0][m] = 0 if m > 0 and 1 if m == 0
 
 
s = [int(i) for i in input().split('+')]
n = sum(s)
 
dp = []
for i in range(n + 1):
    dp.append([0] * (n + 1))
 
dp[0][0] = 1
 
for i in range(1, n + 1):
    for j in range(n, 0, -1):
        if j >= i:
            dp[i][j] = int(i == j)
        else:
            dp[i][j] = dp[i - j][j] + dp[i][j + 1]
 
z = 0
def gen(p, a, left):
    global z
    if a == n:
        if p == s:
            print(z)
            return
        z += 1
    for i in range(left, n + 1):
        if a + i <= n:
            t = dp[n - a - i][i]
            if s[len(p)] == i:
                gen(p + [i], a + i, i)
                return
            else:
                z += t
 
gen([], 0, 1)
