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
#define ctz(x) __builtin_ctzll(x)
#define pb push_back
#define pf push_front

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);    
    int tt = 1;
	// cin >> tt;	
	while(tt--){	
        int n;
        cin >> n;
        vector<vector<int>> v(n,vector<int> (5));
        rep(i,0,n){
            rep(j,0,5){
                cin >> v[i][j];
            }
        }
        int ans = 0;
        rep(i,0,n){
            rep(j,i+1,n){
                vector<int> t(5);
                int s= 1e9;
                rep(k,0,5){
                    t[k] = max(v[i][k],v[j][k]);
                    s = min(s,t[k]);
                }
                ans = max(ans,s);
            }
        }
        cout << ans;ln;
	}       
}


