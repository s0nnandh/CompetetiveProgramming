#include<bits/stdc++.h>
using namespace std;
vector<pair<long long,int>> pff(long long n){
    vector<pair<long long,int>> fac;
    long long cnt=0;
    while (n % 2 == 0)
    {
        cnt++;
        n = n/2;
    }
    if(cnt!=0)
    fac.push_back({2,cnt});


    for (long long i = 3; i * i <= n; i = i + 2)
    {
        cnt=0;
        if(n==1)break;
        while (n % i == 0)
        {
            cnt++;
            n = n/i;
        }
            if(cnt!=0)
    fac.push_back({i,cnt});
    }
    if (n > 2)
    fac.push_back({n,1});
    
    return fac;
}
