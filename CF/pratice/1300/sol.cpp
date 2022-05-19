#include<bits/stdc++.h>
#define ll long long
#define ln cout<<endl
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


void solve(){

    int n;
    cin >> n;
    vector<int> v(n);
    for(auto &i : v)cin >> i;
    vector<int> ans;
    ans.pb(v[0]);
    ans.pb(v[1]);
    rep(i,2,n){
        int two = ans.back();
        ans.pop_back();
        int one = ans.back();
        ans.pop_back();
        int th = v[i];
        if(abs(th - one) >= abs(th - two) + abs(one - two)){
            ans.pb(one);
            ans.pb(th);
        }
        else{
            ans.pb(one);
            ans.pb(two);
            ans.pb(th);
        }
    }
    cout << ans.size();ln;
    for(auto x : ans)cout << x << " ";
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


