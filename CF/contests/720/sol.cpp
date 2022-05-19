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

int p1 = 1e9 + 7;
int p2 = 1e9 + 9;

void solve(){

    int n;
    cin >> n;

    vector<int> v(n);
    for(auto &i : v)cin >> i;
    vector<pair<pi,pi>> ans;
    bool now = 1;
    rep(i,1,n){
        if(gcd(v[i],v[i-1]) != 1){
            int k = min(v[i],v[i-1]);
            int p = (now ? p1 : p2);
            //cout << i + 1 << " " << i + 2 << " " << p << " " << k;ln;
            ans.pb({{i,i + 1},{p,k}});
            v[i] = k;
            now = !now;
        }
    }
    cout << ans.size();ln;
    for(auto x : ans)cout << x.fr.fr << " " << x.fr.sc << " " << x.sc.fr << " " << x.sc.sc << endl;
    
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