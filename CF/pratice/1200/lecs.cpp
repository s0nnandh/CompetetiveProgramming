#include<bits/stdc++.h>
#include<unordered_map>
#define ll long long
#define ull unsigned long long
#define ln cout<<"\n"
#define dbg(x) cout<<#x<<" = "<<x<<" "
#define rep(i,s,n) for(ll i = (s);i<(n);++i)
using namespace std;

void solve(){ 
    ll n,k;
    cin>>n>>k;
    vector<ll> v(n),t(n);
    rep(i,0,n){
        cin>>v[i];
    }
    ll total = 0;
    rep(i,0,n){
        cin>>t[i];
        if(t[i] == 1){
            total+=v[i];
            v[i] = 0;
        }
    }
    vector<ll> sums(n+1,0);
    rep(i,1,n+1){
        sums[i]=sums[i-1]+v[i-1];
    }
    ll ans = 0;
    rep(i,0,n-k+1){
        //dbg(sums[i+k]-sums[i]);ln;
        ans = max(ans,sums[i+k]-sums[i]);
    }
    cout<<total+ans;ln;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);   
    int test=1;
    //cin>>test;   
    while(test--)
        solve();
    return 0;
}

// PREFIX SUMS PROBLEM.