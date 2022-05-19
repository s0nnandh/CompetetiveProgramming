// https://codeforces.com/contest/1484/problem/C

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
	vector<int> cnt(n + 1);
	vector<vector<int>> v(m);
	rep(i,0,m){
		int k;
		cin >> k;
		rep(j,0,k){
			int a;
			cin >> a;
			v[i].pb(a);
			// cnt[a]++; 
		}
	}
	// first run 
	vector<int> ans(m);
	rep(i,0,m){
		if(v[i].size() == 1){
			// dbg(i,v[i][0]);
			cnt[v[i][0]]++;
			ans[i] = v[i][0];
		}
	}
	rep(i,1,n + 1){
		if(cnt[i] > (m + 1)/2){
			cout << "NO";
			ln;
			return;
		}
	}
	rep(i,0,m){
		if(v[i].size() > 1){
			bool f = 1;
			for(auto x : v[i]){
				if(cnt[x] < (m + 1)/2){
					++cnt[x];
					ans[i] = x;
					f = 0;
					break;
				}
			}
			if(f){
				cout << "NO";
				ln;
				return;
			}
		}
	}
	cout << "YES";
	ln;
	for(auto x : ans)cout << x << " ";
	ln;

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