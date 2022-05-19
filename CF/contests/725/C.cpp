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
#define all(x) x.begin(),x.end()
 
void solve(){
	
	ll n,l,r;
	cin >> n >> l >> r;
	vector<ll> v(n);
	for(auto &i : v)cin >> i;
	if(n == 1){
		cout << 0;
		ln;
		return;
	}
	sort(all(v));
	ll ans = 0;
	rep(i,0,n-1){
		ll lid = lower_bound(all(v),l - v[i]) - v.begin();
		lid = max(lid,i + 1);
		ll rid = upper_bound(all(v),r - v[i]) - v.begin();
		if(rid < lid)continue;
		ll pos = n - lid;
		ll dw = n - rid;
		ans += pos - dw;
		dbg(lid,rid,ans);
	}
	cout << ans;ln;
 
}	
	
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL); 
    // gen_factorial(1e6);   
    int test=1;
    cin>>test;   
    while(test--)
        solve();
    return 0;
}