#include<bits/stdc++.h>
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
    int n;
    cin >> n;
    vector<int> w(n),l(n+1),pos(n+1);

    rep(i,0,n){
        cin >> w[i];
        pos[w[i]] = i;
    }
    rep(i,0,n)cin >> l[w[i]];
    int ans = 0;
    rep(i,2,n+1){
        if(pos[i] <= pos[i-1]){
            int k = ceil((pos[i-1]-pos[i]+1)/(float)l[i]);
            ans+=k;
            //dbg(ans);
            pos[i] += k*l[i];
        }   
    }
    cout << ans ;ln;
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

// 2 1 4 3
/*
  ---       

*/

