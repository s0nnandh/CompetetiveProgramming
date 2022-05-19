import sys
def dec(binary): 
      
    binary1 = binary 
    decimal, i, n = 0, 0, 0
    while(binary != 0): 
        dec = binary % 10
        decimal = decimal + dec * pow(2, i) 
        binary = binary//10
        i += 1
    #print(arr[decimal])
    return arr[decimal]

s = "abcdefghijklmnop"
arr = list(s)
#print(arr) 
  
def solve():
    n = map(int,sys.stdin.readline().strip().split())
    k = n
    s = sys.stdin.readline().strip()
    l = len(s)
    for i in range(0,l,4):
        #print(int(s[i:i+4]))
        print(dec(int(s[i:i+4])),end='')
    print()
    

t = int(input())
while t:
    solve()
    t-=1
