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
    int n,m;
    cin >> n >> m;
    vector<set<int>> g(n);
    vector<int> ok(n,1);
    int ans =  n;
    rep(i,0,m){
        int a,b;
        cin >> a >> b;
        --a;--b;
        g[a].insert(b);
        g[b].insert(a);
        if(ok[a] && g[a].lower_bound(a) != g[a].end()){
            ok[a] = 0;
            --ans;
        }
        if(ok[b] && g[b].lower_bound(b) != g[b].end()){
            ok[b] = 0;
            --ans;
        }
    }
    int q;
    cin >> q;
    rep(i,0,q){
        int typ;
        cin >> typ;
        if(typ == 3){
            cout << ans;ln;
        }
        else{
            int a,b;
            cin >> a >> b;
            --a;--b;
            if(typ == 1){
                g[a].insert(b);
                g[b].insert(a);
                if(ok[a] && g[a].lower_bound(a) != g[a].end()){
                    ok[a] = 0;
                    --ans;
                }
                if(ok[b] && g[b].lower_bound(b) != g[b].end()){
                    ok[b] = 0;
                    --ans;
                }
            }
            else{
                g[a].erase(b);
                g[b].erase(a);
                if(!ok[a] && g[a].lower_bound(a) == g[a].end()){
                    ok[a] = 1;
                    ++ans;
                }
                if(!ok[b] && g[b].lower_bound(b) == g[b].end()){
                    ok[b] = 1;
                    ++ans;
                }
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL); 
    // gen_factorial(1e6);  	
    int test=1;
    // cin>>test;   
    while(test--)
        solve();
    return 0;
}
