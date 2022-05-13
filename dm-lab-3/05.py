n, k = map(int, input().split())
 
def gen(size):
    if size == 1:
        return [str(j) for j in range(k)]
    pred = gen(size - 1)
    derp = pred[::-1]
    res = []
    for i in range(k):
        if i % 2 == 0:
            for j in pred:
                res.append(str(i) + j)
        else:
            for j in derp:
                res.append(str(i) + j)
    return res
 
ans = gen(n)
for i in ans:
    print(*i, sep = '')
