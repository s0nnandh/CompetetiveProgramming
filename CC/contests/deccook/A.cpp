#include<bits/stdc++.h>
#include<unordered_map>
#define ll long long
#define ull unsigned long long
#define ln cout<<"\n"
#define dbg(x) cout<<#x<<" = "<<x<<" "
#define rep(i,s,n) for(ll i = (s);i<(n);++i)
#define DEBUG(x) do { std::cerr << #x << ": " << x << std::endl; } while (0)
using namespace std;

void solve(){
    int n;cin>>n;
    string s;cin>>s;int ones = 0;
    rep(i,0,n){
        if(s[i] == '1')++ones;
    }
    n = 120 - n;
    cout<<(n+ones>=90?"YES":"NO");
    ln;
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