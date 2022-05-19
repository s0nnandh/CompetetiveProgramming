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
    ll n,k,x;
    cin >> n >> k >> x;
    vector<ll> v(n);
    for(auto &i : v)cin >> i ;
    sort(v.begin(),v.end());
    vector<ll> ans;
    rep(i,1,n){
        if(v[i] - v[i-1] > x)ans.pb(v[i] - v[i-1]);
    }
    sort(ans.begin(),ans.end());
    ll out = ans.size() + 1;
    rep(i,0,(int)ans.size()){
        ll req = ans[i]/x;
        if(ans[i] % x == 0)--req;
        if(k < req)break;
        k -= req;
        --out;
    }       
    cout << out << endl;
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