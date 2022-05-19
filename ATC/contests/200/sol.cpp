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



void solve(){


    int n;
    cin >> n;
    vector<int> v(n);
    rep(i,0,n)cin >> v[i];
    int N = min(n,8);
    vector<vector<int>> ans(200);
    rep(i,0,(1 << N)){
        vector<int> t;
        int s= 0;
        rep(j,0,N){
            if(i&(1<<j)){
                t.pb(j+1);
                s = (s + v[j]) % 200;
                // if(s >= 200)s -= 200;
            }
        }
        if(ans[s].size() != 0){
            cout << "YES";ln;
            cout << ans[s].size() << ' ';
            for(auto x : ans[s]){
                cout << x << ' ';
            }
            ln;
            cout << t.size() << ' ';
            for(auto x : t){
                cout << x << ' ';
            }
            ln;
            return;
        }
        ans[s] = t;
    }
    cout << "NO";ln;
    
    
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