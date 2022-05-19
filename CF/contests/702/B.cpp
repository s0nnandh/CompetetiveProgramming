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
    
    int n,k;
    cin >> n >> k;
    set<ll> s,pos;
    vector<bool> v(n);
    ll mex = 0,m = 0;
    rep(i,0,n){
        ll a;
        cin >> a;
        m = max(m,a);
        s.insert(a);
        if(a < n){
            v[a] = 1;
        }
    }  
    bool ss = 0;  
    rep(i,0,n){
        if(!v[i]){
            ss = 1;
            mex = i;
            break;
        }
    }       
    if(ss == 0){
        cout << n + k;ln;
        return;
    }
    else{
        cout << n + ((bool)k && s.find((m+mex+1)/2) == s.end());ln;
    }
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

