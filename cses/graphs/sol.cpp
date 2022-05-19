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
const int nx = 1e5 + 5;

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
    UF uf(n);
    set<int> s;
    rep(i,0,n)s.insert(i);
    auto tell = [&](int a,int b){
        cout << a << " " << b;
        ln;
    };
    int ma = 1;
    rep(i,0,m){
        int a,b;
        cin >> a >> b;
        --a;--b;    
        int x = uf.find(a),y = uf.find(b);
        if(x == y){
            tell(s.size(),ma);
            continue;
        }
        if(uf.sz[x] > uf.sz[y])swap(x,y);
        uf.par[x] = y;
        s.insert(y);
        s.erase(x);
        uf.sz[y] += uf.sz[x];
        ma = max(ma,uf.sz[y]);
        tell(s.size(),ma);
    }

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