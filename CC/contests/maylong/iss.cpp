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

void solve(){
   
    ll k;
    cin >> k ;
    map<int,int> mp;
    ll n = (2*k) + 1;
    vector<ll> v(n) ;
    rep(i,1,n+1){
        v[i-1] = k + i*i; 
    }
    ll ans = 0;
    rep(i,1,n){
        mp[gcd(v[i],v[i-1])]++;
        // dbg(v[i-1]);
        ans += gcd(v[i],v[i-1]);

    }
    cout << k << ' ' << ans;ln;
    cout << "EXtra Added : " << ans - (4* k + 1);ln;
    cout << "Occurences";ln;
    cout << "Size is : " << mp.size() ;ln;
    for(auto x : mp){
        cout << x.fr << " " << x.sc;ln;
    }
    cout << "---------------------------";ln;

}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL); 
    //gen_factorial(1e6);   
    int test=1;
    cin>>test;   
    while(test--)
        solve();
    return 0;
}