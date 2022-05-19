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

vector<pair<long long,int>> pff(long long n){    
    vector<pair<long long,int>> fac;
    long long cnt=0;
    while (n % 2 == 0)
    {
        cnt++;
        n = n/2;
    }
    if(cnt!=0)
    fac.push_back({2,cnt});


    for (long long i = 3; i * i <= n; i = i + 2)
    {
        cnt=0;
        if(n==1)break;
        while (n % i == 0)
        {
            cnt++;
            n = n/i;
        }
            if(cnt!=0)
                fac.push_back({i,cnt});
    }
    if (n > 2)
        fac.push_back({n,1});
    
    return fac;
}

void solve(){
    int n,q;
    cin >> n >> q;
    vector<int> v(n);
    for(auto &i : v)cin >> i;
    vector<int> jump(n + 1,n);
    int nx = 1e5;   
    vector<int> prime(nx + 1,n);
    for(int i = n - 1;i >= 0;--i){
        auto fac = pff(v[i]);
        int go = n;
        for(auto &x : fac){
            go = min(go,prime[x.fr]);
            prime[x.fr] = i;
        }
        jump[i] = min(go,jump[i + 1]);
    }
    vector<vector<int>> dp(n + 1,vector<int> (21));
    for(int i = 0;i < 21;++i)dp[n][i] = n;
    for(int i = 0;i < n;++i)dp[i][0] = jump[i];
    for(int i = 1;i < 21;++i){
        for(int j = 0;j < n;++j){            
            dp[j][i] = dp[dp[j][i - 1]][i - 1];
        }
    }
    for(int i = 0;i < q;++i){
        int l,r;
        cin >> l >> r;
        --l;--r;
        int ans = 1;
        for(int j = 20;j >= 0;--j){
            if(dp[l][j] <= r){
                l = dp[l][j];
                ans += (1 << j);
            }
        }
        cout << ans << '\n';
    }

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

