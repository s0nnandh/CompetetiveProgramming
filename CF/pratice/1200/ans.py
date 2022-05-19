import copy
def solve():
    n = int(input())
    arr = list(map(int,input().strip().split()))[:n]
    v = copy.deepcopy(arr)
    v.sort()
    idx = [0] * 1001
    for i in range(n):
        idx[arr[i]] = i
    ans = 0
    for i in range(n):
        if(arr[i] != v[i]):
            id1 = i
            id2 = idx[v[i]]
            ans += 1
            arr[id1],arr[id2] = arr[id2],arr[id1]
            idx[v[i]] = id1
            idx[arr[i]] = id2
    print(ans)
    return

t = int(input())
while(t > 0):
    solve()
    t -= 1