// https://codeforces.com/problemset/problem/1516/B

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

	int n;
	cin >> n;
	vector<int> v(n + 1),pref(n + 1);
	rep(i,1,n + 1){
		cin >> v[i];
		pref[i] = pref[i-1] ^ v[i];
	}
	// now if even no of  elements 
	if(pref[n] == 0){
		cout << "YES";ln;
		return;
	}
	// if odd no of elements
	// dividing into 3 parts 
	int b1 = 1,b2 = 2;	
	for(;b1 <= n-2;++b1){
		int fpart = pref[b1];
		for(b2 = b1 + 1;b2 <= n-1;++b2){
			int spart = pref[b2]^fpart;
			int rpart = pref[n]^pref[b2];
			if(spart == pref[n] && fpart == pref[n] && rpart == pref[n]){
				cout << "YES";ln;
				return;
			}
		}	
	}
	cout << "NO";ln;
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

