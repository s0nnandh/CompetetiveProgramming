#include<bits/stdc++.h>
#include<stdio.h>
#define ll long long
#define ull unsigned long long
#define ln cout<<"\n"
#define dbg(x) cout<<#x<<" = "<<x<<" "
#define rep(i,s,n) for(ll i = (s);i<(n);++i)
#define DEBUG(x) do { std::cerr << #x << ": " << x << std::endl; } while (0)
#define pc(x) __builtin_popcount(x)
using namespace std;

void solve(){
    string s;
    cin >> s;
    int ans = 0,n = s.length();
    if(s[0] == s[1]){
        s[1] = '#';
        ++ans;
    }
    rep(i,2,n){
        if(s[i] == '#')continue;
        if(s[i] == s[i-1] || s[i] == s[i-2]){
            s[i] = '#';
            ++ans;
        }        
    }
    cout << ans;
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

