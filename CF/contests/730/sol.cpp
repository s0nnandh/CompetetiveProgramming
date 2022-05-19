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
long double eps = 1e-9;
long double f(long double c,long double m,long double p,long double v){    
    double ans = 0;
    ans += p;
    if(c == 0.0 && m == 0.0)return ans;
    int x = 2;
    if(c <= eps || m <= eps)--x;
    // dbg(c,m,p,v,x);
    // assert(c + m + p == 1.0);
    long double take = min(c,v);
    if(c > eps){
        ans += c * (1 + f(c - take,m <= eps ? 0 : m + (take / x),p + (take / x),v));
    }
    take = min(m,v);
    if(m > eps){
        ans += m * (1 +  f(c <= eps ? 0 : c + (take / x),m - take,p + (take / x),v));
    }
    return ans;
}

void solve(){
    long double c,m,p,v;
    cin >> c >> m >> p >> v;
    cout << setprecision(12) << fixed;
    cout << f(c,m,p,v);ln;
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
