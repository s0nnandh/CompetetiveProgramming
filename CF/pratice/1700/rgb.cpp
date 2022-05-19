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
#define dbg(...) cerr << "[ ]" << endl
#endif


#define pi pair<int,int>
#define pl pair<ll,ll> 
#define fr first
#define sc second
#define pb push_back
#define all(x) x.begin(),x.end()

void solve(){

	int r,g,b;
	cin >> r >> g >> b;
	vector<ll> R(r),G(g),B(b);
	for(auto &i : R)cin >> i;
	for(auto &i : G)cin >> i;
	for(auto &i : B)cin >> i;
	sort(all(R));
	sort(all(G));
	sort(all(B));
	ll ans = 4e18;
	auto sq = [&](ll x,ll y,ll z){
		return (x - y)*(x - y) + (x - z)*(x - z) + (z - y)*(z - y);
	};
	auto f = [&](vector<ll> &A,vector<ll> &Be,vector<ll> &C){
		int n = A.size();
		rep(i,0,n){
			int l = lower_bound(Be.begin(),Be.end(),A[i]) - Be.begin();
			int ri = lower_bound(C.begin(),C.end(),A[i]) - C.begin();
			if(l == (int)Be.size())--l;
			if(ri == (int)C.size())--ri;
			if(l > 0 && Be[l] > A[i])--l;
			ans = min(ans,sq(A[i],Be[l],C[ri]));
			// dbg(A[i],Be[l],C[ri]);
		}
	};
	f(R,G,B);
	f(R,B,G);
	f(B,G,R);
	f(B,R,G);
	f(G,B,R);
	f(G,R,B);
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

