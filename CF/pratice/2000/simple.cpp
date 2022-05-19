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

vector<vector<int>> adj;
vector<int> parent;
vector<bool> v;
vector<bool> in;
int cstart,cen;

bool dfs(int u,int par){
	v[u] = 1;
	for(auto x : adj[u]){
		if(x == par)continue;
		if(v[x]){
			cstart = x;
			cen = u;
			return 1;
		}
		parent[x] = u;
		if(dfs(x,u))return 1;
	}
	return 0;
}
ll _dfs(int u,int par){
	int ans = 1;
	// dbg(u);
	for(auto x : adj[u]){
		if(x == par)continue;
		if(!in[x])ans +=_dfs(x,u);
	}
	return ans;
}

void solve(){
	int n;
	cin >> n;
	adj.resize(n);
	parent.resize(n,-1);
	v.resize(n);
	in.resize(n);
	rep(i,0,n){
		int a,b;
		cin >> a >> b;
		--a;--b;
		adj[a].pb(b);
		adj[b].pb(a);
	}
	dfs(0,-1);
	vector<int> cyc;
	cyc.pb(cstart);
	while(cen != cstart){
		cyc.pb(cen);
		cen = parent[cen];
	}
	
	for(auto x : cyc)in[x] = 1;
	ll ans = ((ll)n * (n - 1));
	for(auto x : cyc){
		ll sz = _dfs(x,-1);	
		// dbg(x,sz);
		// dbg(ans,sz);	
		ans -= (sz * (sz - 1))/2;
	}
	cout << ans;ln;
	rep(i,0,n)adj.clear();
	adj.clear();
	parent.clear();
	v.clear();
	in.clear();
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL); 
    //gen_factorial(1e6);   
    int test=1;
    cin>>test;   
    while(test--)
        solve();
    return 0;
}