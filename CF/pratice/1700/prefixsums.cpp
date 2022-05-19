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
#define len(x) (int)x.size()
#define all(x) x.begin(),x.end()
#define vi vector<int>
#define vl vector<ll>


void solve(){
	
    int n,k;
    cin >> n >> k;
    int nx = 2 * k + 2;
    vi v(n),pre(nx);
    for(auto &i : v)cin >> i;
    rep(i,0,n/2){
        int big = max(v[i],v[n - i - 1]);
        int small = min(v[i],v[n - i - 1]);
        int sum = big + small;

        // 1 move
        int canIncrease1 = sum +  k - small;
        pre[sum + 1] += 1;
        pre[canIncrease1 + 1] -= 1;

        int uptoDec1 = sum - 1;
        pre[small + 1] += 1;
        pre[uptoDec1 + 1] -= 1;

        // 2 moves
        pre[canIncrease1 + 1] += 2;
        pre[2*k + 1] -= 2;

        pre[0] += 2;
        pre[small + 1] -= 2;
    }

    rep(i,1,nx)pre[i] += pre[i - 1];
    int ans = 1e9;
    rep(i,2,2*k + 1)ans = min(ans,pre[i]);
    cout << ans;ln;
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
