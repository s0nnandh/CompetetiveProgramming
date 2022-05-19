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

const int mxN = 1e5 + 3;

vector<bool> prime(mxN,1);
vector<int> good(mxN);
void solve(){
    int n;
    cin >> n;
    vector<int> deg(n);
    vector<int> to(n - 1),from(n - 1);
    vector<vector<int>> g(n);
    for(int i = 0;i < n - 1;++i){
        int a,b;
        cin >> a >> b;
        --a;--b;
        g[a].push_back(b);
        g[b].push_back(a);
        from[i] = min(a,b);
        to[i] = max(a,b);
        deg[a]++;
        deg[b]++;
    }
    int mx = *max_element(all(deg));
    if(mx > 2){
        cout << -1 << "\n";
        return;
    }
    int leaf = 0;
    for(int i = 0;i < n;++i){
        if(deg[i] == 1){
            leaf = i;
            break;
        }
    }
    queue<pair<int,int>> q;
    vector<bool> vis(n);
    q.push({leaf,1});
    vis[leaf] = 1;
    map<pi,int> mp;
    while(!q.empty()){
        int u = q.front().first;
        int sw = q.front().second;
        q.pop();
        for(auto x : g[u]){
            if(!vis[x]){
                vis[x] = 1;
                mp[{min(x,u),max(x,u)}] = (sw ? 2 : 3);
                q.push({x,sw ^ 1});
            }
        }
    }
    for(int i = 0;i < n - 1;++i){
        cout << mp[{from[i],to[i]}] << " ";
    }
    cout << '\n';
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL); 
    // prime[0] = 0;
    // prime[1] = 0;
    // for(int i = 2;i < mxN;++i){
    //     for(int j = i * i;j < mxN;j += i)prime[j] = false;
    // }
    // for(int i = 3;i < mxN;++i){
    //     if(prime[i] && prime[i - 2])good[i - 2] = 1;
    // }
    int test=1;
    cin>>test;   
    while(test--)
        solve();
    return 0;
}