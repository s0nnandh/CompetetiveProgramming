#include<bits/stdc++.h>
#include<unordered_map>
#define ll long long
#define ull unsigned long long
#define ln cout<<"\n"
#define dbg(x) cout<<#x<<" = "<<x<<" "
#define for(i,s,n) for(ll i = (s);i<(n);++i)
using namespace std;

void solve(){ 
    ll x;
    cin>>x;
    int k = 0;
    while(x>0){ 
        ++k;           
        ull p = (1LL<<k) - 1;
        x -= (p*(p+1))/2;
    }
    if(x == 0)++k;
    cout<<k - 1;ln;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);   
    int test=1;
    cin>>test;   
    while(test--)
        solve();
    return 0;
}