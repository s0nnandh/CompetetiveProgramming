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

ll inf = 1e18;

void solve(){
    
	int n;
	cin >> n;
	vector<ll> a(n),b(n);
	rep(i,0,n)cin >> a[i] >> b[i];
	vector<vector<pl>> dp(n,vector<pl> (3,{inf,inf}));
	dp[0][0] = {0,a[0]};
	dp[0][1] = {b[0],a[0] + 1};
	dp[0][2] = {2*b[0],a[0] + 2};
	rep(i,1,n){
		rep(j,0,3){
			rep(k,0,3){
				if(dp[i-1][k].fr != inf && a[i] + j != dp[i-1][k].sc){
					// dbg(i,a[i] + j,j,k);
					dp[i][j] = min(dp[i][j],{dp[i-1][k].fr + j * b[i],a[i] + j});
				}
			}
			// dbg(i,j,dp[i][j].fr);
		}
	}
	cout << min({dp[n-1][0].fr,dp[n-1][1].fr,dp[n-1][2].fr});ln;

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL); 
    //gen_factorial(1e6);   
    int test=1;
    cin>>test;   
    while(test--)
        solve();
    return 0;
}