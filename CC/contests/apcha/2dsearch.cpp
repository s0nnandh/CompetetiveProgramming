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
#define pb push_back
int main(){
    int tt = 1;
    cin >> tt;
    while(tt--){        
        
       ll t,q,D;
       cin >> t >> q >> D;
       ll l = -1e18,r = 1e18,u = 1e18,d = -1e18,xmid,ymid;
       while(q--){
            cout << 1 <<" ";
            xmid = (l + r)/2;ymid = (u + d)/2;
            cout << xmid << " " << ymid << endl;
            string s;
            cin >> s;
            if(s == "O"){
                break;
            }
            else if(s == "PY"){

                l = xmid + 1;
            }
            else if(s == "NY"){
                r = xmid - 1;
            }
            else if(s == "XP"){
                d = ymid + 1;
            }
            else if(s == "XN"){
                u = ymid-1;
            }
            else if(s == "PP"){
                l = xmid + 1;
                d = ymid + 1;
            }
            else if(s == "PN"){
                l = xmid + 1;
                u = ymid-1;
            }
            else if(s == "NP"){
                r = xmid - 1;
                 l = xmid + 1;
            }
            else {
                r = xmid - 1;
                u = ymid-1;
            }
       }
       if(q <= 0)cout << "FAILED";ln;
    }
}