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
    vector<int> v(n);
    for(auto &i : v)cin >> i;
    vector<vector<ll>> dp(n + 1,vector<ll> (n + 1,-1e18));

    // trnasition if(i >= j) dp[i][j] = dp[i-1][j-1] + v[i-1]
    dp[0][0] = 0;
    rep(i,1,n+1){
        dp[i][0] = 0;
        // dp[0][i] = 0;
    }
    rep(i,1,n + 1){
        rep(j,1,n + 1){
            if(i >= j){               
                // transition state
                dp[i][j] = dp[i-1][j];
                if(dp[i-1][j-1] + v[i-1] >= 0){
                    dp[i][j] = max(dp[i][j],dp[i-1][j-1] + v[i-1]);
                } 
            }
        }
    }
    // for(auto x : dp){
    //     for(auto y : x){
    //         cout << y << " ";
    //     }
    //     ln;
    // }
    int ans = 0;
    rep(i,0,n + 1){
        if(dp[n][i] >= 0){
            ans = i;
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