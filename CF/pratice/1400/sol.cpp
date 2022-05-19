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

long solve(string s){
    int n = s.size();
    vector<int> dp(n);
    vector<int> cnt(n + 1),zcnt(n + 1);
    rep(i,1,n + 1){
        cnt[i] += cnt[i - 1] + (s[i - 1] == '1');
        zcnt[i] += zcnt[i - 1] + (s[i - 1] == '0'); 
    }
   //  dbg(dp);
    dbg(cnt);
    dbg(zcnt);
    stack<int> one,z;
    if(s.front() == '0'){
        dp[0] = 0;
        z.push(0);
    }
    else{
        dp[0] = 1;
        one.push(0);
    }
    rep(i,1,n){
        // if(s[i] == '0')continue;
        dp[i] = 1;
        while(!one.empty() && cnt[i + 1] - cnt[one.top()] > zcnt[i + 1] - zcnt[one.top()]){
            dbg(one.top());
            if(cnt[i + 1] - cnt[one.top()] > zcnt[i + 1] - zcnt[one.top()] + 1)dp[i] += 2 * dp[one.top()];
            else dp[i] += dp[one.top()];
            one.pop();
        }
        while(!z.empty() && cnt[i + 1] - cnt[z.top()] > zcnt[i + 1] - zcnt[z.top()]){
            dbg(i,z.top(),cnt[i + 1] - cnt[z.top()],zcnt[i + 1] - zcnt[z.top()]);
            // dbg(one.top());
            if(cnt[i + 1] - cnt[z.top()] > zcnt[i + 1] - zcnt[z.top()] + 1)dp[i] += 2 * dp[z.top()];
            else dp[i] += dp[z.top()];
            z.pop();
        }
        if(s[i] == '1')one.push(i);
        else z.push(i);
    }
    dbg(dp);
    return dp.back();   
}

void solve(){
    string s;
    cin >> s;
    cout << solve(s);ln;
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
