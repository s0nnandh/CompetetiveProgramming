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
#define dbg(...) cerr << "[ ]" << endl
#endif

#define pl pair<ll,ll>

void solve(){
    string s;
    cin >> s;
    int n = s.size();
    bool ev = 1;
    if(n&1)ev = 0;
    n = n/2;
    ll ans = 0;
    if(ev){
        ll po = 1;
        rep(i,0,n-1)po*=10;
        dbg(po);
        //ans = 1;
        int kk = s[0] - '0';
        ans+=(kk-1)*po;
        dbg(ans);
        if(s[0] >= s[n]){
            ll t = 1;
            rep(i,1,n){
                kk = min(s[i]-'0',s[i+n]-'0');
                t*=kk+1;
            }
            ans+=t;
        }       
        
    }
    //dbg(ans);
    ll t=0,k = 1;
    if(!ev)++n;
    rep(i,0,n-1){
        t+=9*k;
        k*=10;
    }
    cout << ans + t;ln;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);    
    int test=1;
    //cin>>test;   
    while(test--)
        solve();
    return 0;
}

