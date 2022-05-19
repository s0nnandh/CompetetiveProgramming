// https://atcoder.jp/contests/arc120/tasks/arc120_b

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

const int mod = 998244353;

void solve(){   
   
    int h,w;
    cin >>h >> w;
    vector<string> v(h+1);
    rep(i,1,h + 1){
        cin >> v[i];
    }
    map<int,pair<int,pi>> mp;
    rep(i,1,h + 1){
        rep(j,0,w){
            // cout << v[i][j] << " " << i + j;ln;
            if(v[i][j] == '.'){
                mp[i+j].fr++;
            }
            else if(v[i][j] == 'R'){
                mp[i+j].sc.fr++;
            }
            else mp[i+j].sc.sc++;
        }
    }
    ll ans = 1;
    for(auto x : mp){
        pair<int,pi> p = x.sc;
        // dbg(x.fr,p.fr,p.sc.fr,p.sc.sc);
        if(p.sc.fr && p.sc.sc){
            cout << 0;
            ln;
            return;
        }
        else if(p.sc.fr == 0 && p.sc.sc == 0){
            ans *= 2;
            ans %= mod;
        }
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

// HAve to observe that the positions having the sum i + j same must be coulred the same . 