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

int INF = 1e9;

void build(ll t[], ll a[], int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = a[tl];
    } else {
        int tm = (tl + tr) / 2;
        build(t,a, v*2, tl, tm);
        build(t,a, v*2+1, tm+1, tr);
        t[v] = min(t[v*2],t[v*2+1]);
    }
}

void push(ll t[],ll lazy[],int v) {
    t[v*2] += lazy[v];
    lazy[v*2] += lazy[v];
    t[v*2+1] += lazy[v];
    lazy[v*2+1] += lazy[v];
    lazy[v] = 0;
}

void update(ll t[],ll lazy[],int v, int tl, int tr, int l, int r, ll addend) {
    if (l > r) 
        return;
    if (l == tl && tr == r) {
        t[v] += addend;
        lazy[v] += addend;
    } else {
        push(t,lazy,v);
        int tm = (tl + tr) / 2;
        update(t,lazy,v*2, tl, tm, l, min(r, tm), addend);
        update(t,lazy,v*2+1, tm+1, tr, max(l, tm+1), r, addend);
        t[v] = min(t[v*2], t[v*2+1]);
    }
}

ll query(ll t[],ll lazy[],int v, int tl, int tr, int l, int r) {
    if (l > r)
        return INF;
    if (l <= tl && tr <= r)
        return t[v];
    push(t,lazy,v);
    int tm = (tl + tr) / 2;
    return min(query(t,lazy,v*2, tl, tm, l, min(r, tm)), 
               query(t,lazy,v*2+1, tm+1, tr, max(l, tm+1), r));
}

void solve(){

    int n,s;
    cin >> n >> s;
    ll a[n],t[4 * n + 1],lazy[4 * n + 1],b[n];
    for(int i = 0;i <= 4 * n;++i)t[i] = lazy[i] = 0;
    pi ans = {-1,-1};
    for(int i = 0;i < n;++i){
        cin >> a[i];
        b[i] = a[i];
        if(a[i] + s >= 0)ans = {i,i};
    }
    for(int i = 1;i < n;++i)a[i] += a[i - 1];
    for(int i = 0;i < n;++i)a[i] += s;
    build(t,a,1,0,n - 1);
    int l = 0;
    for(int r = 0;r < n;++r){
        while(l < r && query(t,lazy,1,0,n - 1,l,r) < 0){
            update(t,lazy,1,0,n - 1,l + 1,n - 1,-b[l]);
            ++l;
        }
        if(query(t,lazy,1,0,n - 1,l,r) >= 0){
            if(ans.first == -1){
                ans = {l,r};
            }
            else if(ans.second - ans.first + 1 < r - l + 1){
                ans = {l,r};
            }
        }
    }
    if(ans.fr == -1){
        cout << -1;
    }
    else{
        cout << ans.fr + 1  << " " << ans.sc + 1 ;
    }
    cout << "\n";
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
