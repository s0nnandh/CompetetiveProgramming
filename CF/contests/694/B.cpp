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



void solve(){


    int n,x;
    cin >> n >> x;
    ll sum = 0;
    vector<ll> v(n);
    for(auto &i : v)cin >> i;
    bool ok = 1;
    rep(i,0,n)ok &= (v[i] % x == 0);
    if(!ok){
        int c = 2;
        rep(i,0,n){
            if(v[i] % x){
                c = 1;
            }
            sum += c * v[i];
        }
        cout << sum;ln;
        return;
    }
    rep(i,0,n){
        if(v[i] % x == 0){
            if(i == 0){
                ll k = v[i];
                int cnt = 0;
                while(v[i] % x == 0){
                    v[i] /= x;
                    ++cnt;
                }
                sum += (cnt + 1) * k;
            }
            else sum += 2 * v[i];
        }
    }
    cout << sum;ln;

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
