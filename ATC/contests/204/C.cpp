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
#define all(x) x.begin(),x.end()

vector<vector<int>> adj;


void dfs(int u,int &sum,vector<bool> &v){
    if(!v[u]){
        ++sum;
        v[u] = 1;
        for(auto x : adj[u]){
            if(!v[x])dfs(x,sum,v);
        }
    }
}

void solve(){   
   
    int n,m;
    cin >> n >> m;
    adj.resize(n);
    
    rep(i,0,m){
        int a,b;
        cin >> a >> b;
        --a;--b;
        adj[a].pb(b);
    }
    int ans = 0;
    rep(i,0,n){
        int s = 0;
        vector<bool> v(n);
        dfs(i,s,v);
        ans += s;
    }
    cout << ans << endl;

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