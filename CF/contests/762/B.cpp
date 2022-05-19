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

vector<vector<int>> dx = {{1,0},{-1,0},{0,1},{0,-1}};

void solve(){   
    int n,m;
    cin >> n >> m;
    vector<vector<int>> d(n + 1,vector<int> (m + 1,-1));
    queue<pi> q;
    vector<int> a,b;
    if(n&1)a.push_back((n + 1) / 2);
    else{
        a.push_back(n / 2);
        a.push_back((n / 2) + 1);
    }
    if(m&1){
        b.push_back((m + 1) / 2);
    }
    else{
        b.push_back(m / 2);
        b.push_back((m / 2) + 1);
    }
    for(auto x : a){
        for(auto y : b){
            q.push({x,y});
            d[x][y] = 1;
        }
    }
    while(!q.empty()){
        pi p = q.front();
        q.pop();
        int x = p.first,y = p.second;
        for(int k = 0;k < 4;++k){
            int nx = x + dx[k][0],ny = y + dx[k][1];
            if(nx == 0 || ny == 0 || nx > n || ny > m)continue;
            if(d[nx][ny] == -1){
                d[nx][ny] = 1 + d[x][y];
                q.push({nx,ny});
            }
        }
    }
    map<int,int> mp;
    for(int i = 0;i <= n;++i){
        for(int j = 0;j <= m;++j){
            if(d[i][j] != -1){
                mp[d[i][j]]++;
            }
        }
    }
    vector<int> ans;
    for(auto x : mp){
        ans.push_back(x.second);
    }
    int now = (n / 2) + (m / 2);
    for(auto x : ans){
        for(int i = 0;i < x;++i)cout << now << " ";
        ++now;
    }
    cout << '\n';
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