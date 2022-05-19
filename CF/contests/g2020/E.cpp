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

const int m = 1e9 + 7;
void solve(){
    int n;
    cin >> n;
    vector<ll> v(n),z(60),one(61);
    for(auto&i : v)cin >> i;
    for(auto x : v){
        for(int i = 60;i>=0;--i){
            if(x&(1LL<<i))one[i]++;
        }
    }  
    vector<ll> power(61);
    ll a = 1;
    rep(i,0,61){
        power[i] = a;
        a=(a*2) % m;
    } 
    ll ans = 0;
    for(auto x : v){
        ll an = 0,orr = 0;
        for(int i = 60;i >= 0;--i){
            if(x&(1LL<<i)){
                an=(an + (one[i]*power[i]) % m) % m;
            }
        }

        for(int i = 60;i >= 0;--i){
            if(x&(1LL<<i)){
                orr = (orr + (n*power[i]) % m) % m;
            }
            else orr = (orr + (one[i]*power[i]) % m) % m;
        }
        ans =( ans + (an * orr ) % m ) % m;
    }   
    cout << ans;ln;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);    
    int test=1;
    cin>>test;   
    while(test--)
        solve();
    return 0;
}

// THE IDEA IS THAT FOR AND BIT WISE IF A BIT IS SET IT BASICALLY MEANS THAT THE
// NUMBER OF ONES TOTATLY
// AND FOR OR BIT WISE OPERATOR IF IT IS SET TO ZERO THEN THE TOTAL NO OF ONES
// AND IF IT IS A ONE THAN EVERY ELMENT WHICH IS N.