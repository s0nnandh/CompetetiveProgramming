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
    multiset<pl> s;
    rep(i,0,n){
        ll a;
        cin >> a ;
        s.insert({i+1,a});
    }
    int q;
    cin >> q;
    // ll ans = 0;
    rep(i,0,q){
        int a,x;
        cin >> a >> x;
        ll ans = 0,d = 0;
        while(x){
            auto cur = s.lower_bound({a,0});
            if(cur == s.end())break;
            pl p = *cur;
            d = p.fr - a;
            if(p.sc <= x){                
                x-=p.sc;
                ans+=d*p.sc;
                s.erase(cur);
            }
            else{
                p.sc-=x;
                ans+=d*x;
                x = 0;
                s.erase(cur);
                s.insert(p);
            }
        }
        cout << ans;ln;
    }   
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