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

#define pl pair<ll,ll>
#define ctz(x) __builtin_ctzll(x)
#define pb push_back
#define pf push_front

int solve(vector<vector<int>> &dp,vector<vector<int>> &a,vector<vector<int>> &b,int i,int j){
    if(i == 0 || j == 0)return 1e9;
    if(i == 1 && j == 1)return 0;
    if(dp[i][j] == -1){
        dp[i][j] = min(solve(dp,a,b,i-1,j) + b[i-1][j],solve(dp,a,b,i,j-1) + a[i][j-1]);
    }
    return dp[i][j];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);    
    int tt = 1;
	// cin >> tt;	
	while(tt--){	
        int r,c;
        cin >> r >> c;
        vector<vector<int>> dp(r+1,vector<int> (c+1,-1));
        vector<vector<int>> a(r+1,vector<int> (c));
        vector<vector<int>> b(r,vector<int> (c+1));
        rep(i,1,r+1){
            rep(j,1,c){
                cin >> a[i][j];
            }
        }
        rep(i,1,r){
            rep(j,1,c+1){
                cin >> b[i][j];
            }
        }
        // rep(i,1,r+1){
        //     dp[i][0] = a[i][0];
        // }
        // rep(i,1,c+1){
        //     dp[0][i] = b[0][i];
        // }
        // rep(i,1,r+1){
        //     rep(j,1,c+1){
        //         dp[i][j] = min(dp[i][j-1] + a[i][j-1],dp[i-1][j] + b[i-1][j]);
        //     }   
        // }
        // cout << dp[r][c] ;
        cout << solve(dp,a,b,r,c);
	}   
}


