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
	map<string,string> mp;
	string a,b,c,d,e,last;
	while(n--){		
		cin >> a >> b;
		// cout << a << " " << b ;ln;
		last = a;
		if(b == ":="){			
			cin >> c;
			mp[a] = c;
		}
		else{
			cin >> c >> d >> e;
			// cout << d ;ln;
			mp[a] = mp[c] + mp[e];
		}
	}
	// cout << last << " " << mp[last];ln;
	string s = mp[last];
	int sz =s.size();
	// cout << sz;ln;
	int ans = 0;
	rep(i,0,sz){
		if(i + 3 < sz)ans += (s.substr(i,4) == "haha");
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