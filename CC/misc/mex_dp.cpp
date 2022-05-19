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

ll mod = 1e9 + 7;

void solve(){
    int n;
    cin >> n;
    vector<int> v(n);
    vector<bool> see(n + 1);
    for(int &i : v){
        cin >> i;
        see[i] = 1;
    }
    int mex = n;
    for(int i = 0;i <= n;++i){
        if(!see[i]){
            mex = i;
            break;
        }
    }
    vector<int> best_valid(n,-1); // best start point 
    set<pi> s;
    bool ok = 0;
    vector<int> have_seen(n,-1);
    for(int i = 0;i < n;++i){
        if(v[i] < mex){
            if(have_seen[v[i]] != -1){
                s.erase({have_seen[v[i]],v[i]});
            }
            s.insert({i,v[i]});
            have_seen[v[i]] = i;
        }
        if(len(s) == mex)ok = 1;
        if(ok){
            if(s.size() == 0)best_valid[i] = i;
            else best_valid[i] = (*s.begin()).first;
        }
    }
    /*
            my dp[i] is the number of ways to divide into sub arrays such that the last sub-array ends at i 
            dp[i] += dp[best_valid[i]] + dp[best_valid[i] - 1] + ... + dp[0]

    */

    vector<ll> dp(n + 1),pref(n + 1);

    for(int i = 0;i < n;++i){
        if(i - 1 >= 0)pref[i] = ( pref[i] + pref[i - 1] ) % mod;
        int x = best_valid[i];
        if(x == 0){
            dp[i] = 1;
        }
        else if(x > 0){
            dp[i] = ( 1 + pref[x - 1] ) % mod;
        }
        pref[i] = ( pref[i] + dp[i] ) % mod;
    }

    cout << dp[n - 1] << "\n";
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
