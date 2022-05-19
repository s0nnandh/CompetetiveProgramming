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

void solve(){
    int n,m;
    cin >> n >> m;
    vector<vector<int>> v(n,vector<int> (m));
    vector<vector<ll>> ans(n,vector<ll> (m));
    for(auto &i : v)for(auto &j : i)cin >> j;
    for(int i = 0;i < m;++i){
        ll sum = 0;
        for(int j = 0,k = i;j < n && k < m;++j,++k)sum += v[j][k];
        for(int j = 0,k = i;j < n && k < m;++j,++k)ans[j][k] += sum;
    }
    for(int i = 1;i < n;++i){
        ll sum = 0;
        for(int j = i,k = 0;j < n && k < m;++j,++k)sum += v[j][k];
        for(int j = i,k = 0;j < n && k < m;++j,++k)ans[j][k] += sum;
    }
    for(int i = 0;i < n;++i){
        ll sum = 0;
        for(int j = 0,k = i;k >= 0 && j < m;++j,--k)sum += v[k][j];
        for(int j = 0,k = i;k >= 0 && j < m;++j,--k)ans[k][j] += sum;
    }
    for(int i = 1;i < m;++i){
        ll sum = 0;
        for(int j = i,k = n - 1;k >= 0 && j < m;++j,--k)sum += v[k][j];
        for(int j = i,k = n - 1;k >= 0 && j < m;++j,--k)ans[k][j] += sum;
    }

    ll mx = 0;
    for(int i = 0;i < n;++i)for(int j = 0;j < m;++j)mx = max(ans[i][j] - v[i][j],mx);
    cout << mx << '\n';
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