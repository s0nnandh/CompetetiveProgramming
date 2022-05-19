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
    string s;
    cin >> s;
    vector<char16_t> v = {'a','b','c'};
    vector<vi> pre(6,vector<int> (n + 1));
    int ptr =  0;
    do
    {
        int j = 0;
        for(int i = 1;i <= n;++i){
            pre[ptr][i] = s[i - 1] != v[j++];
            if(j == 3)j = 0;
        }
        ++ptr;
    } while(next_permutation(all(v)));
    rep(i,0,6){
        rep(j,1,n + 1){
            pre[i][j] += pre[i][j - 1];
        }
    }
    rep(i,0,m){
        int l,r;
        cin >> l >> r;
        int ans = r - l + 1;
        for(auto &x : pre)ans = min(ans,x[r] - x[l - 1]);
        cout << ans;ln;
    }        
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL); 	
    int test=1;
    // cin>>test; 
    while(test--)
        solve();
    return 0;
}