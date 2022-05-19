#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ln cout<<"\n"
using namespace std;
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
#define dbg(...) {}
#endif

#define pi pair<int,int>
#define pl pair<ll,ll> 
#define fr first
#define sc second
#define pb push_back
#define gcd(a,b) __gcd(a,b)
#define all(x) x.begin(),x.end()

vector<vector<int>> adj;
vector<bool> vis;
void dfs(int u,int &sum){
    sum++;
    vis[u] = 1;
    for(auto x : adj[u]){
        if(!vis[x])dfs(x,sum);
    }
}

void solve(){
    int n;
    cin >> n;
    vector<int> v(n);
    map<int,int> mp;
    for(auto &i : v){
        cin >> i;
        mp[i] = 0;
    }
    int sz = 0;
    for(auto x : mp){
        mp[x.fr] = sz++;
    }   
    adj.resize(sz);
    vis.resize(sz);
    int l = 0,r = n-1;
    while(l <= r){
        adj[mp[v[l]]].pb(mp[v[r]]);
        adj[mp[v[r]]].pb(mp[v[l]]);
        ++l;
        --r;
    }
    ll ans = 0;
    rep(i,0,sz){       
        if(!vis[i]){
            int cyc = 0;
            dfs(i,cyc);
            ans += cyc - 1;
        }
    }
    cout << ans;ln;
}   


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);        
    int test=1;
    // cin>>test;   
    while(test--)
        solve();
    return 0;
}