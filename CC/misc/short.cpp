#define ll long long
#include<bits/stdc++.h>
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
#define all(x) x.begin(),x.end()

void solve(){
    int n,m;
    cin >> n >> m;
    vector<int> v(n),l(n),r(n);
    for(auto &i : v)cin >> i;
    l[0] = 0;
    int one = (v[0] == 1 ? 0 : -1);
    rep(i,1,n){
        if(v[i] == 1)one = i;
        l[i] = one;
    }
    r[n-1] = (v[n-1] != 0 ? n-1 : -1); 
    int two = (v.back() == 2 ? n-1 : -1);
    for(int i = n-2;i >= 0;--i){
        if(v[i] == 2)two = i;
        r[i] = two;
    }
    
    rep(i,0,m){
        int a;
        cin >> a;
        --a;
        if(a == 0){
            cout << 0 << " ";
            continue;
        } 
        int ans = 1e9;
        if(l[a] != -1)ans = a - l[a];
        if(r[a] != -1)ans = min(ans,r[a]-a);
        cout << (ans == 1e9 ? -1 : ans) << " ";
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