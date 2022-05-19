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

ll n,k;
int boxes(vector<ll> &h,vector<int> &dp,int sa,int sb,int i){ 
    //dbg(sa,sb,num);
    int t = max(sa,sb);  
    if(sa >=k && sb >= k){
        return i;
    }
    if(i == n)return 1e9;
    if(sa >= k){
        if(dp[t] == -1 || dp[t] >= 1e9){
            dp[t] = boxes(h,dp,sa,sb+h[i],i+1);
        }
        //dbg(num,dp[sa+sb][num],sa,sb);
        return dp[t];
    }
    if(sb >= k){
        if(dp[t] == -1 || dp[t] >= 1e9){
            dp[t] = boxes(h,dp,sa+h[i],sb,i+1); 
        } 
        //dbg(num,dp[sa+sb][num],sa,sb);
        return dp[t] ;
    }   
    if(dp[t] == -1 || dp[t] >= 1e9){
        int x = boxes(h,dp,sa+h[i],sb,i+1);
        int y = boxes(h,dp,sa,sb + h[i],i+1);
        dp[t] =  min(x,y);
        //dbg(num,x,y,sa,sb);        
    }
    return dp[t];
}
bool check(vector<ll> &h){
    vector<bool> dp(k+1);
    dp[0] = 1;
    rep(i,0,n){
        for(int j = k;j>=h[i];--j){
            if(dp[j-h[i]])dp[j] = 1;
        }
    }
    return dp[k];
}
void solve(){
    cin >> n >> k;
    vector<ll> h(n);
    ll s = 0;
    for(auto& l : h){
        cin >> l;
        s +=l;
    }    
    if(s < 2*k){
        cout << -1;
        ln;
        return;
    }
    sort(h.rbegin(),h.rend());
    if(s == 2*k){       
        if(h[0] > k){
            cout << -1;
            //ln;
        }
        else if(check(h)){
            cout << n ;
            //ln;
        }
        else {
            cout << -1;
        }
    }
    else if(h[0] >= k){
        s = 0;int idx = 0;
        rep(i,1,n){
            s+=h[i];
            if(s >= k){
                idx = i;
                break;
            }
        }
        if(idx == 0){
            cout << -1;
        }
        else cout << idx + 1;
    }
    else{
        //dbg(s);
        vector<int> dp(s+1,-1);
        int ans = boxes(h,dp,0,0,0);
        cout << (ans>=1e9?-1:ans);
    }
    ln;
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

