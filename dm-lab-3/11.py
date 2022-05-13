n = int(input())
 
def gen(p):
    print(*p)
    for i in range(1, n + 1):
        if len(p) == 0 or i > p[-1]:
            gen(p + [i])
 
gen([])
