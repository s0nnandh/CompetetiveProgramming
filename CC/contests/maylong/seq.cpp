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

const int mx = 4e6 + 5;

vector<int> p(mx);

vector<vector<int>> d(mx);

const int nx = 1e6 + 1;

vector<ll> ans(nx);

void solve(){
   
    int k;
    cin >> k;
    // cout << "Divisors of " << 4*k + 1 << " : ";
    // for(auto x : d[4*k + 1])cout << x << " ";
    // ln;
    // cout << k << ' ' <<  ans[k];ln;

    cout << ans[k] ;ln;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL); 
    for(int i = 3;i < mx;i += 2){
        int t;bool up;  
        up = (i%4 == 1?1:0);
        t = (up?4*i:i);        
        for(int j = i; j < mx ;j += t){
            // if(i == 3)dbg(j,t,up);
            d[j].pb(i);            
            ((!up && j == 7*i)?up = 1:up = up);
            (up?t = 4*i:t += t);
        }

    }
    for(int k = 1;k < nx ; ++k){
        ll rem = 2*k - 1;
        ans[k] += 4*k + 1;
            for(int i = (int)d[4*k + 1].size() - 1; i >= 0;--i){
                int t = rem/d[4*k + 1][i];
                int c = rem % d[4*k + 1][i];
                if(c == d[4*k + 1][i] - 1){
                    ++t;
                }
                rem -= t;
                ans[k] += t * d[4*k + 1][i];
                
            }
        ans[k] += rem;
    }
    //gen_factorial(1e6);   
    int test=1;
    cin>>test;   
    while(test--)
        solve();
    return 0;
}