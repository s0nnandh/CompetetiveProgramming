#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ln cout<<"\n"
using namespace std;
//#define dbg(x) cout<<#x<<" = "<<x<<" "
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
#define dbg(...) cerr << "[ ]" << endl
#endif


#define pi pair<int,int>
#define pl pair<ll,ll> 
#define fr first
#define sc second
#define pb push_back

vector<ll> l,r;
vector<vector<int>> adj;


void dfs(int u,int par,vector<vector<ll>> &dp){
    for(auto x : adj[u]){
        if(x == par)continue;
        dfs(x,u,dp);
        // when setting to zero        
        dp[u][0] += max(abs(l[u] - r[x]) + dp[x][1],abs(l[u] - l[x]) + dp[x][0]);

        dp[u][1] += max(abs(r[u] - l[x]) + dp[x][0],abs(r[u] - r[x]) + dp[x][1]);
    }
}

void solve(){

    int n;
    cin >> n;
    l.resize(n);r.resize(n);
    adj.resize(n);
    rep(i,0,n){
        cin >> l[i] >> r[i];
    }
    rep(i,0,n-1){
        int a,b;
        cin >> a >> b;
        --a;--b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    vector<vector<ll>> dp(n,vector<ll> (2));
    dfs(0,-1,dp);
    cout << max(dp[0][0],dp[0][1]);ln;
    rep(i,0,n)adj[i].clear();
    adj.clear();
    l.clear();
    r.clear();
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

