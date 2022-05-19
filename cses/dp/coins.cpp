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


// ll solve(vector<vector<ll>> &v,int i,int x){

// }       


int main(){
    int tt = 1;
    // cin >> tt;
    while(tt--){        
        int n;
        cin >> n;
        vector<int> v(n);
        for(auto&i : v)cin >> i;
        vector<bool> dp(1e6 + 1);
        dp[0] = 1;
        rep(i,0,n){
            for(int j = 1e6;j >= 0;--j){
                if(j >= v[i] && dp[j-v[i]])dp[j] = 1;
            }
        }
        int s = 0;
        rep(i,1,1e6+1){
            if(dp[i])
                ++s;
            // if(dp[i])cout << i << " ";
        }
        cout << s;ln;
        rep(i,1,1e6+1){
            // ++s;
            if(dp[i])cout << i << " ";
        }
        ln;
    }
}