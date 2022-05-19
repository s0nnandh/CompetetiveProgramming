// https://codeforces.com/contest/429/problem/B

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

const int nx = 1001;

// instead of calculating dp from index 0 better to calculate from 1 indexing 
// just makes it easier to handle spl cases size of n + 2 will suffice . 

// vector<vector<int>> up(nx,vector<int> (nx)),dp(nx,vector<int> (nx)),up2(nx,vector<int> (nx)),dp2(nx,vector<int> (nx));

void solve(){

	int n,m;
	cin >> n >> m;
	vector<vector<int>> v(n + 1,vector<int> (m + 1));
	rep(i,1,n+1){
		rep(j,1,m+1)cin >> v[i][j];	
	}
	// if(n % 2 == 0){
	// 	cout << 0;ln;
	// 	exit(0);
	// }
	vector<vector<int>> up(n + 2,vector<int> (m + 2)),dp(n + 2,vector<int> (m + 2)),up2(n + 2,vector<int> (m + 2)),dp2(n + 2,vector<int> (m + 2));
	// dp[0][0] = v[0][0];
	// rep(i,1,n){
	// 	dp[i][0] = dp[i-1][0] + v[i][0];
	// }
	// rep(i,1,m){
	// 	dp[0][i] = dp[0][i-1] + v[0][i];
	// }
	// rep(i,1,n){
	// 	rep(j,1,m){
	// 		dp[i][j] = v[i][j] + max(dp[i-1][j],dp[i][j-1]);
	// 	}
	// }
	// up[n-1][0] = v[n-1][0];
	// for(int i = n -2;i >= 0;--i){
	// 	up[i][0] = up[i + 1][0] + v[i][0];
	// }
	// rep(i,1,m){
	// 	up[n-1][i] = up[n-1][i-1] + v[n-1][i];
	// }
	// for(int i = n-2;i >= 0;--i){
	// 	rep(j,1,m){
	// 		up[i][j] = v[i][j] + max(up[i+1][j],up[i][j-1]);
	// 	}
	// }

	rep(i,1,n+1){
		rep(j,1,m+1){
			dp[i][j] = max(dp[i-1][j],dp[i][j-1]) + v[i][j];
		}
	}
	for(int i = n;i >= 1;--i){
		rep(j,1,m+1){
			up[i][j] = max(up[i+1][j],up[i][j-1]) + v[i][j];
		}
	}
	
	for(int i = n;i >= 1;--i){
		for(int j = m;j >= 1;--j){
			up2[i][j] = max(up2[i+1][j],up2[i][j+1]) + v[i][j];
		}
	}
	rep(i,1,n +1){
		for(int j = m;j >= 0;--j){
			dp2[i][j] = max(dp2[i-1][j],dp2[i][j+1]) + v[i][j];
		}
	}
	int ans = 0;
	rep(i,2,n){
		rep(j,2,m){
			ans = max(ans,up2[i][j+1] + dp[i][j-1] + dp2[i-1][j] + up[i+1][j]); /// 
			ans = max(ans,dp2[i][j+1] + dp[i-1][j] + up[i][j-1] + up2[i+1][j]); /// -|
		}
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