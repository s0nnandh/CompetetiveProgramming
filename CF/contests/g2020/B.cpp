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
    int n;
    cin >> n;
    vector<int> v((2*n) + 2);
    int a;
    rep(i,0,n){
        cin >> a;
        v[a]++;
    }
    int ans = 0;
    rep(i,1,(2*n)+2){
        if(v[i]>1){
            --v[i];
            ++v[i+1];
        }
        
    }
    rep(i,1,2*n + 2){
        if(v[i] != 0)++ans;
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

