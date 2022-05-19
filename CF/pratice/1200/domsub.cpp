#include<bits/stdc++.h>
#include<unordered_map>
#define ll long long
#define ull unsigned long long
#define ln cout<<"\n"
#define dbg(x) cout<<#x<<" = "<<x<<" "
#define rep(i,s,n) for(ll i = (s);i<(n);++i)
using namespace std;

void solve(){ 
    int n;
    cin>>n;
    vector<int> v(n),prev(n+1,-1),vf(n,-1),cnt(n+1);
    rep(i,0,n){
        cin>>v[i];
        cnt[v[i]]++;
        vf[i] = prev[v[i]]; //CREATED PREFIX ARRAY WHICH STORES AT WHCH 
                            // INDEX THE NUMBER PREVIOUSLY OCCURED IN vf vector
        prev[v[i]] = i;
    }
    //rep(i,0,n)cout<<vf[i]<<" ";
    //ln;
    int ans = 1e9;
    for(int i = n-1;i>=0;--i){
        if(vf[i] != -1)ans = min(ans,i-vf[i]+1);
    }
    if(ans == 1e9)ans = -1;
    cout<<ans;ln;
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