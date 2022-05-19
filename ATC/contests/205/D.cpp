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
	
    int n,q;
    cin >> n >> q;
    vector<ll> v(n);
    for(auto &i : v)cin >> i;
    vector<ll> t;
    t.pb(0);
    t.pb(v[0]-1);
    rep(i,1,n){
        t.pb(t.back() + v[i] - v[i-1] - 1);
    }   
    int sz = t.size();
    rep(i,0,q){
        ll k;
        cin >> k;
        int idx = lower_bound(all(t),k) - t.begin();
        --idx;
        k -= t[idx];
        if(idx == 0){
            cout << k;ln;
        }
        else{
            cout << v[idx-1] + k;ln;
        }
    }


}   


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);        
    int test=1;
    // cin>>test;   
    while(test--)
        solve();
    return 0;
}