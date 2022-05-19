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
#define all(x) x.begin(),x.end()

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

typedef tree<int,null_type,less<int>,rb_tree_tag,
tree_order_statistics_node_update> indexed_set;


void solve(){   
   
    int n;
    cin >> n;
    vector<int> v(n);
    for(auto &i : v)cin >> i;
    if(n <= 2){
        cout <<  "YES";
        ln;
        return;
    }
    indexed_set s;
    s.insert(v[0]);
    s.insert(v[1]);
    int prev = v[1];
    bool pos = 1;
    rep(i,2,n){
        s.insert(v[i]);
        int cur_idx = s.order_of_key(v[i]);
        int prev_idx = s.order_of_key(prev);
        pos &= (abs(cur_idx - prev_idx) <= 1);
        prev = v[i];
    }
    cout << (pos ? "YES" : "NO");
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