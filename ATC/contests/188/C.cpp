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


void solve(){
    int n;
    cin >> n;
    vector<ll> v(1LL<<n);
    rep(i,0,(1LL<<n)){
        cin >> v[i];
    }
    int idx = -1,m = 0;
    rep(i,0,(1LL<<(n-1))){
        if(v[i] > m){
            m = v[i];
            idx = i + 1;
        }
    }
    int id = -1,M = 0;
    rep(i,(ll)v.size()/2,(ll)v.size()){
        if(v[i] > M){
            M = v[i];
            id = i + 1;
        }
    }
    //dbg(m,M,id,idx);
    int ans = -1;
    if(m > M)ans = id;
    else ans = idx;
    cout << ans;ln;
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

