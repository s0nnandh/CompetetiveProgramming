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

    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<ll> l(n+2),r(n+2);
    ll k = 0;
    rep(i,1,n+1){
        if(s[i-1] == '.'){
            l[i] = l[i-1] + k;
        }
        else{
            ++k;
            l[i] = l[i-1];
        }
    }
    k = 0;
    for(int i = n;i >= 1;--i){
        if(s[i-1] == '.'){
            r[i] = r[i+1] + k;
        }
        else{
            ++k;
            r[i] = r[i+1];
        }
    }
    ll ans = 1e18;
    rep(i,1,n+1){
        ans = min(ans,l[i] + r[i]);
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