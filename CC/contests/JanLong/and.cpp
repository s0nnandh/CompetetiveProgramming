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

int n,m;
unordered_set<ll> ans;
void solve(){
    ans.clear();
    cin >> n >> m;
    vector<ll> a(n),b(m);
    ans.insert(0);
    rep(i,0,n){
        cin >> a[i];
        ans.insert(a[i]);
    }
    rep(i,0,m)cin >> b[i];
    unordered_set<ll> s = ans;
    while(1){
        for(auto x : s){
            rep(i,0,n){
                ans.insert(x|a[i]);
            }
            rep(i,0,m){
                ans.insert(x&b[i]);
            }
        }
        if(ans.size() == s.size())break;
        s = ans;
    }
    
    cout << ans.size();
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

