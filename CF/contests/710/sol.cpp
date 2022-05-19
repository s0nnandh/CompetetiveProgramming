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
#define dbg(...) cerr << "" << endl
#endif

#define pi pair<int,int>
#define pl pair<ll,ll> 
#define fr first
#define sc second
#define pb push_back

void solve(){

    int n,k;
    cin >> n >> k;
    vector<int> v;
    string s;
    cin >> s;
    rep(i,0,n){
        if(s[i] =='*'){
            v.pb(i);
        }
    }
    int sz = v.size();
    int ans = 0,prev = -1;
    rep(i,0,sz){
        if(i == 0 || i == sz-1){
            ++ans;
            prev = i;
        }
        else if(v[i]-prev >= k){
            dbg(v[i],prev);
            prev = v[i];
            dbg(prev);
            ++ans;
        }
    }
    cout << ans;ln;

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