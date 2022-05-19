// https://atcoder.jp/contests/abc186/tasks/abc186_d

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
   
    int n;
    cin >> n;
    vector<int> a(n + 1),b(n + 1),c(n + 1);
    set<int> s;
    rep(i,1,n + 1){
        cin >> a[i]; 
        s.insert(a[i]);
    }
    rep(i,1,n + 1)cin >> b[i];
    rep(i,1,n + 1)cin >> c[i];
    map<int,ll> mpa,mpb;
    vector<ll> newb(n + 1);
    rep(i,1,n + 1){
        newb[i] = b[c[i]];
        mpb[newb[i]]++;
        mpa[a[i]]++;
        // dbg(b[i]);
    }
    ll ans = 0;
    for(auto x : s){
        ans += mpa[x] * mpb[x];
    }   
    cout << ans;ln;
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