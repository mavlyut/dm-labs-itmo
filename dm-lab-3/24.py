n = int(input())
a = [int(i) for i in input().split()]
 
def prevPerm():
    ind = n - 1
    for i in range(n - 2, -1, -1):
        if a[i + 1] <= a[i]:
            ind = i
            break
    k = 0
    for i in a[ind + 1:]:
        if i < a[ind]:
            k = max(k, i)
    if k != 0:
        r = []
        for i in a[ind:]:
            if i != k:
                r.append(i)
        return a[:ind] + [k] + sorted(r)[::-1]
    return [0] * n
 
 
def nextPerm():
    ind = n - 1
    for i in range(n - 2, -1, -1):
        if a[i + 1] >= a[i]:
            ind = i
            break
    k = 1000000
    for i in a[ind + 1:]:
        if i > a[ind]:
            k = min(k, i)
    if k != 1000000:
        r = []
        for i in a[ind:]:
            if i != k:
                r.append(i)
        return a[:ind] + [k] + sorted(r)
    return [0] * n
 
print(*prevPerm())
print(*nextPerm())
