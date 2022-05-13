n = int(input())
 
def gen(p, a):
    if a >= n:
        if a == n:
            print(*p, sep = '+')
        return
    for i in range(1, n - a + 1):
        if len(p) == 0 or i >= p[-1]:
            gen(p + [i], a + i)
 
gen([], 0)
