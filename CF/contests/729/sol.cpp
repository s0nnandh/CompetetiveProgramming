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
    int n,m;
    cin >> n >> m;
    vector<string> v(n);
    for(auto &i : v)cin >> i;
    int ans = 0;
    vector<vi> pre(n,vi(m + 1));
    rep(i,0,n)rep(j,0,m)pre[i][j + 1] = (v[i][j] == '*' ? 1 : 0);
    rep(i,0,n)rep(j,1,m + 1)pre[i][j] += pre[i][j - 1];
    auto q = [&](int row,int l,int r){
        return pre[row][r] - pre[row][l - 1];
    };
    rep(i,0,n){
        rep(j,0,m){
            if(v[i][j] == '*'){
                ++ans;
                int l = j - 1,r = j + 1,k = i + 1;
                while(l >= 0 && r < m && k < n){
                    if(q(k,l + 1,r + 1) != r - l + 1)break;
                    ++ans;
                    --l;
                    ++r;
                    ++k;
                }
            }
        }
    }
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
