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
const int nx = 2e5 + 5;
vector<int> adj[nx];
ll in[nx];
ll out[nx];
ll c[nx];
ll A[nx];
int d[nx];
void dfs1(int u,int par){
    if(par != -1)d[u] = 1 + d[par];
	c[u] += A[u];
    for(auto x : adj[u]){
        if(x == par)continue;
        dfs1(x,u);
        c[u] += c[x];
		in[u] += in[x] + c[x];
    }   
    // for(auto x : adj[u]){
    //     if(x == par)continue;
        
    // }
}

void dfs(int u,int par){
    if(par != -1){
		// partial is 
		// ll partial = out[par] - in[u];
		out[u] += out[par] + c[0] - 2*c[u];
	}
	for(auto x : adj[u]){
		if(x == par)continue;
		dfs(x,u);
	}
}
void solve(){
    int n;
    cin >> n;
    rep(i,0,n){
        in[i] = 0;
        out[i] = 0;
        c[i] = 0;
    }
	rep(i,0,n)cin >> A[i];
    rep(i,0,n - 1){
        int a,b;
        cin >> a >> b;
        --a;--b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    dfs1(0,-1);
	out[0] = in[0];
    dfs(0,-1);
	ll ans = 0;
    rep(i,0,n)ans = max(ans,out[i]);
	cout << ans;
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