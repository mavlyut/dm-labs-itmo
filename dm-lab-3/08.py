n, k = map(int, input().split())
 
def gen(p):
    if len(p) == k:
        print(*p)
        return
    for i in range(1, n + 1):
        if len(p) > 0 and i <= p[-1]:
            continue
        if n - i < k - len(p) - 1:
            break
        gen(p + [i])
 
gen([])
