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

#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct Fenwick{   // 1 - indexed Fenwick tree
    int n;
    vector<ll> bit;  

    Fenwick(int nn){
        this -> n = nn;
        bit.resize(nn + 1);
    }
    void add(ll x,int i){
        while(i <= n){
            bit[i] += x;
            i += i & (-i);
        }
    }
    ll get(int i){
        ll sum = 0;
        while(i > 0){
            sum += bit[i];
            i -= i & (-i);
        }  
        return sum; 
    }
    ll query(int l,int r){
        return get(r) - get(l-1);
    }
};

void solve(){
    int n;
    cin >> n;
    vector<int> v(n);
    Fenwick B(n),C(n);
    for(auto &i : v){
        cin >> i;
    }
    long long ans = 0;
    for(int i = 0;i < n;++i){
        for(int j = i + 1;j < n;++j)B.add(1,v[j]);
        for(int j = i + 1;j < n;++j){
            B.add(-1,v[j]);
            int x = B.get(v[i]);
            int y = C.get(v[j]);
            ans += (long long) x * y;
        }
        C.add(1,v[i]);
    }
    cout << ans << '\n';
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