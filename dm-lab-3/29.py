s = input()
n = int(s[:s.find('=')])
a = [int(i) for i in s[s.find('=') + 1 :].split('+')]

k = len(a)
if k > 1:
    if a[k - 1] - 1 < a[k - 2] + 1:
        a[k - 2] += a[k - 1]
        k -= 1
    else:
        a[k - 1] -= 1
        a[k - 2] += 1
        while a[k - 2] * 2 <= a[k - 1]:
            a.append(a[k - 1] - a[k - 2])
            a[k - 1] = a[k - 2]
            k += 1

    print(n, end = '=')
    print(*a[:k], sep = '+')
else:
    print('No solution')
