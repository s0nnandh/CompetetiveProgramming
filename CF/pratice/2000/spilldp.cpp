#include<bits/stdc++.h>
#define ll long long
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
#define dbg(...) cerr << "" << endl
#endif

#define pi pair<int,int>
#define pl pair<ll,ll> 
#define fr first
#define sc second
#define pb push_back
#define gcd(a,b) __gcd(a,b)
#define len(x) (int)x.size()
#define all(x) x.begin(),x.end()
#define vi vector<int>
#define vl vector<ll>

    
void solve(){
    int n;
    cin >> n;
    vi a(n),b(n);
    int sum = 0,s = 0;
    rep(i,0,n){
        cin >> a[i] >> b[i];
        sum += a[i];
        s += b[i];
    }
    vector<vi> dp(n + 1,vi (sum + 1,-1));
    vector<double> ans(n);
    dp[0][0] = 0;
    rep(i,0,n){
        for(int j = sum;j >= 0;--j){
            rep(k,0,n){
                if(dp[k][j] != -1 && j + a[i] <= sum){
                    dp[k + 1][j + a[i]] = max(dp[k + 1][j + a[i]],b[i] + dp[k][j]);

                }
            }
        }
    }
    rep(i,1,n + 1){
        rep(j,0,sum + 1){
            if(dp[i][j] != -1){
                ans[i - 1] = max(ans[i - 1],min((double)(s + dp[i][j])/2,(double)j));
            }
        }
    }
    cout << setprecision(10) << fixed;
    for(auto x : ans)cout << x << " ";
    ln;
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
