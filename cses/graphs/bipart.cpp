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
#define dbg(...) cerr << "" << endl
#endif

#define pi pair<int,int>
#define pl pair<ll,ll> 
#define fr first
#define sc second
#define pb push_back
#define gcd(a,b) __gcd(a,b)

ll inf = 1e18;
vector<vector<int>> adj;
vector<int> c;
bool dfs(int u,int color){
    if(c[u] != -1)return c[u] == color;
    c[u] = color;
    bool ans = 1;
    for(auto x : adj[u]){
        ans &= dfs(x,(color + 1) % 2);
    }
    return ans;
}

void solve(){
    int n,m;
    cin >> n >> m; 
    adj.resize(n);
    c.resize(n,-1);
    rep(i,0,m){
        int a,b;
        cin >> a >> b;
        --a;--b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    bool ans = 1;       
    rep(i,0,n){
        if(c[i] == -1){
            ans &= dfs(i,0);
        }
        if(ans == 0)break;
    }
    if(!ans){
        cout << "IMPOSSIBLE";ln;
        return;
    }
    for(auto x : c)cout << x + 1 << " ";
    ln;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL); 
    //gen_factorial(1e6);   
    int test=1;
    // cin>>test;   
    while(test--)
        solve();
    return 0;
}