#include<bits/stdc++.h>
#include<unordered_map>
#define ll long long
#define ull unsigned long long
#define ln cout<<"\n"
#define dbg(x) cout<<#x<<" = "<<x<<" "
#define rep(i,s,n) for(ll i = (s);i<(n);++i)
using namespace std;

void solve(){
    int n;cin>>n;
    vector<int> a(n),cnt(102,0);
    rep(i,0,n){
        cin>>a[i];
        cnt[a[i]]++;
    }
    int m;cin>>m;
    vector<int> b(m);
    rep(i,0,m)cin>>b[i];
    sort(b.begin(),b.end());
    int ans = 0;
    rep(i,0,m){
        int k = b[i];
        if(cnt[k-1]!= 0){
            ++ans;
            --cnt[k-1];
        }
        else if(cnt[k] != 0){
            ++ans;
            --cnt[k];
        }
        else if(cnt[k+1] != 0){
            ++ans;
            --cnt[k+1];
        }
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