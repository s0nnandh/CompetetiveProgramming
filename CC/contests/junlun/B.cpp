#include<bits/stdc++.h>
#define ll long long
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
#define gcd(a,b) __gcd(a,b)
#define sz(x) (int)x.size()
#define all(x) x.begin(),x.end()
#define vi vector<int>
#define vl vector<ll>


void solve(){
	
    int n;
    cin >> n;
    vi ev,od,v(n);
    rep(i,0,n){
        int a;
        cin >> a;
        v[i] = a;
        if(a&1)od.pb(a);
        else ev.pb(a);
    }
    vector<int> ans(n);
    for(int i = n - 1;i >= 0 && od.size();i -= 2){
        ans[i] = od.back();
        od.pop_back();
    }
    for(int i = n - 2;i >= 0 && ev.size();i -= 2){
        ans[i] = ev.back();
        ev.pop_back();
    }
    int id = 0;
    rep(i,0,n){
        if(ans[i] == 0){
            id = i;
            break;
        }
    }
    while(ev.size()){
        ans[id] = ev.back();
        ev.pop_back();
        id += 2;
    }
    while(od.size()){
        ans[id] = od.back();
        od.pop_back();
        id += 2;
    }
    for(auto x : ans)cout << x << " ";
    ln;
}	

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL); 
    // gen_factorial(1e6);  	
    int test=1;
	cin>>test;   
    while(test--)
        solve();
    return 0;
}
