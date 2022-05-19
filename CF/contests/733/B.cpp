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
#define int long long
void solve(){
    int h,w;
    cin >> h >> w;
    vector<vector<int>> g1(h,vector<int> (w,-1)),g2(h,vector<int> (w,-1));
    int k1 = 0,k2 = 0;
    vector<vector<int>> p = {{-1,-1},{1,-1},{1,1},{-1,1},{0,-1},{0,1},{-1,0},{1,0}};
    rep(i,0,h){
        rep(j,0,w){
            if(i == 0 || j == 0 || i == h - 1 || j == w - 1){
                if(g1[i][j] == 0)continue;
                g1[i][j] = 1;
                k1++;
                rep(k,0,8){
                    int x = i + p[k][0];
                    int y = j + p[k][1];
                    if(x < 0 || y < 0 || x == h || y == w)continue;
                    g1[x][y] = 0;
                }
            }
        }
    }
    g2[0][0] = 0;
    rep(i,0,h){
        rep(j,0,w){
            if(g2[i][j] == 0)continue;
            k2++;
            rep(k,0,8){
                int x = i + p[k][0];
                int y = j + p[k][1];
                if(x < 0 || y < 0 || x == h || y == w)continue;
                g2[x][y] = 0;
            }
        }
    }
    rep(i,0,h){
        rep(j,0,w){
            if(g1[i][j] == -1)g1[i][j] = 0;
            if(g2[i][j] == -1)g2[i][j] = 0;
        }
    }
    if(k1 >= k2){
        for(auto x : g1){
            for(auto y : x)cout << y;
            ln;
        }
    }
    else{
        for(auto x : g1){
            for(auto y : x)cout << y;
            ln;
        }
    }
}    
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL); 
    int test=1;
    cin>>test;   
    while(test--)
        solve();
    return 0;
}