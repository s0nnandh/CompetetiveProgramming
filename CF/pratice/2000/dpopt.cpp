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

ll inf = 4e8 + 1;

void solve(){
    
    int n[4];
    cin >> n[0] >> n[1] >> n[2] >> n[3];
    vector<vector<ll>> c(4);
    rep(i,0,4){
        rep(j,0,n[i]){
            ll a;
            cin >> a;
            c[i].pb(a);
        }
    }
    vector<vector<vector<int>>> dont(3);
    vector<vector<ll>> dp(4);
    dp[0] = c[0];
    rep(i,0,3){
        int m;
        cin >> m;
        dont[i].resize(n[i + 1]);
        rep(I,0,m){
            int a,b;
            cin >> a >> b;
            --a;--b;
            dont[i][b].pb(a);
        }
    }
    rep(i,0,3){
        dp[i + 1].resize(n[i + 1]);
        multiset<int> s;
        rep(j,0,n[i])s.insert(dp[i][j]);
        rep(j,0,n[i + 1]){
            for(auto x : dont[i][j])s.erase(s.find(dp[i][x]));
            dp[i + 1][j] = (s.size() == 0 ? inf : c[i + 1][j] + *s.begin());
            for(auto x : dont[i][j])s.insert(dp[i][x]);
        }
    }
    ll ans = *min_element(all(dp[3]));
    cout << (ans >= inf ? -1 : ans);ln;
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
