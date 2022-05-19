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
int inf = 1e18;
void solve(){
    int n,k;
    cin >> n >> k;
    vi ac(n),t(n);
    vi A(k);
    rep(i,0,k){
        int a;
        cin >> a;
        --a;
        A[i] = a;
        ac[a] = 1;
    }
    rep(i,0,k){
        int a;
        cin >> a;
        t[A[i]] = a;
    }
    sort(all(A));
    vi pre(n,inf),suf(n,inf);
    int val = 0;
    rep(i,A.front(),n){
        if(i == A.front()){
            val = t[A.front()];
            pre[i] = val;
            ++val;
            continue;
        }
        if(ac[i]){
            if(t[i] < val){
                val = t[i];
                pre[i] = val;
            }
            else pre[i] = val;
        }
        else pre[i] = val;
        ++val;
    }
    for(int i = A.back();i >= 0;--i){
        if(i == A.back()){
            val = t[A.back()];
            suf[i] = val;
            ++val;
            continue;
        }
        if(ac[i]){
            if(t[i] < val){
                val = t[i];
                suf[i] = val;
            }
            else suf[i] = val;
        }
        else suf[i] = val;
        ++val;
    }
    rep(i,0,n)cout << min(suf[i],pre[i]) << " ";
    ln;
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
