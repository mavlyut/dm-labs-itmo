n, k = map(int, input().split())
 
f = [-1] * (n + 1)
def fact(p):
    if f[p] == -1:
        if p < 2:
            f[p] = 1
        else:
            f[p] = fact(p - 1) * p
    return f[p]
 
a = [0] * n
used = [False] * (n + 1)
def gen(p):
    global k
    if p == n:
        print(*a)
        return 
    for i in range(1, n + 1):
        if not used[i]:
            if k >= fact(n - p - 1):
                k -= fact(n - p - 1)
            else:
                used[i] = True
                a[p] = i
                gen(p + 1)
                return
 
gen(0)
