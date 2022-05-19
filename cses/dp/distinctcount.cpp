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
        int n,x;
        cin >> n >> x;
        vector<int> v(n);
        for(auto&i : v)cin >> i;
        vector<int> dp(x+1);
        dp[0] = 1;
        rep(j,0,n){
            rep(i,1,x + 1){
                if(i >= v[j]){
                    dp[i] = (dp[i] + dp[i-v[j]]) % mod;
                }
            }
        }
        cout << dp[x];ln;
 
    }
}