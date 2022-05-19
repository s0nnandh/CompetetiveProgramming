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

struct UF{
    vector<int> parl,parr, sz, color;
    UF() {}
    UF(int n):parl(n), parr(n), sz(n, 1), color(n,false) {
        for(int i=0; i<n; i++){
            parl[i]=i;
            parr[i] = i;
        } 
    }
    int findl(int x){
        if(parl[x]==x) return x;
        return parl[x]=findl(parl[x]);
    }
    int findr(int x){
        if(parr[x]==x) return x;
        return parr[x]=findr(parr[x]);
    }
    void unite(int x, int y){
        x=findl(x); y=findl(y);
        if(x==y) return;
        // if(sz[x]>sz[y]) swap(x, y);
        parl[x]=parl[y];
        parr[x] = parr[y];
        sz[y]+=sz[x];
        color[x] = color[y];
    }
    bool same(int x, int y){
        return findl(x)==findl(y);
    }
    int size(int x){
        return sz[findl(x)];
    }
};

void solve(){
    string s;
    int n;
    cin >> n >> s;
    char me = s[0];
    vector<int> v;
    int cnt = 1;
    set<pair<int,pi>> middle;
    for(int i = 1;i < n;++i){
        if(me != s[i]){
            v.push_back(cnt);
            cnt = 1;
            me = s[i];
        }
        else{
            ++cnt;
        }
    }
    v.push_back(cnt);
    UF tree(v.size());
    int start = me - '0',sz = (int)v.size();
    for(int i = 0;i < (int)v.size();++i){
        tree.sz[i] = v[i];
        tree.color[i] = start;
        start ^= 1;
        if(i && i != (int)v.size() - 1)middle.insert({v[i],{i,i}});
    }
    int ans = 0,bit = 0;
    for(int i = 0;i < (int)v.size();++i){
        v[i]&=1;
        if(bit && v[i]){
            bit = 0;
        }
        else if(bit && !v[i]){
            ++ans;
        }
        else if(!bit && v[i]){
            ++ans;
            bit = 1;
        }
    }
    cout << ans << " ";
    while(!middle.empty() && ans > 0){
        auto f = *(middle.begin());
        int num = f.fr,xl = f.sc.fr,xr = f.sc.sc;
        if(num > ans)break;
        ans -= num;
        assert(xl != 0 && xr != sz - 1);
        int l = tree.findl(xl - 1),r = tree.findr(xr + 1);
        middle.erase(middle.begin());
        if(l){
            middle.erase({tree.sz[l],{l,xl - 1}});
        }
        if(r != sz - 1){
            middle.erase({tree.sz[r],{xr + 1,r}});
        }
        tree.unite(xl,l);
        tree.unite(xr,r);
        if(l && r != sz - 1){
            middle.insert({tree.sz[l],{l,r}});
        }
    }
    int extra = 0;
    if(ans >= tree.sz[0]){
        ans -= tree.sz[0];
        ++extra;
    }
    if(ans >= tree.sz[sz - 1]){
        ++extra;
    }
    // assert(ans <= 1);
    int ans2 = 0;
    for(int i = 0;i < sz;++i){
        if(i < sz - 1)ans2 += tree.parl[i] == i;
        else ans2 += tree.parr[i] == i;
    }
    cout << ans2 - extra << '\n'; 
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);    
    int test=1;
    cin>>test;  
    while(test--){
        // cout << test << endl;
        solve();
    }
    return 0;
}