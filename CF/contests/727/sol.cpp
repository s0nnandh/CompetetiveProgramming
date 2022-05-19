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
    vector<pl> v(n);
    rep(i,0,n)cin >> v[i].sc >> v[i].fr;
    sort(v.rbegin(),v.rend());
    int left = 0,right = n-1;
    ll req_items = v.back().fr,items = 0,cost = 0;
    while(left < n){
        // dbg(req_items,left,v[left].fr,v[left].sc);
        ll k = v[left].sc,how_many;
        v[left].sc -= min(req_items,v[left].sc);
        how_many = min(req_items,k);
        req_items -= min(req_items,k);
        cost += 2 * how_many;
        if(v[left].sc == 0)++left;
        if(req_items == 0)break;
    }
    // dbg(cost);
    items = v.back().fr;
    while(right >= left){
        // dbg(cost,items);
        if(right == left){
            cost += min(max(0LL,v[right].fr - items) + v[right].sc,2 * v[right].sc);
            break;
        }
        cost += max(0LL,v[right].fr - items) + v[right].sc;
        items += max(0LL,v[right].fr - items) + v[right].sc;  
        --right; 
    }
    cout << cost;ln;
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