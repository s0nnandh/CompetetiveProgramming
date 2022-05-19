#include<bits/stdc++.h>
#define ll long long
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
#define dbg(...) cerr << "" << endl
#endif

#define pi pair<int,int>
#define pl pair<ll,ll> 
#define fr first
#define sc second
#define pb push_back
#define gcd(a,b) __gcd(a,b)
#define sz(x) (int)x.size()
#define all(x) x.begin(),x.end()
#define vi vector<int>
#define vl vector<ll>

vector<vector<int>> adj;
vector<int> d;
int dfs(int u,int par){
    int val = 0;
    if(par != -1)d[u] = 1 + d[par];
    val = d[u];
    for(auto x : adj[u]){
        if(x == par)continue;
        val = max(val,dfs(x,u));
        // val = max(val,d[x]);
    }  
    return val; 
}
void solve(){
    int n,k;
    cin >> n >> k;
    adj.resize(n);
    d.resize(n);
    rep(i,1,n){
        int a;
        cin >> a;
        --a;
        adj[a].pb(i);
        adj[i].pb(a);
    }
    if(k % n == 0){
        cout << 2 *(k/n) - 1;
        ln;
    }
    else {
        int ans = 2 *(k/n + 1) - 1;
        int val = dfs(0,-1);
        // dbg(val, k % n);
        if(k % n > val)ans++;
        cout << ans;ln;
    }
    adj.clear();
    d.clear();
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
