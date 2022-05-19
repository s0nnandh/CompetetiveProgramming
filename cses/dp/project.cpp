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
#define all(x) x.begin(),x.end()

const int nx = 2e5 + 1;

ll dp[nx];  

void solve(){
    int n;
    cin >> n;
    vector<pair<pi,ll>> v(n);
    rep(i,0,n){
        cin >> v[i].fr.sc >> v[i].fr.fr >> v[i].sc;
        dp[i] = 0;
    }
    sort(all(v));
    vector<int> R(n);
    rep(i,0,n)R[i] = v[i].fr.fr;
    dp[0] = v[0].sc;
    rep(i,1,n){
        int start = v[i].fr.sc;
        int idx = lower_bound(all(R),start) - R.begin();
        --idx;
        if(idx < 0){
            dp[i] = max(dp[i-1],v[i].sc);
        }
        else{
            dp[i] = max(dp[i - 1],dp[idx] + v[i].sc);
        }
    }
    cout << dp[n - 1];ln;
    
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