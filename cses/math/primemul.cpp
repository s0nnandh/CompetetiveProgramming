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

// Take care while multiplying large numbers

void solve(){
    ll n;
    int k;
    cin >> n >> k;
    vector<ll> v(k);
    for(auto &i : v)cin >> i;
    ll ans = 0;
    // rep(i,0,k)ans += (n / v[i]);
    rep(i,1,(1 << k)){
        ll t = 1;
        int now = 0;
        bool dont = 0;
        for(int j = 0;j < k;++j){
            if(i&(1LL<<j)){
                if((double)t * v[j] <= 1e18){
                    t *= v[j];
                    ++now;                    
                }
                else{
                    dont = 1;
                    break;
                }
            }
        }
        if(dont)continue;
        ans = ans + (now&1 ? (ll)n/t : -((ll)n/t));
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