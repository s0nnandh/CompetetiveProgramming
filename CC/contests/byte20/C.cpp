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
    // int n,q,l,r;
    // cin >> n>> q;
    // map<pair<int,int>,int> mp;
    // vector<int> ans(n+1,0);
    // rep(i,0,q){
    //     cin>>l>>r;
    //     mp[make_pair(l,r)]++;
    // }
    // for(auto x  : mp){
    //     int a = x.first.first,b = x.first.second,cnt = x.second;
    //     for(int i = a;i<=b;++i){
    //         ans[i]+=cnt * (i-a+1);
    //     }
    // }
    // rep(i,1,n+1){
    //     cout<<ans[i]<<" ";
    // }
    // ln;
    int n,q,l,r;
    cin >> n >> q;
    vector<int> ans(n+2);
    vector<pair<int,int>> p;
    rep(i,0,q){
        cin >> l >> r;
        ans[l]++;
        --ans[r+1];
        //ans[r+1]-=r-l+1;
        p.push_back({l,r});
    }
    rep(i,1,n+1){
        ans[i]+=ans[i-1];
    }
    for(auto x : p){
        ans[x.second+1]-=x.second+1-x.first;
    }
    rep(i,1,n+1){
        ans[i]+=ans[i-1];
    }
    rep(i,1,n+1){
        cout<<ans[i]<<" ";
    }
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


