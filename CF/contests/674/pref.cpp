#include<bits/stdc++.h>
#include<stdio.h>
#define ll long long
#define ull unsigned long long
#define ln cout<<"\n"
#define int ll
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
#define dbg(...) cerr << "[ ]" << endl
#endif


void solve(){
    int n;
    cin >> n;
    vector<int> v(n);
    rep(i,0,n){
        int a;
        cin >> a;
        v[i] = a&1?1:0;
    }
    vector<int> cnt(2);
    int pref = 0;
    int ans = 0;
    rep(i,0,n){
        pref^=v[i];
        //dbg(pref,cnt[pref]);
        ans+=cnt[pref];
        if(!pref)ans++;
        cnt[pref]++;
    }
    cout << ans;ln;
}
 
 
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);    
    int test=1;
    cin>>test;   
    while(test--)
        solve();
    return 0;
}
