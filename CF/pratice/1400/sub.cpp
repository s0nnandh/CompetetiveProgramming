// https://codeforces.com/problemset/problem/1363/B


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

	int n;
	string s;cin >> s;
	n = sz(s);
	vector<int> zero(n + 1),one(n + 1);
	rep(i,0,n){
		zero[i+1] += zero[i] + (s[i] == '0');
		one[i + 1] += one[i] + (s[i] == '1');
	}
	ll ans = min(n - zero[n],n - one[n]);
	int l,r;
	rep(i,0,n){
		l = i - 1,r = i + 1;		
		int l0 = zero[i],l1 = one[i],r0 = zero[n] - zero[r],r1 = one[n] - one[r];
		// 0 1
		ans = min(ans,i - l0 + n - i - 1 - r1);
		// 1 0 
		ans = min(ans,i - l1 + n - i - 1 - r0);
	}
	rep(i,0,n){
		l = i,r = i + 1;		
		int l0 = zero[i + 1],l1 = one[i + 1],r0 = zero[n] - zero[r],r1 = one[n] - one[r];
		// 0 1
		ans = min(ans,i - l0 + n - i - r1);
		// 1 0 
		ans = min(ans,i - l1 + n - i - r0);
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


// Based on prefix sumss . Good problem . 