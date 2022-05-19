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
    string s;
    cin >> s;
    vector<int> cnt(26);
    int n = s.size();
    rep(i,0,n)cnt[s[i] - 'a']++;
    vector<pi> p;
    set<int> se;
    rep(i,0,26){
        if(cnt[i]){
            se.insert(cnt[i]);
            p.emplace_back(cnt[i],i);
        }
    }
    if(*se.begin() == 1){
        // dbg(s);
        rep(i,0,26){
            if(cnt[i] == 1){
                --cnt[i];
                cout << char('a' + i);
                break;
            }
        }
        rep(i,0,26){
            while(cnt[i]){
                cout << char('a' + i);
                --cnt[i];
            }
        }
        ln;
        return;
    }
    int prev = 0;
    rep(i,0,26){    
        if(cnt[i]){
            --cnt[i];
            prev = i;
            cout << char('a' + i);
            break;
        }
    }
    rep(i,0,n){
        if(cnt[i] && i == prev)continue;
        if(cnt[i]){
            while(cnt[i]){
                cout << char('a' + i);
                --cnt[i];
            }
            break;
        }
    }
    rep(i,0,26){
        while(cnt[i]){
            cout << char('a' + i);
            --cnt[i];
        }
    }
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