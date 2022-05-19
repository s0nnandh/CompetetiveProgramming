#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ln cout<<"\n"
#define pc(x) __builtin_popcount(x)
#define rep(i,s,n) for(ll i = (s);i<(n);++i)
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
template<class T,class V>void __dbg(const pair<T, V> &x) {cerr << "{ "; __dbg(x.first); cerr << ','; __dbg(x.second); cerr << "}";}
void __dbg(bool x) {cerr << (x ? "true" : "false");} 
template<class T>void __dbg(const T &x) {int f = 0; cerr << "{ "; for (auto &i: x) cerr << (f++ ? "," : ""), __dbg(i); cerr << "}";}
void _dbg() {cerr << " ]" << endl;}
template <class T, class... V>void _dbg(T t, V... v) {__dbg(t); if (sizeof...(v)) cerr << ", "; _dbg(v...);} 
#ifdef _DEBUG
#define dbg(x...) cerr << "[" << #x << "] = [ "; _dbg(x)
#else
#define dbg(x...)
#endif 

void solve(){
    int n;
    cin >> n;
    vector<ll> v(n);
    for(auto &i : v)cin >> i;
    int mx = 20;
    vector<vector<ll>> m(n,vector<ll> (mx + 1)),g(n,vector<ll> (mx + 1));
    for(int i = 0;i < n;++i){
        m[i][0] = g[i][0] = v[i];
    }
    for(int j = 1;j <= mx;++j){
        for(int i = 0;i + (1 << j) - 1 < n;++i){
            m[i][j] = min(m[i][j-1],m[i + (1 << (j - 1))][j - 1]);
            g[i][j] = gcd(g[i][j-1],g[i + (1 << (j - 1))][j - 1]);
        }
    }
    auto gq = [&](int l,int r){
        int k = 31 - __builtin_clz(r - l  +1);
        return gcd(g[l][k],g[r - (1 << k) + 1][k]);
    };
    auto mq = [&](int l,int r){
        int k = 31 - __builtin_clz(r - l  +1);
        return min(m[l][k],m[r - (1 << k) + 1][k]);
    };
    int l = 1,r = n;
    auto ok = [&](int x){
        int k = 31 - __builtin_clz(x);
        for(int i = 0;i + x - 1 < n;++i){
            if(gcd(g[i][k],g[i + x - (1 << k)][k]) == min(m[i][k],m[i + x - (1 << k)][k]))return 1;
        }
        return 0;
    };
    int mid = 0,Ans = 0;
    while(l <= r){
        mid = (l + r) / 2;
        if(ok(mid)){
            l = mid + 1;
            Ans = mid;
        }
        else r = mid - 1;
    }
    vector<int> ans;
    mid = Ans;
    for(int i = 0;i + mid - 1 < n;++i){
        if(gq(i,i + mid - 1) == mq(i,i + mid - 1))ans.push_back(i + 1);
    }
    cout << ans.size() << " " << mid - 1 << "\n";
    for(auto x : ans)cout << x << " ";
    cout << "\n";

    
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL); 
    int test = 1;
    // cin >> test;
    while(test--)solve();
        // gen_factorial(1e6); 
    return 0;
}

