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
	
	int n;
	cin >> n;
	vector<int> v(n);
	int sum = 0;
	for(auto &i : v){
		cin >> i;
		sum += i;
	}
	if(sum %n){
		cout << -1;
	}
	else{

		int ans = 0;
		sort(v.rbegin(),v.rend());
		bool eq = 1;
		rep(i,1,n){
			eq &= (v[i] == v[i-1]);
		}
		if(eq){
			cout << 0;
			ln;
			return;
		}
		vector<int> req(n);
		req[n-1] = (sum/n) - v.back();
		for(int i = n-2;i >= 0;--i){
			req[i] = req[i+1] + max((sum/n) - v[i],0);
		}
		// for(auto x : req)cout << x << " ";
		// ln;
		int extra = 0;	
		rep(i,0,n-1){
			extra += v[i] - (sum/n);
			++ans;
			if(extra >= req[i+1])break;
		}
		cout << ans;
	}
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