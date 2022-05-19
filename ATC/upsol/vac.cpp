// https://atcoder.jp/contests/dp/tasks/dp_c

#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ln cout<<"\n"
using namespace std;
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
#define dbg(...) {}
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
    vector<int> a(n),b(n),c(n);
    rep(i,0,n){
        cin >> a[i] >> b[i] >> c[i];
    }
    vector<vector<int>> dp(n,vector<int> (3));
    dp[0][0] = a[0];dp[0][1] = b[0];dp[0][2] = c[0];
    rep(i,1,n){
        dp[i][0] = a[i] + max(dp[i-1][1],dp[i-1][2]);
        dp[i][1] = b[i] + max(dp[i-1][0],dp[i-1][2]);
        dp[i][2] = c[i] + max(dp[i-1][0],dp[i-1][1]);
    }
    cout << max(max(dp[n-1][0],dp[n-1][1]),dp[n-1][2]);ln;
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