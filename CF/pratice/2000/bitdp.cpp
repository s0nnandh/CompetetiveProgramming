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
    int primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53};
    int n;
    cin >> n;
    vector<int> v(n);
    for(auto &i : v)cin >> i;
    vector<int> msk(60);
    // find masks of all the possible values
    for(int i = 1;i <= 58;++i){
        for(int j = 0;j < 16;++j){
            if(i % primes[j] == 0)msk[i] |= (1 << j);
        }
    }    
    int inf = 123456789;
    vector<vector<int>> dp(n + 1,vector<int> ((1 << 16),inf)); // to store all possible subsets with primes
    for(int i = 0;i < n;++i){
        
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

