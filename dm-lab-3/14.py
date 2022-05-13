n = int(input())
a = [int(i) for i in input().split()]
 
f = [-1] * (n + 1)
def fact(r):
    if f[r] == -1:
        if r < 2:
            f[r] = 1
        else:
            f[r] = fact(r - 1) * r
    return f[r]
 
k = 0
def gen(p):
    global k
    if len(p) == n:
        if p == a:
            print(k)
        k += 1
        return
    for i in range(1, n + 1):
        if i not in p:
            t = fact(n - len(p) - 1)
            if a[len(p)] == i:
                gen(p + [i])
                return
            else:
                k += t
 
gen([])
