#include<bits/stdc++.h>
#define ll long long
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
#define dbg(...) cerr << "" << endl
#endif

#define pi pair<int,int>
#define pl pair<ll,ll> 
#define fr first
#define sc second
#define pb push_back
#define gcd(a,b) __gcd(a,b)
#define len(x) (int)x.size()
#define all(x) x.begin(),x.end()
#define vi vector<int>
#define vl vector<ll>

vector<vi> g;
const int nx = 1e5 + 5;
int sz[nx];
int cen[nx];
int d[nx];
int p[nx];
int Min = 1e9,Maxd = 0;

int total;
void dfs(int u,int par){
    sz[u] = 1;  
    cen[u] = 0;
    if(par != -1)d[u] = 1 + d[par];
    Maxd = max(Maxd,d[u]);
    for(auto x : g[u]){
        if(x == par)continue;
        p[x] = u;
        dfs(x,u);
        sz[u] += sz[x];
        cen[u] = max(cen[u],sz[x]);
    }
    cen[u] = max(cen[u],total - sz[u]);
    Min = min(Min,cen[u]);
}
pi L = {-1,-1};
void leaf(int u,int par){
    if(L.fr != -1)return;
    int cnt = 0;
    for(auto x : g[u]){
        if(d[x] > d[u]){
            ++cnt;
            leaf(x,u);
        }
    }
    if(cnt == 0){
        L = {par,u};
    }
}

void solve(){    
    int n;
    cin >> n;
    total = n;
    g.resize(n);
    Min = 1e9,Maxd = 0;
    pi e;
    rep(i,0,n - 1){
        int a,b;
        cin >> a >> b;
        e = {a,b};
        --a;--b;
        g[b].pb(a);
        g[a].pb(b);
    }
    d[0] = 0;
    dfs(0,-1);
    // dbg(Min);
    int cnt = 0;
    rep(i,0,n)cnt += cen[i] == Min;
    // dbg(cnt);
    if(cnt == 1){
        cout << e.fr << " " << e.sc;ln;
        cout << e.fr << " " << e.sc;ln;
        // dbg(cnt);
    }
    else{  
        L = {-1,-1};
        int u = -1,dep = 0;
        rep(i,0,n){
            if(cen[i] == Min && d[i] > dep){
                u = i;
                dep  = d[i];
            }
        }
        // dbg(u);
        // rep(i,0,n)cout << d[i];ln;
        leaf(u,-1);
        // dbg(u + 1,p[u] + 1);
        assert(L.fr != -1);
        cout << L.fr + 1 << " " << L.sc+ 1;ln;
        cout << p[u] + 1 << " " << L.sc + 1;ln;
    }
    rep(i,0,n)g[i].clear();
    g.clear();
}       

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL); 
    // gen_factorial(1e6);  	
    int test=1;
	cin>>test;   
    while(test--)
        solve();
    return 0;
}
