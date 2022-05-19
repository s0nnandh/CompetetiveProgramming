import math
def solve():
    n = int(input())
    g = 0
    p = 1
    k = n
    ok = 1
    s = set()
    while(k > 0):
        d = k % 10
        if(d > 0):
            s.add(d)
            if(n % d > 0):
                ok = 0
        k //= 10
    if(ok == 1):
        print(n)
    else:
        sum = 0
        for x in s:
            g = math.gcd(g,x)
            p *= x
        lcm = p // g
        print(lcm)
        while(sum < n):
            sum += lcm
        print(sum)
    return

tc = int(input())
while(tc > 0):
    solve()
    tc -= 1