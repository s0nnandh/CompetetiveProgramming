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
#define sz(x) (int)x.size()
#define all(x) x.begin(),x.end()

void solve(){

	int n;
    cin >> n;
    vector<vector<int>> v(n);    
    vector<int> a(n),s(n);
    rep(i,0,n)cin >> a[i];
    rep(i,0,n)cin >> s[i];
    rep(i,0,n){
        --a[i];
        v[a[i]].pb(s[i]);
    }
    rep(i,0,n)sort(v[i].rbegin(),v[i].rend());
    vector<vector<ll>> pref(n);
    rep(i,0,n)pref[i].pb(0);
    rep(i,0,n){
        for(auto x : v[i])pref[i].pb(pref[i].back() + x);
    }
    vector<ll> ans(n + 1);
    rep(i,0,n){
        for(int k = 1;k <= sz(v[i]);++k){
            ans[k] += pref[i][(sz(v[i])/k)*k];
        }
    }
    rep(i,1,sz(ans))cout << ans[i] << " ";
    ln;
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
