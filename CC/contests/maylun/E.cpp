#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ln cout<<"\n"
using namespace std;
#define rep(i,s,n) for(ll i = (s);i<(n);++i)
#define pc(x) __builtin_popcount(x)
void DBG() {
	cerr << "]" << endl;
}
template<class H, class... T> void DBG(H h, T... t) {
    //cerr << '[' << endl;
	cerr << to_string(h);
	if(sizeof...(t))
		cerr << ", ";
	DBG(t...);
}
#ifdef _DEBUG
#define dbg(...) cerr << "LINE(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)
#else
#define dbg(...) {}
#endif

#define pi pair<int,int>
#define pl pair<ll,ll> 
#define fr first
#define sc second
#define pb push_back
#define gcd(a,b) __gcd(a,b)

vector<vector<int>> adj;
vector<pl> dp;
string s;

void dfs(int par,int u){
    int cnt = 0;
    for(auto x : adj[u]){
        if(x == par)continue;
        ++cnt;
        dfs(u,x);
        if(s[u] == '1'){
            dp[u].fr = max(dp[u].fr,1 + dp[x].fr);
            dp[u].sc += dp[x].sc;
        }
        else{
            dp[u].fr = max(dp[u].fr,dp[x].fr);
            dp[u].sc += dp[x].sc;
        }
    }
    if(cnt == 0 && s[u] == '1'){
        dp[u] = {1,0};
    }
    else if(s[u] == '0')dp[u].sc += dp[u].fr; 
    // dbg(u,dp[u].fr,dp[u].sc);
}

void solve(){
    
    int n;
    cin >> n;
    adj.resize(n);
    dp.resize(n);
    cin >> s;
    rep(i,1,n){
        int p;
        cin >> p;
        --p;
        adj[p].pb(i);
        adj[i].pb(p);
    }
    dfs(-1,0);
    cout << dp[0].sc;ln;
    rep(i,0,n)adj[i].clear();
    adj.clear();
    dp.clear();
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL); 
    //gen_factorial(1e6);  

    int test=1;
    cin>>test;   
    while(test--)
        solve();
    return 0;
}