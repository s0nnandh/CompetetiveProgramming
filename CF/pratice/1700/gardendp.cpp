// https://codeforces.com/contest/467/problem/C

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
#define dbg(...) cerr << "[ ]" << endl
#endif


#define pi pair<int,int>
#define pl pair<ll,ll> 
#define fr first
#define sc second
#define pb push_back

void solve(){

	int n,m,k;
	cin >> n >> m >> k;
	vector<ll> v(n),pre(n + 1);
	for(auto &i : v)cin >> i;
	rep(i,1,n + 1){
		pre[i] = pre[i-1] + v[i-1];
	}
	// for(auto x : pre)cout << x << " ";
	// ln;
	vector<vector<ll>> dp(n + 1,vector<ll> (k + 1));
	rep(i,1,n + 1){
		rep(j,1,k+1){
			dp[i][j] = dp[i-1][j];
			if(i - m >= 0){
				// dbg(i,m,pre[i]-pre[i-m]);
				dp[i][j] = max(dp[i][j],pre[i]-pre[i-m] + dp[i-m][j-1]);
			}
		}
	}
	ll ans = 0;
	rep(i,0,n+1){
		ans = max(ans,dp[i][k]);
	}

	cout << ans;ln;

   
}       
 


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);    
    int test=1;
    // cin>>test;   
    while(test--)
        solve();
    return 0;
}

