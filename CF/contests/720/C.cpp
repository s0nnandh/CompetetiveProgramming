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

ll p = 1e9 + 7;
ll p1 = 1e9 + 21;

void solve(){

    int n;
    cin >> n;
    vector<ll> v(n);
    rep(i,0,n){
        cin >> v[i];
    }
    vector<pair<pl,pl>> ans;
    int k = 0;
    rep(i,1,n){
        if(gcd(v[i],v[i-1]) != 1){
            ++k;
            if(v[i] > v[i-1]){
                int s = v[i-1];
                // v[i] = v[i-1];
                if(i >= 2 && v[i-2] == p){
                    ans.pb({{i,i+1},{p1,v[i-1]}});
                    v[i-1]= p1;
                }
                else {
                ans.pb({{i,i+1},{p,v[i-1]}});
                v[i-1]= p;
                }
                v[i] = s;
            }
            else{
                if(i >= 2 && v[i-2] == p){
                    ans.pb({{i,i+1},{p1,v[i]}});
                    v[i-1] = p1;
                }
                else{
                    ans.pb({{i,i+1},{p,v[i]}});
                    v[i-1] = p;
                }
            }
            // ++i;
        }
         
    }
    cout << k;ln;
    for(auto x : ans){
        cout << x.fr.fr << " " << x.fr.sc << " " << x.sc.fr << " " << x.sc.sc ;ln;
    }
    // rep(i,0,n){
    //     cout << v[i] << " ";
    // }
    // ln;
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