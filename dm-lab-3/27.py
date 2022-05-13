s = input()
n = len(s)
bal = 0
ans = '-'
for i in range(n)[::-1]:
    if s[i] == '(':
        bal -= 1
    else:
        bal += 1
    if s[i] == '(' and bal > 0:
        bal -= 1
        ans = s[:i] + ')' + '(' * ((n - i - 1 - bal) // 2) + ')' * (n - i - 1 - (n - i - 1 - bal) // 2)
        break
print(ans)
