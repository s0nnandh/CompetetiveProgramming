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

struct UF {
	vector<int> par, ran;
public:
	UF(int n) {
		par.resize(n, 0);
		ran.resize(n, 0);
		rep(i,0, n) {
			par[i] = i;
		}
	}
	int find(int x) {
		if (par[x] == x)return x;
		else return par[x] = find(par[x]);
	}
	void unite(int x, int y) {
		x = find(x), y = find(y);
		if (x == y)return;
		if (ran[x] < ran[y]) {
			par[x] = y;
		}
		else {
			par[y] = x;
			if (ran[x] == ran[y])ran[x]++;
		}
	}
	bool same(int x, int y) {
		return find(x) == find(y);
	}
};
vector<vector<int>> adj;
vector<bool> v;
vector<int> parent;
int start,en;

bool dfs(int u,int par){
    v[u] = 1;
    for(auto x : adj[u]){
        if(x == par)continue;
        if(v[x]){
            en = u;
            start = x;
            return true;
        }
        parent[x] = u;
        if(dfs(x,u))return 1;
    }
    return 0;
}

void solve(){

    int n,m;
    cin >> n >> m;
    adj.resize(n);
    v.resize(n);
    parent.resize(n,-1);
    UF uf(n);
    bool cyc = 0;
    int node;
    rep(i,0,m){
        int a,b;
        cin >> a >> b;
        --a;--b;
        if(a == b)continue;
        if(!cyc){
            if(uf.same(a,b)){
                cyc = 1;
                node = a;
            }
            else{
                uf.unite(a,b);
            }
        }
        adj[a].pb(b);
        adj[b].pb(a);
    }
    if(!cyc){
        cout << "IMPOSSIBLE";ln;
        return;
    }
    dfs(node,-1);
    vector<int> cycle;
    cycle.push_back(start);
    for (int v = en; v != start; v = parent[v])
        cycle.push_back(v);
    cycle.push_back(start);
    reverse(cycle.begin(), cycle.end());
    cout << cycle.size();ln;
    for(auto x : cycle)cout << x + 1 << " ";
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