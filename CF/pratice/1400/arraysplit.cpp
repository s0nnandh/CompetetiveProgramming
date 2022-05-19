// https://codeforces.com/problemset/problem/1197/C

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
#define sz(x) (int)x.size()


void solve(){
	
	int n,k;
	cin >> n >> k;
	vector<int> v(n);
	for(auto &i : v)cin >> i;
	ll ans = v.back() - v.front();	
	vector<int> add;
	rep(i,0,n-1)add.pb(v[i] - v[i+1]);
	sort(add.begin(),add.end());
	rep(i,0,k-1){
		ans += add[i];
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

// really coool observation .. 
