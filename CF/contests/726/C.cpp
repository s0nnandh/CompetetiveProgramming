#include<bits/stdc++.h>
#define ll long long
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
    vector<ll> v(n);
    for(auto &i : v)cin >> i;
    sort(all(v));
    if(n == 2){
        cout << v[0] << " " << v[1];
        ln;
        return;
    }
    int idx =  -1;
    ll ans = 1e18;
    rep(i,1,n){
        if(v[i] - v[i-1] < ans){
            idx = i;
            ans = v[i] - v[i-1];
        }
    }
    vector<ll> f;
    rep(i,idx,n)f.pb(v[i]);
    rep(i,0,idx)f.pb(v[i]);
    for(auto x : f)cout << x << " ";
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
