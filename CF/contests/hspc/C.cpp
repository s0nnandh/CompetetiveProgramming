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
void solve(){
    string s;
    cin >> s;
    string a = s;
    // a win b lose
    for(int i = 0;i < 10;++i){
        if(i % 2 == 0 && s[i] == '?'){
            a[i] = '1';
        }
        else if(i&1 && s[i] == '?'){
            a[i] = '0';
        }
    }
    int ans = 10;
    auto go = [&](){
        int ca = 5,cb = 5;
        int ga = 0,gb = 0;
        for(int i = 0;i < 10;++i){
            if(i % 2 == 0){
                ga += a[i] == '1';
                --ca;
            }
            else if(i&1){
                gb += a[i] == '1';
                --cb;
            }
            if(ga > cb + gb || gb > ca + ga){
                ans = min(ans,i + 1);
                return;
            }
        }
    };
    go();
    a = s;
    // a lose b win
    for(int i = 0;i < 10;++i){
        if(i % 2 == 0 && s[i] == '?'){
            a[i] = '0';
        }
        else if(i&1 && s[i] == '?'){
            a[i] = '1';
        }
    }
    go();
    cout << ans;ln;
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
