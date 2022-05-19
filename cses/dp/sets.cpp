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


const int mod = 1e9 + 7;

// const int N = 250*501;

int main(){
    int tt = 1;
    // cin >> tt;
    while(tt--){       
        ll n;
        cin >> n;
        int k = n;
        n*=n+1;
        // int N = n/2;
        if(n % 4){
            cout << 0;
            ln;
            continue;
        }
        n/=4;
        vector<vector<int>> dp(k+1,vector<int> (n + 1));
        dp[0][0] = 1;
        rep(i,1,k+1){
            rep(j,1,n+1){
                if(j >= i)
                    dp[i][j] = (dp[i-1][j] + dp[i-1][j-i])%mod;
                else dp[i][j] = dp[i-1][j];
            }
        }
        cout << dp[k][n];ln;
    }
}