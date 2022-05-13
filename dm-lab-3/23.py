s = [i for i in input()]
ind = [-1] * 2
for i in range(len(s)):
    ind[s[i] == '1'] = i
 
for i in range(1, -1, -1):
    if ind[i] == -1:
        print('-')
    else:
        print(*s[:ind[i]] + [str(1 - i)] + [i] * (len(s) - ind[i] - 1), sep = '')
