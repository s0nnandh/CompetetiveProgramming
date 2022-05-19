// https://www.codechef.com/MARCH21B/problems/PAPARAZI

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

ll cross(pi o,pi a,pi b){
    pi oa = {a.fr-o.fr,a.sc-o.sc};
    pi ab = {b.fr-a.fr,b.sc-a.sc};
    return oa.fr*ab.sc  - oa.sc*ab.fr;
}

void solve(){   
   
    int n;
    cin >> n;
    vector<pl> v(n);
    rep(i,0,n){
        v[i].fr = i + 1;
        cin >> v[i].sc; 
    }
    // Andrews algorithm 
     ll ans = 1;
    vector<pl> s;
    s.pb(v[0]);s.pb(v[1]);
    rep(i,2,n){
        int k = s.size();
        while(k > 1 && cross(v[i],s[k-2],s[k-1]) >= 0){
            s.pop_back();
            --k;
        } 
        ans = max(ans,i - s.back().fr + 1);     
        s.pb(v[i]);
    }
   
    // rep(i,1,(int)s.size()){
    //     ans = max(ans,s[i].fr - s[i-1].fr);
    // }
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