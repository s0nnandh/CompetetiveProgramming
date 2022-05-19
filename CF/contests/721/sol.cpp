// https://codeforces.com/contest/429/problem/B

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

void solve(){

    int n;
    cin >> n;
    map<int,vector<ll>> mp;
    rep(i,1,n + 1){
        int a;
        cin >> a;
        mp[a].pb(i);
    }
    ll ans = 0;
    for(auto x : mp){
        vector<ll> t = x.second;
        if(t.size() > 1){
            int sz = t.size();
            ll cnt = n - t[sz-1] + 1;
            for(int i = sz-2; i >= 0;--i){
                ans += cnt * t[i];
                cnt += n - t[i] + 1;
            }
        }
    }
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