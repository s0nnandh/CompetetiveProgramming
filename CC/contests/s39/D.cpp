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
    int n;
    cin >> n;
    string s;
    cin >> s;
    s += '#';
    vector<int> ans(n + 1);
    for(char x = 'a';x <= 'z';++x){
        int cnt = 0;
        vector<int> v;
        for(int i = 0;i < n;++i){
            cnt += s[i] == x;
            if(cnt && s[i] == x && s[i + 1] != x){
                v.push_back(cnt);
                cnt = 0;
            }
        }
        if(v.empty())continue;
        sort(all(v),greater<int>());
        int sum = 0;
        for(int j = 0;j <= n && j < (int)v.size();++j){
            sum += v[j];
            ans[j] = max(ans[j],sum);
        }
    }
    for(int i = 1;i <= n;++i)ans[i] = max(ans[i - 1],ans[i]);
    for(auto x : ans)cout << x << " ";
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