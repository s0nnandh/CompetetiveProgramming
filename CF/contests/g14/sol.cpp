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
#define dbg(...) cerr << "" << endl
#endif

#define pi pair<int,int>
#define fr first
#define sc second


void solve(){
    int n,m,x;
    cin >> n >> m >> x;
    vector<pi> v(n);
    rep(i,0,n){
        cin >> v[i].fr;
        v[i].sc = i;
    }
    sort(v.begin(),v.end());
    vector<int> ans(n);
    set<pi> s;
    rep(i,0,m){
        s.insert(v[i]);
        ans[v[i].sc] = i;
    }
    rep(i,m,n){
        auto cur = *s.begin();
        s.erase(s.begin());
        cur.fr += v[i].fr;
        ans[v[i].sc] = ans[cur.sc];
        s.insert(cur);
    }

    cout << "YES";ln;
    rep(i,0,n){
        cout << (ans[i] + 1)  << " ";
    }
    ln;

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL); 
    //gen_factorial(1e6);   
    int test=1;
    cin>>test;   
    while(test--)
        solve();
    return 0;
}