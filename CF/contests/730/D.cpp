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

#define ld  long double 

map<tuple<ld,ld,ld>,ld>  mp;

ld dp(ld c,ld m,ld p,ld v){
    if(p == 0)return 0.0;
    if(c == 0 && m == 0)return 1.0;
    if(c == 0){
        if(m > v && p > v){
            dp[{c,m,p}] = m * (1 + dp(0,m - v,p + v,v)) + p * (1 + dp(0,m + v,p - v,v));
            return dp[{c,m,p}];
        }
        else if(m <= v && c > )
    }
    if(c <= v && m > v && p > v){
        mp[{c,m,p}] = c * (1 + dp(0,m + (c / 2),p + (c / 2),v)) + m * (1 + dp(c + (v / 2),m - v,p + (v / 2),v)) + p * (1 + dp(c + (v/2),m + (v / 2),p - v,v));
        return mp[{c,m,p}];
    }
    else if(c > v && m <= v && p > v){
        mp[{c,m,p}] = c * (1 + dp(c - v,m + (v / 2),p + (v / 2),v)) + m * (1 + dp(c + (m / 2),0,p + (m / 2),v)) + p * (1 + dp(c + (v / 2),m + (v / 2),p - v,v));
        return mp[{c,m,p}];
    }
    else if(c > v && m > v && p <= v){
        mp[{c,m,p}] = c * (1 + dp(c - v,m + (v / 2),p + (v / 2),v)) +  m * (1 + dp(c + (v / 2),m - v,p + (v / 2),v)) + p * (1 + dp(c + (p / 2),m + (p / 2),0,v));
        return mp[{c,m,p}];
    }  
    else{
        mp[{c,m,p}] = c * (1 + dp(c - v,m + (v / 2),p + (v / 2),v)) + m * (1 + dp(c + (v / 2),m - v,p + (v / 2),v)) + p * (1 + dp(c + (v/2),m + (v / 2),p - v,v));
        return mp[{c,m,p}];
     }   
}

void solve(){
    long double c,m,p,v;
    cin >> c >> m >> p >> v;

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
