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

map<pl,ll> mp;

int n,m,k;

pair<ll,vector<ll>> solve(ll cost,int i,vector<ll> &v,vector<pair<ll,vector<ll>>> &dp,vector<ll> t){
    if(i > n){
        vector<ll> tt(n+1);
        return {cost,t};
    }
    cout << " t" << endl;
    rep(j,1,n+1){
        cout << t[i] << " ";
    }
    if(dp[i].first == -1){
        vector<ll> L(t.begin(),t.end());
        L[i] = 0;
        // t[i] = 0;
        pair<ll,vector<ll>> c1 = solve(cost + v[i-1],i + 1,v,dp,L);
        vector<ll> t1 = c1.second;
        rep(j,1,n+1){
            t1[j]+=t1[j-1];
        }
        // cout << i << "1----------";ln;
        // rep(j,1,n+1){
        //     // t1[j]+=t1[j-1];
        
        //     cout << t1[j] << " ";
        // }
        // cout << i << "----------";ln;
        // t[i] = 1;
        vector<ll> R(t.begin(),t.end());
        R[i] = 1;
        pair<ll,vector<ll>> c2 = solve(cost,i+1,v,dp,R);
        vector<ll> t2 = c2.second;
        // rep(j,1,n+1){
        //     t2[j]+=t2[j-1];
        // }
        // cout << i << "2----------";ln;
        rep(j,1,n+1){
            // t1[j]+=t1[j-1];
            cout << t1[j] << " ";
        }
        cout << i << "----------";ln;
        for(auto x : mp){
            pl p = x.first;
            int l = p.first,r = p.second;
            if(t1[r]-t1[l-1] == r-l+1){
                c1.first += x.second;
            }
            if(t2[r]-t2[l-1] == r-l+1){
                c2.first += x.second;
            }
        }
        if(c1.first >= c2.first){
            dp[i].first = c1.first;
            dp[i].second = c1.second;
        }
        else{
            dp[i].first = c1.first;
            dp[i].second = c1.second; 
        }
        dbg(i,dp[i].first);
    }
    return dp[i];
}

int main(){
    int tt = 1;
    cin >> tt;
    while(tt--){        
        
        cin >> n >> m >> k;
        vector<ll> v(n);
        for(auto &i : v)cin >> i;
        rep(i,0,m){
            int a,b,c;
            cin >> a >> b >> c;
            mp[{a,b}] = c;
        }
        vector<ll> pre(n+1,0);  
        vector<pair<ll,vector<ll>>> dp(n+1,{-1,pre}); 
        dp[0] = {0,pre};
        // rep(i,1,n+1){

        // }        
        pair<ll,vector<ll>> ans = solve(0,1,v,dp,pre);
        cout << ans.first ;ln;
    }
}