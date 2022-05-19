#include<bits/stdc++.h>
#include<stdio.h>
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
#define dbg(...) cerr << "" << endl
#endif

#define pi pair<int,int>
#define pl pair<ll,ll> 
#define fr first
#define sc second
#define pb push_back
#define gcd(a,b) __gcd(a,b)
const int nx = 1e5 + 5;
vector<int> adj[nx];
vector<int> from[nx];
ll dp[nx];
int in[nx];
int seen[nx];
vector<int> t;
ll mod = 1e9 + 7;
void solve(){
    int n,m;
    cin >> n >> m;
    rep(i,0,n){
        dp[i] = 0;
        seen[i] = in[i] = 0;
    }
    //dp[0] = 1;
    rep(i,0,m){
        int a,b;
        cin >> a >> b;
        --a;--b;
        adj[a].pb(b);
        from[b].pb(a);
        in[b]++;
    }
    queue<int> q;
    rep(i,0,n){
        if(in[i] == 0){
            q.push(i);
            // dp[i] = 1;
        }
    }
    dp[0] = 1;
    while(!q.empty()){
        int u = q.front();
        t.pb(u);
        q.pop();
        for(auto x : adj[u]){
            seen[x]++;
            if(seen[x] == in[x]){
                for(auto y : from[x]){
                    // dbg(y,x);
                    dp[x] = (dp[x] + dp[y]) % mod;
                }
                q.push(x);
            }
        }
    }
    // for(auto x : t)cout << x << " ";
    // ln;
    cout << dp[n-1];ln;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL); 
    //gen_factorial(1e6);   
    int test=1;
    // cin>>test;   
    while(test--)
        solve();
    return 0;
}