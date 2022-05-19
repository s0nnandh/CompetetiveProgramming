#include<bits/stdc++.h>
#include<stdio.h>
#define ll long long
#define ull unsigned long long
#define ln cout<<"\n"
using namespace std;
//#define dbg(x) cout<<#x<<" = "<<x<<" "
#define rep(i,s,n) for(ll i = (s);i<(n);++i)
#define pc(x) __builtin_popcount(x)
void DBG() {
	cerr << "]" << endl;
}
template<class H, class... T> void DBG(H h, T... t) {
    //cerr << '[' << endl;
	cerr << to_string(h);
	if(sizeof...(t))
		cerr << ", ";
	DBG(t...);
}
#ifdef _DEBUG
#define dbg(...) cerr << "LINE(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)
#else
#define dbg(...) cerr << "[ ]" << endl
#endif

#define pl pair<ll,ll>
#define pb push_back

void dfs(int i,vector<vector<int>> &adj,vector<int> &c,vector<bool> &ans,map<int,bool> &mp,vector<bool> &v){
    if(!v[i]){
        v[i] = 1;
        bool now = 0;
        if(mp[c[i]] == 0){
            mp[c[i]] = 1;
            ans[i] = 1;
            now = 1;
        }
        for(auto x : adj[i]){
            if(!v[x]){
                dfs(x,adj,c,ans,mp,v);
            }
        }
        if(now)mp[c[i]] = 0;
    }
    
}

void solve(){
    int n;
    cin >> n;
    vector<int> c(n+1);
    rep(i,1,n+1)cin >> c[i];
    vector<vector<int>> adj(n+1);
    rep(i,0,n-1){
        int a,b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    vector<bool> ans(n+1);
    ans[1] = 1;
    vector<bool> vis(n+1);
    map<int,bool> mp;
    dfs(1,adj,c,ans,mp,vis);
    rep(i,1,n+1){
        if(ans[i]){
            cout << i ;ln;
        }
    }
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

