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
    vector<int> v(n);
    rep(i,0,n){
        string t;
        cin >> t;
        if(t == "AND")v[i] = 0;
        else v[i] = 1;
    }
    ll t,f;
    if(v[0] == 1){
        t = 3;
        f = 1;
    }
    else{
        t = 1;
        f = 3;
    }
    rep(i,1,n){
        if(v[i] == 1){
            ll tt = t,tf = f;
            t = 2*tt + f;
            f = tf;
        }
        else{
            ll tt = t,tf = f;
            t = tt;
            f = 2*tf + t;
        }
    }
    cout << t;ln;
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

