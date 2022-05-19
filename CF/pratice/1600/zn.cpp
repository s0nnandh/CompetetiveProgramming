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


void solve(){
    
	int n,k,z;
	cin >> n >> k >> z;
	vector<ll> v(n);
	for(auto& i: v)cin >> i;
	z = min(z,k);
	ll ans = 0;
	rep(i,0,k+1)ans += v[i];
	// dbg(ans);
	rep(t,1,z + 1){
		int p = k - 2 * t;
		if(p >= 0){
			ll sum = 0,m = 0;
			rep(i,0,p + 1){
				if(i < n-1){
					m = max(m,v[i] + v[i+1]);
				}
				sum += v[i];
			}
			ans = max(ans,sum + m * t);
		}
		
	}
	cout << ans;ln;
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