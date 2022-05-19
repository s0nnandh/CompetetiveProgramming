#include<bits/stdc++.h>
#include<unordered_map>
#define ll long long
#define ull unsigned long long
#define ln cout<<"\n"
#define dbg(x) cout<<#x<<" = "<<x<<" "
#define rep(i,s,n) for(ll i = (s);i<(n);++i)
#define DEBUG(x) do { std::cerr << #x << ": " << x << std::endl; } while (0)
using namespace std;
const int m = 1e9 + 7;
ull _pow(ull &a, ull b) {
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res =( res * a )%m ;
        a = (a * a) %m;
        b >>= 1;
    }
    return res;
}
void solve(){
    ull n,M;
    cin >> n >> M;
    n/=2;
    n = (n*(n+1));
    M = M%m;
    cout << _pow(M,n);ln;
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
