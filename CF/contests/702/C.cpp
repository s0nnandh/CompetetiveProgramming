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
    ll x;
    cin >> x;
    string ans = "NO";
    rep(i,1,10001){
        ll t = x - (i*i*i);
        if(t < 0)break;
        ll l = 1,r = 10000,mid;
        while(l <= r){
            mid = (l+r)/2;            
            ll k = mid*mid*mid;
            //dbg(mid,k,t);
            if(k == t){
                ans = "Yes";
                break;
            }
            else if(k > t) r = mid - 1;
            else l = mid + 1;
        }
        if(ans == "Yes")break;
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

