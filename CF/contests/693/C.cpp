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

int n;

ll dfs(int j,vector<ll> &score,vector<int> &a){
    if(j > n)return 0;
    if(score[j] != 0)return score[j];
    if(j <= n){
        score[j]=a[j] + dfs(j+a[j],score,a);
    }
    return score[j];
}
void solve(){
    
    cin >> n;
    vector<int> a(n+1);
    vector<bool> visited(n+1,false);
    vector<ll> score(n+1,0);
    rep(i,1,n+1)cin >> a[i];
    //ll score = 0;
    ll ans = 0;
    rep(i,1,n+1){
        if(score[i] == 0)dfs(i,score,a);
        //dbg(score[i]);
        ans = max(ans,score[i]);
    }
    //cout << score;ln;
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

