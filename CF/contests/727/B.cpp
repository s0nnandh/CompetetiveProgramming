#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ln cout<<"\n"
using namespace std;
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
#define dbg(...) {}
#endif

#define pi pair<int,int>
#define pl pair<ll,ll> 
#define fr first
#define sc second
#define pb push_back
#define gcd(a,b) __gcd(a,b)

void solve(){
    int n,q;
    cin >> n >> q;
    string s;
    cin >> s;
    vector<vector<int>> pre(n + 1,vector<int> (26));
    rep(i,0,n){
        pre[i + 1][s[i] - 'a'] = 1;
    }
    rep(i,0,26){
        rep(j,1,n + 1)pre[j][i] += pre[j - 1][i];
    }
    rep(I,0,q){
        int l,r;
        cin >> l >> r;
        ll ans = 0;
        rep(i,0,26){
            ans += (ll)(pre[r][i] - pre[l-1][i]) * (i + 1);
        }
        cout << ans;ln;
    }
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL); 
    //gen_factorial(1e6);   
    int test=1;
    // cin>>test;   
    while(test--)
        solve();
    return 0;
}