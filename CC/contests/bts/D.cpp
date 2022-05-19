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
    cin >> n ;
    vector<int> h(n),q(n);
    rep(i,0,n)cin >> h[i];
    rep(i,0,n)cin >> q[i];
    vector<int> dp(n,1);

    rep(i,1,n){
        rep(j,0,i){
            if(h[i] > h[j] && q[i] < q[j]){
                //dbg(h[i],h[j],dp[i],1+dp[j]);
                dp[i] = max(dp[i],1+dp[j]);
            }
        }
    }
    int ans = 0;
    rep(i,0,n)ans = max(ans,dp[i]);
    cout << ans;ln;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);       
    int test=1;
    cin>>test;    
    while(test--)
        solve();
    return 0;
}

