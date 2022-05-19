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
    int W,L;
    cin >> W >> L;
    set<int> ans;
    ans.insert(1);
    for(ll x = 1;x * x <= W;++x){
        if(W % x == 0){
            int h = W / x;
            if((L - 2) % x == 0){
                ans.insert(x);
            }
            else if((L - 1) % x == 0 && (W - 2) % x == 0)ans.insert(x);
            if((L - 2) % h == 0){
                ans.insert(h);
            }
            else if((L - 1) % h == 0 && (W - 2) % h == 0)ans.insert(h);
        }
    }
    for(ll x = 1;x * x <= W - 1;++x){
        
        if((W - 1) % x == 0){
            int h = (W - 1) / x;
            if((L - 1) % x == 0)ans.insert(x);
            else if(L % x == 0 && (L - 2) % x == 0)ans.insert(x);
            if((W - 1) % h == 0){
            if((L - 1) % h == 0)ans.insert(h);
            else if(L % h == 0 && (L - 2) % h == 0)ans.insert(h);
        }
        }
        
    }
    for(ll x = 1;x * x <= W - 2;++x){
        int h = (W - 2) / x;
        if((W - 2) % x == 0){
            if(L % x == 0)ans.insert(x);
            if((W - 2) % h == 0){
                if(L % h == 0)ans.insert(h);
            }
        }
        
    }
    cout << ans.size();
    for(auto x : ans)cout << " " << x;
    cout << "\n"; 
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