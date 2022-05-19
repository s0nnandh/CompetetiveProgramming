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

ll inf = 1e14;
vector<vector<vector<ll>>> dp(201,vector<vector<ll>>(201,vector<ll> (201,-1)));
int R[201],G[201],B[201];

ll solve(int i,int j,int k){
	if(dp[i][j][k] != -1)return dp[i][j][k];
	dp[i][j][k] = 0;
	if(i > 0 && j > 0 && k > 0){
		dp[i][j][k] = max({R[i-1]*G[j-1] + solve(i-1,j-1,k),
							G[j-1]*B[k-1] + solve(i,j-1,k-1),
							R[i-1]*B[k-1] + solve(i-1,j,k-1)
						});
		return dp[i][j][k];
	}
	if(i > 0 && j > 0){
		dp[i][j][k] = R[i-1]*G[j-1] + solve(i-1,j-1,k);
		return dp[i][j][k];
	}
	if(j > 0 && k > 0){
		dp[i][j][k] = G[j-1]*B[k-1] + solve(i,j-1,k-1);
		return dp[i][j][k];
	}
	if(i > 0 && k > 0){
		dp[i][j][k] = R[i-1]*B[k-1] + solve(i-1,j,k-1);
		return dp[i][j][k];
	}
	return dp[i][j][k];
}

void solve(){
    
	int r,g,b;
	cin >> r >> g >> b;
	rep(i,0,r)cin >> R[i];
	rep(i,0,g)cin >> G[i];
	rep(i,0,b)cin >> B[i];
	sort(R,R+r);
	sort(G,G+g);
	sort(B,B+b);
	// rep(i,0,201){
	// 	rep(j,0,201){
	// 		rep(k,0,201)dp[i][j][k] = 0;
	// 	}
	// }
	cout << solve(r,g,b);ln;
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