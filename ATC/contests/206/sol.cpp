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

void solve(){
    ll l,r;
    cin >> l >> r;
    int mx = r;
    vector<vector<int>> fac(mx + 1);
    rep(i,2,mx + 1){
        for(int j = i;j <= mx;j += i)fac[j].pb(i);
    }
    ll ans = 0;
    rep(i,l,r){
        // dbg(fac[i].size());
        if(fac[i].size() == 1)continue;
        for(int j = 0;j < (int)fac[i].size() - 1;++j){
            int x = fac[i][j];
            // dbg(i,x,r/x,i/x);
            ans += 2* ((r/x) - (i/x));
        }
        if(i != 1)ans -= 2 * (r/i - 1);
    }
    dbg(ans);
    cout << ans;ln;
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