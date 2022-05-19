// https://codeforces.com/contest/1486/problem/C1

#include<bits/stdc++.h>
#include<stdio.h>
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

ll mod = 1e9 + 7;
namespace modop {
	ll madd(ll a, ll b) {
	  return (a + b) % mod;
	}
	ll msub(ll a, ll b) {
	  return (((a - b) % mod) + mod) % mod;
	}
	ll mmul(ll a, ll b) {
	  return ((a % mod) * (b % mod)) % mod;
	}
	ll mpow(ll base, ll exp) {
	  ll res = 1;
	  while (exp) {
		if (exp % 2 == 1){
			res = (res * base) % mod;
		}
		exp >>= 1;
		base = (base * base) % mod;
	  }
	  return res;
	}
	ll minv(ll base) {
	  return mpow(base, mod - 2);
	}
	ll mdiv(ll a, ll b) {
	  return mmul(a, minv(b));
	}
	
	const ll FACTORIAL_SIZE = 1.1e6;
	ll fact[FACTORIAL_SIZE], ifact[FACTORIAL_SIZE];
	void gen_factorial(ll n) {
		fact[0] = fact[1] = ifact[0] = ifact[1] = 1;
		
		for (ll i = 2; i <= n; i++) {
			fact[i] = (i * fact[i - 1]) % mod;
            //dbg(fact[i]);
		}
		ifact[n] = minv(fact[n]);
		for (ll i = n - 1; i >= 2; i--) {
			ifact[i] = ((i + 1) * ifact[i + 1]) % mod;
		}
	}
	ll nck(ll n, ll k) {
		ll den = (ifact[k] * ifact[n - k]) % mod;
        //dbg(ifact[k],ifact[n - k]);
		return (den * fact[n]) % mod;
	}
}
 
using namespace modop;

void solve(){

	int n;
	cin >> n;
	auto ask = [&](int l,int r){
		if(l >= r)return -1;
		int x;
		cout << "? " << l + 1 << ' ' << r + 1  << endl;
		cin >> x;
		return x - 1;
	};

	int l = 0,r = n,mid;
	while(r - l > 1){
		int reply = ask(l,r - 1);
		mid = (l + r)/2;
		int s;
		if(reply < mid){
			s = ask(l,mid - 1);
			if(s == reply){
				r = mid;
			}
			else{
				l = mid;
			}
		}
		else{
			s = ask(mid,r - 1);
			if(s == reply){
				l = mid;
			}
			else{
				r = mid;
			}
		}

	}
	cout << "! " << r << endl;

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL); 
    gen_factorial(1e6);   
    int test=1;
    // cin>>test;   
    while(test--)
        solve();
    return 0;
}

// understand this properly . interactive problems must . // 
