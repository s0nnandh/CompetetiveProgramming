#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
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
#define dbg(...) {}
#endif

#define pi pair<int,int>
#define pl pair<ll,ll> 
#define fr first
#define sc second
#define pb push_back
#define gcd(a,b) __gcd(a,b)
#define all(x) x.begin(),x.end()

ll ninf = -1e18,pinf = 1e18;

void solve(){   
   
	int n,k;
	cin >> n >> k;
	string s;
	cin >> s;
	// if(n == 1){
	// 	cout << 1;ln;
	// 	return;
	// }
	vector<int> a(n),b(n);
	a[0] = (s[0] == 'a' ? 1 : 0);
	b[0] = (s[0] == 'b' ? 1 : 0);
	rep(i,1,n){
		a[i] += (s[i] == 'a' ? 1 : 0) + a[i-1];
		b[i] += (s[i] == 'b' ? 1 : 0) + b[i-1];
	}  
	int ans = 0;
	// making all b's
	rep(i,0,n){
		int idx = lower_bound(a.begin(),a.end(),a[i] - k) - a.begin();
		if(a[i] - k > 0)++idx;
		ans = max(ans,(int)i - idx + 1);
	}
	// making all a's 
	rep(i,0,n){
		int idx = lower_bound(b.begin(),b.end(),b[i] - k) - b.begin();
		if(b[i] - k > 0)++idx;
		ans = max(ans,(int)i - idx + 1);
	}
	cout << ans;ln;
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