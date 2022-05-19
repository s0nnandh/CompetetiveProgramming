#include<bits/stdc++.h>
#include<unordered_map>
#define ll long long
#define ull unsigned long long
#define ln cout<<"\n"
#define dbg(x) cout<<#x<<" = "<<x<<" "
#define rep(i,s,n) for(ll i = (s);i<(n);++i)
using namespace std;
void solve(){
    int n,x,m,a,b,mx,mi;
    cin>>n>>x>>m;
    mx = x;mi = x;
    //int ans = 1;
    rep(i,0,m){
        cin>>a>>b;

        if(max(mi,a) <= min(mx,b)){
            mi = min(mi,a);
            mx = max(mx,b);
        }

        // if(a<=mi && b>=mx){
        //     ans = b-a+1;
        //     mi = a;
        //     mx = b;
        // }
        // else if(a<=mi && b>=mi){
        //     ans=max(mx,b)-min(a,mi)+1;
        //     mi = min(a,mi);
        //     mx = max(mx,b);
        // }
        // else if(a<=mx && b>=mx){
        //     ans=max(mx,b)-min(a,mi)+1;
        //     mi = min(a,mi);
        //     mx = max(mx,b);
        // }
        
    }
    cout<<mx-mi+1;ln;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);    
    int test=1;
    cin>>test;   
    while(test--)
        solve();
}

// SUFFICIENT CONDITION TO CHECK WHETHER TWO SEGMENTS OVERLAP OR NOT
// max(mi,a) <= min(mx,b)
