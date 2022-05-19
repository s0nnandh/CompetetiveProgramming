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
    
    int n,m;
    cin >> n >> m;
    vector<ll> v(m);
    rep(i,0,n){
        int a;
        cin >> a;
        v[a%m]++;
    }
    // rep(i,0,m)cout << v[i] << " ";
    // ln;
    ll ans = 0;
    if(m%2 == 0){
        if(v[m/2]){
            ++ans;
            v[m/2] = 0;
        }
    }
    if(v[0])++ans;
    rep(i,1,m){
        if(v[i] && v[m-i]){
            //dbg(i,m-i);
            if(abs(v[m-i]-v[i]) <= 1){
                //dbg(i,m-i);
                ++ans;
            }
            else ans+=abs(v[m-i]-v[i]);
            v[i] = 0;v[m-i] = 0;
        }
    }
    // dbg(ans);
    // rep(i,1,m)cout << v[i] << " ";
    // ln;
    rep(i,1,m){
        if(v[i]){
            ans+=v[i];
        }
    }
    cout << ans;ln;
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

