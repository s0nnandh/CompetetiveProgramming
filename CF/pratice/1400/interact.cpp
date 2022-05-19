// https://codeforces.com/contest/1512/problem/C

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
    vector<ll> v(n+1);
	auto ask = [&](int i,int j){
		cout << "? " << i << " " << j << endl;
		cin >> v[j-1];
	};
	rep(i,2,n + 1){
		ask(1,i);
	}
	cout << "? " << 2 << " " << n << endl;
	cin >> v[n];
	// a1 value
	ll a = ( v[n-1] - v[n] + v[1] ) / 2;
	cout << "! " << a;
	rep(i,1,n){
		cout << " " << v[i] - a;
	}
	cout << endl;

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
