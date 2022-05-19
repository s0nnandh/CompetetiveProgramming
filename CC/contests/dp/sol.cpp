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

void solve(){
    int n;
    vector<int> k(3);
    cin >> n >> k[0] >> k[1] >> k[2];
    vector<int> dp(n+1,-1e9);
    dp[0] = 0;
    for(int i = 1;i <= n;++i){
        rep(j,0,3){
            if(i-k[j] >= 0){
                dp[i] = max(dp[i],1+dp[i-k[j]]);
            }
        }
        //dbg(dp[i]);
    }
    cout << dp[n];ln;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);       
    int test=1;
    //cin>>test;    
    while(test--)
        solve();
    return 0;
}

