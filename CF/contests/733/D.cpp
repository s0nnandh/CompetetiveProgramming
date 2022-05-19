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
#define int long long
void solve(){
    int n;
    cin >> n;
    vector<bool> d(n + 1);
    vector<int> b(n + 1,-1);
    vector<int> a(n + 1);
    rep(i,1,n + 1)cin >> a[i];
    int ans = 0;
    vector<int> pos(n + 1);
    rep(i,1,n + 1){
        if(d[a[i]] == 0){
            ++ans;
            pos[a[i]] = i;
            b[i] = a[i];
            d[a[i]] = 1;
        }
    }
    vector<int> v;
    rep(i,1,n + 1){
        if(d[i] == 0)v.pb(i);
    }
    reverse(all(v));
    // dbg(pos);
    int j = 0;
    rep(i,1,n + 1){
        if(b[i] == -1){
            if(v[j] == i){
                int p = pos[a[i]];
                b[i] = b[p];
                b[p] = v[j];
                pos[a[i]] = i;
            }
            else b[i] = v[j];
            ++j;
        }
    }
    cout << ans;ln;
    rep(i,1,n + 1)cout << b[i] << " ";
    ln;
}    

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL); 
    int test=1;
    cin>>test;   
    while(test--)
        solve();
    return 0;
}