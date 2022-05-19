// https://codeforces.com/problemset/problem/788/A

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

void solve(){

	int n;
	cin >> n;
	vector<ll> v(n);
	for(auto &i : v)cin >> i;
	vector<vector<ll>> dp(n,vector<ll> (2));
	dp[n-1][0] = 0;dp[n-1][1] = 0;
	for(int i = n-2;i >= 0;--i){
		dp[i][1] = abs(v[i]-v[i+1]) - min(dp[i+1][0],0LL);
		dp[i][0] = abs(v[i]-v[i+1]) - max(dp[i+1][1],0LL);
	}	
	ll ans = 0;
	rep(i,0,n){
		ans = max(ans,dp[i][1]);
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