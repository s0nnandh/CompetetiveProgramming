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
string a;
string b;
int n,m;
void solve(){   
    cin >> a >> b;
    n = len(a);
    m = len(b);
    // left right
    for(int j = 0;j < m;++j){
        string t = b.substr(0,j + 1);
        // dbg(t);
        bool ok = 0;
        int l = len(t);
        int rpos = -1;
        for(int i = 0;i < n;++i){
            bool f = 1;
            for(int k = 0;k < l;++k){
                f &= (a[i + k] == t[k]);
            }
            if(f){
                rpos = i + l - 1;
                ok = 1;
                 int k = j + 1;
                --rpos;
                while(rpos >= 0 && k < m){
                    ok &= a[rpos] == b[k];
                    --rpos;
                    ++k;
                }
                if(ok && k == m){
                    cout << "YES";
                    ln;
                    return;
                }
            }
            ok = 0;
        }       
    }    
    cout << "NO";
    ln;   
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
