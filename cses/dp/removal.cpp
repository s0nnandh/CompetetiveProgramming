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
 
 
 
ll solve(vector<vector<ll>> &dp,int l,int r,bool par,vector<int> &v){
    if(r < l)return 0;    
    if(!par & (dp[l][r] == -1)){
        dp[l][r] = max(v[l] + solve(dp,l+1,r,!par,v),v[r] + solve(dp,l,r-1,!par,v));
        return dp[l][r];
    }
    if(dp[l][r] == -1){
        dp[l][r] = min(solve(dp,l+1,r,!par,v),solve(dp,l,r-1,!par,v));
    }
    return dp[l][r];
}       
 
 
 
int main(){
    int tt = 1;
    // cin >> tt;
    while(tt--){        
        int n;
        cin >> n;
        vector<int> v(n + 1);
        rep(i,1,n+1)cin >> v[i];
        vector<vector<ll>> dp(n+1,vector<ll> (n+1,-1));
        cout << solve(dp,1,n,0,v);
        ln;
    }
}