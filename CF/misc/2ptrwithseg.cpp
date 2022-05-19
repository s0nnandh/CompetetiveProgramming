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
void _dbg() {cerr << " ]" << endl;}
template <class T, class... V>void _dbg(T t, V... v) {__dbg(t); if (sizeof...(v)) cerr << ", "; _dbg(v...);} 
#ifdef _DEBUG
#define dbg(x...) cerr << "[" << #x << "] = [ "; _dbg(x)
#else
#define dbg(x...)
#endif 
struct SegTree{
    SegTree *left,*right;
    int lo,hi;
    ll g;
    SegTree(){

    }
    ll f(ll a,ll b){
        if(a == 0 || b == 0)return max(a,b);
        return gcd(a,b);
    }
    void recal(){
        // dbg(left -> g,right -> g);
        g = f(left -> g,right -> g);
    }
    SegTree(int l,int r,vector<ll> &v){
        lo = l,hi = r;
        if(lo == hi){            
            g = v[l];
            // dbg(g);
        }
        else{
            int mid = (hi + lo) / 2;
            left = new SegTree(lo,mid,v);
            right = new SegTree(mid + 1,hi,v);
            recal();
        }        
    }
    ll ask(int l,int r){
        // dbg(g);
        if(lo > r || hi < l)return 0;
        if(l <= lo && r >= hi)return g;
        return f(left -> ask(l,r),right -> ask(l,r));
    }

};
void solve(){
    int n;
    cin >> n;
    vl v(n);
    for(auto &i : v)cin >> i;
    // dbg(v);
    int l = 0,r = 0;
    SegTree *st = new SegTree(0,n - 1,v);
    int inf = 1e9,ans = inf;
    for(;r < n;++r){
        while(l + 1 <= r && st -> ask(l + 1,r) == 1)++l;
        // dbg(l,r,st -> ask(l,r));
        if(st -> ask(l,r) == 1)ans = min(ans,r - l + 1);
    }
    cout << (ans == inf ? -1 : ans) << "\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL); 
    // gen_factorial(1e6);  	
    int test=1;
    // cin>>test;   
    while(test--)
        solve();
    return 0;
}
