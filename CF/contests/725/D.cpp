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

struct Sieve {
    vector<bool> isp;
    vector<int> primes;
    vector<short> smallest_fac;
 
    Sieve(int n, bool gen_primes = false, bool gen_mn = false) {
        isp.assign(n + 1, true); isp[0] = isp[1] = false;
        for (int i = 2; i * i <= n; ++i)
            if (isp[i])
                for (int j = i * i; j <= n; j += i)
                    isp[j] = false;
 
        if (gen_primes)
            for (int i = 2; i <= n; ++i)
                if (isp[i])
                    primes.push_back(i);
 
        if (gen_mn) {
            smallest_fac.resize(n + 1);
            for (int i = 2; i * i <= n; ++i)
                if (isp[i])
                    for (int j = i * i; j <= n; j += i)
                        smallest_fac[j] = i;
        }
    }
 
    bool is_prime(int k) const {
        return isp[k];
    }
 
    bool operator[](int k) const {
        return isp[k];
    }
 
    vector<pair<int, int>> get_prime_divs(int k) const {
        static vector<int> v;
        v.clear();
        while (k != 1 && !isp[k]) {
            v.pb(smallest_fac[k]);
            k /= smallest_fac[k];                
        }
        if (k != 1)
            v.pb(k);
        sort(v.begin(), v.end());
        vector<pair<int, int>> res;
        for (int i : v) {
            if (res.empty() || i != res.back().first)
                res.emplace_back(i, 0);
            res.back().second++;
        }
        return res;
    }
	
	int cnt_divs(ll n){
		int ans = 0;
        for (int p : primes) {
            if (p * p > n) break;
            while (n % p == 0) {
                n /= p;
                ++ans;
            }
        }
        if (n != 1) ++ans;
        return ans;
	}

    int phi(int n) const {
        auto v = get_prime_divs(n);
        for (auto p : v)
            n = n / p.fr * (p.fr - 1);
        return n;
    }
};
 
auto s = Sieve(1e5,1);

void solve(){
	
	int a,b,k;
	cin >> a >> b >> k;
	if(k == 1){
		if(a == b){
			cout << "NO" << endl;
			return;
		}
		if(a % b == 0 || b % a == 0){
			cout << "YES" << endl;
			return;
		}
		else{
			cout << "NO" << endl;
			return;
		}
	}
	int t = s.cnt_divs(a) + s.cnt_divs(b);
	cout << (k <= t ? "YES" : "NO") << endl;

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