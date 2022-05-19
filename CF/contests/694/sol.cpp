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

struct UF{
    vector<int> par, sz;
    UF() {}
    UF(int n):par(n), sz(n, 1){
        for(int i=0; i<n; i++) par[i]=i;
    }
    int find(int x){
        if(par[x]==x) return x;
        return par[x]=find(par[x]);
    }
    void unite(int x, int y){
        x=find(x); y=find(y);
        if(x==y) return;
        if(sz[x]>sz[y]) swap(x, y);
        par[x]=y;
        sz[y]+=sz[x];
    }
    bool same(int x, int y){
        return find(x)==find(y);
    }
    int size(int x){
        return sz[find(x)];
    }
};
vector<vector<int>> adj;
vector<int> c;
void solve(){
	
    int n,m;
    cin >> n >> m;
    adj.resize(n);
    UF uf(n);   
    rep(i,0,m){
        int a,b;
        cin >> a >> b;
        --a;--b;
        adj[a].pb(b);
        adj[b].pb(a);
        uf.unite(a,b);  
    }
    if(*max_element(all(uf.sz)) != n){
        cout << "NO";
        ln;
        rep(i,0,n)adj[i].clear();
        adj.clear();
        c.clear();
        return;
    }
    c.resize(n,-1);
    queue<int> q;
    c[0] = 0;
    for(auto x : adj[0]){
        q.push(x);
        c[x] = 1;
    }
    // white nodes color the others white
    while(!q.empty()){
        int u = q.front();
        q.pop();
        // these are colored white
        for(auto x : adj[u]){
            if(c[x] == -1){
                c[x] = 0;
                for(auto y : adj[x]){
                    if(c[y] == -1){
                        c[y] = 1;
                        q.push(y);
                    }
                }
            }
        }
    }
    cout << "YES";ln;
    int ans = 0;
    rep(i,0,n)ans += c[i] == 0;
    cout << ans;ln;
    rep(i,0,n){
        if(c[i] == 0)cout << i + 1 << " ";
    }
    ln;
    rep(i,0,n)adj[i].clear();
    adj.clear();
    c.clear();
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
