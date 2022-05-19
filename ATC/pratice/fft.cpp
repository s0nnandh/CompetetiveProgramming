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
#define dbg(...) cerr << "[ ]" << endl
#endif

#define pl pair<ll,ll>
#define ctz(x) __builtin_ctzll(x)


const int mod = 998244353;


// int p = 3;
// p is primitive root 

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



// const int root = 3;
// const int root_1 = minv(3);
// const int root_pw = mpow(3,119);

// void fft(vector<ll> & a, bool invert) {
//     int n = a.size();

//     for (int i = 1, j = 0; i < n; i++) {
//         int bit = n >> 1;
//         for (; j & bit; bit >>= 1){
//             j ^= bit;
// 		}
//         j ^= bit;

//         if (i < j){
//             swap(a[i], a[j]);
// 		}
//     }

//     for (int len = 2; len <= n; len <<= 1) {
//         int wlen = invert ? root_1 : root;
//         for (int i = len; i < root_pw; i <<= 1)
//             wlen = (int)((1LL * wlen * wlen) % mod);

//         for (int i = 0; i < n; i += len) {
//             int w = 1;
//             for (int j = 0; j < len / 2; j++) {
//                 int u = a[i+j], v = (int)((1LL * a[i+j+len/2] * w) % mod);
//                 a[i+j] = u + v < mod ? u + v : u + v - mod;
//                 a[i+j+len/2] = u - v >= 0 ? u - v : u - v + mod;
//                 w = (int)((1LL * w * wlen) % mod);
//             }
//         }
//     }

//     if (invert) {
//         int n_1 = minv(n);
//         for (ll & x : a)
//             x = (int)((1LL * x * n_1) % mod);
//     }
// }

void fft(vector<ll> &a,bool inv, ll p){
	int n = a.size();

	rep(i,0,n){

		ll y = 0;
		rep(j,0,ctz(n)){

			if(i&(1LL<<j)){
				y |= (1LL << (ctz(n)-j-1));
			}
		}

		if(y > i){
			//dbg(y);
			swap(a[i],a[y]);
		}

	}
	ll x = p;
	if(inv)x = minv(p);
	// dbg(x);

	rep(s,1,ctz(n) + 1){
		ll y = mpow(x,(n/(1LL << s)));
		//dbg(y);

		rep(j,0,(n/(1LL << s))){

			ll r = 1;

			rep(i,0,(1LL << (s-1))){

				ll u = a[i + j*(1LL << s)];
				ll v = mmul(r,a[i + j*(1LL << s) + (1LL << (s-1))]);
				a[i + j*(1LL << s)] = madd(u,v);
				a[i + j*(1LL << s) + (1LL << (s-1))] = msub(u,v);
				r*=y;
				r%=mod;

			}
		}
	}

	if(inv){
		ll ivn = minv(n);
		rep(i,0,n){
			a[i] = mmul(a[i],ivn);
		}
	}

}



vector<ll> pmul(vector<ll> &a,vector<ll> &b,vector<ll> &v){

    ll sz = 1;
	while( sz < (ll)a.size() + (ll)b.size()){
		sz<<=1;
	}
	// dbg(sz);
	vector<ll> fa(a.begin(),a.end());
	vector<ll> fb(b.begin(),b.end());

	fa.resize(sz,0);
	fb.resize(sz,0);

	ll y = mpow(3,(mod-1)/sz);
	// vector<ll> v(sz);
	v.resize(sz,0);
	fft(fa,0,y);
	fft(fb,0,y);
	rep(i,0,sz){
		v[i] = mmul(fa[i],fb[i]);
	}
	fft(v,1,y);

	v.resize((ll)a.size() + (ll)b.size() -1);

	return v;
    
}



void solve(){
    
    int n,m;

    cin >> n >> m;
    vector<ll> a(n),b(m);
    rep(i,0,n){
        cin >> a[i];
    }    
    rep(i,0,m){
		cin >> b[i];
	}

	vector<ll> ans(n);

	pmul(a,b,ans);
	
	rep(i,0,(ll)ans.size())cout << ans[i] << " ";
	ln; 


}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);    
    int test=1;
    //cin>>test;   
    while(test--)
        solve();
    return 0;
}


