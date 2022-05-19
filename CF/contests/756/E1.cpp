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
    int n,m;
    cin >> n >> m;
    queue<int> q;
    vector<int> v(n + 1);
    vector<vector<int>> g(n + 1);
    for(int i = 0;i < m;++i){
        int x;
        cin >> x;
        q.push(x);
        v[x] = x;
    }
    for(int i = 0;i < n - 1;++i){
        int a,b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    q.push(1);
    v[1] = 1;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(auto x : g[u]){
            if(v[x] == 0){
                if(g[x].size() == 1 && v[u] == 1){
                    cout << "YES" << "\n";
                    return;
                }
                q.push(x);
                v[x] = v[u];
            }
        }
    }   
    cout << "NO" << "\n";
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
