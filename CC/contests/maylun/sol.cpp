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


void solve(){
    
	int n,k;
	cin >> n >> k;
	vector<ll> v(n);
	for(auto &i : v)cin >> i;
	vector<vector<ll>> dp(n,vector<ll> (k + 1,-1e18)),pre(n,vector<ll> (k + 1,-1e18));
	dp[0][1] = v[0];
	// dp[0][0] = 0;
	pre[0][1] = v[0];
	// pre[0][0] = 0;
	// rep(i,2,k+1)dp[0][i] = 0;
	rep(i,0,n){
		dp[i][0] = 0;
		pre[i][0] = 0;
	}
	rep(i,1,n){
		rep(j,1,k + 1){
			if(i+1 >= j){
				// first transition 
				// we can include this element in the jth subarry
				dp[i][j] = max(dp[i][j],dp[i-1][j] + j * v[i]);
				// or we can start a new j th sub array from here
				dp[i][j] = max(dp[i][j],pre[i-1][j-1] + j * v[i]);

				//dp[i][j] = max(pre[i-1][j],dp[i-1][j]) + j * v[i];

				// dbg(dp[i][j],i,j);
				// update prefix
				pre[i][j] = max(pre[i-1][j],dp[i][j]);
			}
		}
	}
	ll ans = dp[n-1][k];
	rep(i,0,n)ans = max(ans,dp[i][k]);
	cout << ans;ln;
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