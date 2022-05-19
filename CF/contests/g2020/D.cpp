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
    // int n;
    // cin >> n;
    // vector<ll> cost(n);
    // for(auto& i : cost)cin >> i;
    // ll ans = accumulate(cost.begin(),cost.end(),0);
    // vector<int> deg(n);
    // rep(i,0,n-1){
    //     int a,b;
    //     cin >> a >> b;
    //     --a;--b;
    //     deg[a]++;deg[b]++;
    // }
    // vector<ll> val;
    // rep(i,0,n){
    //     rep(j,0,deg[i]-1){
    //         val.push_back(cost[i]);
    //     }
    // }
    // sort(val.begin(),val.end(),greater<ll>());
    // cout << ans << " ";
    // for(auto x : val){
    //     ans+=x;
    //     cout << ans << " ";
    // }
    // // rep(i,0,n-1){
    // //     ans+=val[0];
    // //     cout << ans << " ";
    // // }
    // ln;
    int n;
    cin >> n;
    vector<int> w(n);
    long long ans = 0;
    for (int i = 0; i < n; i++) {
      cin >> w[i];
      ans += w[i];
    }
    vector<int> deg(n);
    for (int i = 0; i < n - 1; i++) {
      int x, y;
      cin >> x >> y;
      --x; --y;
      deg[x] += 1;
      deg[y] += 1;
    }
    vector<int> seq;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < deg[i] - 1; j++) {
        seq.push_back(w[i]);
      }
    }
    sort(seq.rbegin(), seq.rend());
    cout << ans;
    for (int x : seq) {
      ans += x;
      cout << " " << ans;
    }
    cout << '\n';
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

