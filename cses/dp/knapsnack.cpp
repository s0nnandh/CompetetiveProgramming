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
#define pb push_back


// ll solve(vector<vector<ll>> &v,int i,int x){

// }       


int main(){
    int tt = 1;
    // cin >> tt;
    while(tt--){        
        int n,x;
        cin >> n >> x;
        vector<int> h(n),s(n);
        rep(i,0,n)cin >> h[i];
        rep(i,0,n)cin >> s[i];
        vector<vector<int>> dp(n+1,vector<int> (x+1));
        rep(i,1,n+1){
            rep(j,0,x+1){
                if(j >= h[i-1] && i > 0){
                    dp[i][j] = max(dp[i-1][j],s[i-1] +  dp[i-1][j-h[i-1]]);
                }
                else dp[i][j] = dp[i-1][j];
                // dbg(i,j,dp[i][j]);
            }
        }
        cout << dp[n][x];ln;
    }
}