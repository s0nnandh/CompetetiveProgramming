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
#define len(x) (int)x.size()
#define all(x) x.begin(),x.end()
#define vi vector<int>
#define vl vector<ll>

ll inf = 1e18;
void solve(){
    
    int n,m;
    cin >> n >> m;
    vector<vl> d(n,vl (n,inf));
    rep(i,0,m){
        int a,b,c;
        cin >> a >> b >> c;
        --a;--b;
        d[a][b] = c;
    }
    rep(i,0,n)d[i][i] = 0;
    ll ans = 0;
    for(int k = 0;k < n;++k){
        for(int i = 0;i < n;++i){
            for(int j = 0;j < n;++j){
                d[i][j] = min(d[i][j],d[i][k] + d[k][j]);
                ans += ((d[i][j] == inf) && k > ? 0 : d[i][j]);
            }
        }
    }
    
    rep(i,0,n)rep(j,0,n)ans += (d[i][j] == inf ? 0 : d[i][j]);
    cout << ans;ln;
}   

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL); 
    // gen_factorial(1e6);  	
    int test=1;
	// cin>>test;   
    while(test--)
        solve();
    return 0;
}
