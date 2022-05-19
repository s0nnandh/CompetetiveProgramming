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

int inf = 2e9 + 1;

void solve(){
    int n;
    cin >> n;
    int L = inf,cost_L = inf;
    int R = 0,cost_R = inf;
    int ml = 0,mlc = inf;
    for(int i = 0;i < n;++i){
        int l,r,c;
        cin >> l >> r >> c;

        if(l < L){
            L = l,cost_L = c;
        }
        else if(l == L){
            cost_L = min(cost_L,c);
        }

        if(r > R){
            R = r,cost_R = c;
        }
        else if(r == R){
            cost_R = min(cost_R,c);
        }

        if(ml < r - l + 1){
            ml = r - l + 1,mlc = c;
        }
        else if(ml == r - l + 1){
            mlc = min(mlc,c);
        }

        int ans = cost_L + cost_R;
        if(ml == R - L + 1){
            ans = min(ans,mlc);
        }

        cout << ans << "\n";

    }
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