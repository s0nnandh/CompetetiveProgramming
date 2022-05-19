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


void solve(){

	int n,m;
	cin >> n >> m;
	string a,b;
	cin >> a >> b;
	vector<int> f(m),l(m);
	int j = 0;
	rep(i,0,n){
		if(a[i] == b[j]){
			f[j] = i;
			++j;
		}
	}
	// for(auto x : f)cout << x << " ";
	// ln;
	j = m-1;
	for(int i = n-1;i >= 0;--i){
		if(a[i] == b[j]){
			l[j] = i;
			--j;
		}
	}
	// for(auto x : l)cout << x << " ";
	// ln;
	int ans = 0;
	rep(i,0,m-1){
		ans = max(ans,l[i+1] - f[i]);
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