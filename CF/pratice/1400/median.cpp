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
int n, k ;
bool check(vector<int> &v,ll x){
    ll t = 0;
    rep(i,(n+1)/2,n+1){
        t+=max((ll)0,x-v[i]);
        if(t > k)break;
    }
    //if(x == 3)cout<<t;  
    return t<=k; 
}
void solve(){
    
    cin >> n >> k;
    vector<int> v(n+1);
    rep(i,1,n+1)cin>>v[i];
    //dbg(check(v,2));ln;
    sort(v.begin()+1,v.end());
    ll l = 1,r = LLONG_MAX,mid,ans = 0;
    while(l <= r){
        mid = l + (r-l)/2;
        if(check(v,mid)){
            ans = mid;
            l = mid + 1;
        }
        else r = mid - 1;
    }
    cout<<ans;ln;
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

