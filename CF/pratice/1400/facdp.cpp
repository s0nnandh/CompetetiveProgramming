// https://codeforces.com/contest/1512/problem/C

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
#define dbg(...) cerr << "" << endl
#endif

#define pi pair<int,int>
#define pl pair<ll,ll> 
#define fr first
#define sc second
#define pb push_back
#define gcd(a,b) __gcd(a,b)
#define sz(x) (int)x.size()

ll mod = 1e9 + 7;

void solve(){
	
	int n,k;
	cin >> n >> k;
	vector<vector<int>> factors(n + 1,vector<int> (1,1));
	for(int i = 2;i <= n;++i){
		for(int j = i;j <= n;j += i){
			factors[j].pb(i);
		}
	}
	vector<vector<ll>> dp(n + 1,vector<ll> (k + 1));
	rep(i,1,n + 1){
		dp[i][1] = 1;
	}
	for(int last = 1;last <= n;++last){
		for(int len = 2;len <= k;++len){
			for(auto x : factors[last]){
				dp[last][len] = (dp[last][len] + dp[x][len - 1]) % mod;
			}
		}
	}
	ll ans = 0;
	rep(i,1,n + 1){
		ans = (ans + dp[i][k]) % mod;
	}
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
