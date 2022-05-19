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
#define ctz(x) __builtin_ctzll(x)
#define pb push_back

const int N = 100000;
const int lo = 20;

map<pl,ll> mp;
vector<ll> cost(N);

void dfs(int a,vector<vector<int>> &adj,vector<vector<int>> &up,vector<int> &d,vector<bool> &v){
	if(!v[a]){
		v[a] = 1;
		for(auto b : adj[a]){
			cost[b] = cost[a] + mp[{a,b}];
			d[b] = d[a] + 1;
			up[b][0] = a;
			rep(i,1,lo){
				up[b][i] = up[up[b][i-1]][i-1];
			}
			if(!v[b])dfs(b,adj,up,d,v);
		}
	}
}

// correct lca

// void dfs(int a,vector<vector<int>> &adj,vector<vector<int>> &up,vector<int> &d,vector<bool> &v,vector<int> &cost){
// 	if(!v[a]){
// 		v[a] = 1;
// 		for(auto b : adj[a]){
//             if(!v[b]){
// 			cost[b] = cost[a] + 1;
// 			d[b] = d[a] + 1;
// 			up[b][0] = a;
// 			rep(i,1,lo){
// 				up[b][i] = up[up[b][i-1]][i-1];
// 			}
// 			dfs(b,adj,up,d,v,cost);
//             }
// 		}
// 	}
// }

int lca(int a,int b,vector<int> &d,vector<vector<int>> &up){
	if(a == b)return a;
	if(d[a] < d[b]){
		swap(a,b);
	}
	int k = d[a] - d[b];
	for(int i = 19 ; i >= 0;--i){
		if(k&(1<<i))a = up[a][i];
	}
	if(a == b)return a;
	for(int i = 19;i >= 0;--i){
		if(up[a][i] != up[b][i]){
			a = up[a][i];
			b = up[b][i];
		}
	}
	return up[a][0];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);    
    int tt = 1;
	cin >> tt;
	
	while(tt--){	
		mp.clear();		
		int n,q,r;
		cin >> n >> q >> r;
		--r;
		vector<vector<int>> adj(n);
		rep(i,0,n-1){
			ll a,b,c;
			cin >> a >> b >> c;
			--a;--b;
			adj[a].pb(b);
			adj[b].pb(a);
			mp[{a,b}] = c;
			mp[{b,a}] = c;
		}
		
		// vector<ll> cost(n);
		//int up[n][20];
		// up[r][0] = r;
		vector<int> d(n);
		vector<bool> vis(n);
		vector<vector<int>> up(n,vector<int> (20));
		dfs(r,adj,up,d,vis);
		rep(i,0,q){
			int u,v;
			cin >> u >> v;
			--u;--v;
			int a = lca(u,v,d,up);
			ll f  = cost[u] - cost[a],s = cost[v] - cost[a];
			cout << s + f;
			ln;
		}
	}
}


