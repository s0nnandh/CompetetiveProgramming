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
    vector<ll> d(n);
    ll sum = 0;
    for(auto &i : d){
        cin >> i;
        sum -= i;
    }
    sort(all(d));
    ll c = n - 1;
    vector<ll> back(n);
    rep(i,0,n){
        back[i] = c * d[i];
        --c;
    }
    // dbg(sum);
    rep(i,0,n){
        sum += d[i];
        back[i] += sum;
    }
    // for(auto x : back)cout << x << " ";
    // ln;
    ll ans = 0;
    rep(i,1,n)ans += d[i] - d[i - 1];
    rep(i,0,n)ans += back[i];
    cout << ans;ln;

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
