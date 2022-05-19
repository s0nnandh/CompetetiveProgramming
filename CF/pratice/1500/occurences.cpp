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

void solve(){
    
    int n,q;
    cin >> n >> q;
    vector<ll> v(n),cnt(n+2);
    rep(i,0,n){
        cin >> v[i];
    }
    vector<pi> Q;
    rep(i,0,q){
        int l,r;
        cin >> l >> r;
        // --l;
        // --r;
        Q.pb({l,r});
        cnt[l] += 1;
        cnt[r+1] += - 1; 
    }
    vector<ll> c;
    rep(i,1,n + 2){
        cnt[i] += cnt[i-1];
        c.pb(cnt[i]);    
    }
    sort(c.rbegin(),c.rend());
    sort(v.rbegin(),v.rend());
    ll ans = 0;
    rep(i,0,n){
        // dbg(c[i],v[i]);
        ans += c[i] * v[i];
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