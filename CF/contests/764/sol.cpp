#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ln cout<<"\n"
#define rep(i,s,n) for(ll i = (s);i<(n);++i)
#define pc(x) __builtin_popcount(x)
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
void __dbg(int x) {cerr << x;}
void __dbg(long long x) {cerr << x;}
void __dbg(float x) {cerr << x;}
void __dbg(double x) {cerr << x;}
void __dbg(long double x) {cerr << x;}
void __dbg(char x) {cerr << '\'' << x << '\'';}
void __dbg(const char *x) {cerr << '\"' << x << '\"';}
void __dbg(const string &x) {cerr << '\"' << x << '\"';}
void __dbg(bool x) {cerr << (x ? "true" : "false");} 
template<class T,class V>void __dbg(const pair<T, V> &x) {cerr << "{ "; __dbg(x.first); cerr << ','; __dbg(x.second); cerr << "}";}
template<class T>void __dbg(const T &x) {int f = 0; cerr << "{ "; for (auto &i: x) cerr << (f++ ? "," : ""), __dbg(i); cerr << "}";}
void _dbg() {cerr << " ]" << endl ;}
template <class T, class... V>void _dbg(T t, V... v) {__dbg(t); if (sizeof...(v)) cerr << ", "; _dbg(v...);} 
#ifdef _DEBUG
#define dbg(x...) cerr << "[" << #x << "] = [ "; _dbg(x)
#else
#define dbg(x...)
#endif 

struct edge{
    int a,b,c;
    edge(){

    }
    edge(int f,int t,int C){
        a = f;
        b = t;
        c = C;
    }
};

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

void solve(){
    int n,m;
    cin >> n >> m;
    vector<edge> E;
    for(int i = 0;i < m;++i){
        int a,b,c;
        cin >> a >> b >> c;
        E.push_back(edge(a,b,c));
    }
    int ans = 0;
    for(int j = 29;j >= 0;--j){
        vector<edge> t;
        for(auto x : E){
            if((x.c&(1 << j)) == 0)t.push_back(x);
        }
        UF uf(n);
        for(auto x : t){
            uf.unite(x.a - 1,x.b - 1);
        }
        int ok = *max_element(all(uf.sz));
        if(ok == n){
            ans |= (1 << j);
            E = t;
        }
    }
    cout << (1 << 30) - ans - 1 << '\n';
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