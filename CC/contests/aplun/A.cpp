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
#define pb push_back

ll mod = 1e9 + 7;

int main(){
    int tt = 1;
    // cin >> tt;
    while(tt--){        

        int n;
        cin >> n;
        ll sum = 0;
        rep(i,0,n){
            ll a;
            cin >> a;
            sum = (sum + a) % mod;
        }
        int q;
        cin >> q;
        rep(i,0,q){
            int a;
            cin >> a;
            sum = (sum * 2) % mod;
            cout << sum ;ln;
        }
    }
}
