// https://atcoder.jp/contests/arc117/tasks/arc117_b

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

void solve(){   
   
    
    int n,k;
    cin >> n >> k;
    vector<vector<int>> a(n + 1,vector<int> (n + 1));
    rep(i,1,n + 1){
        rep(j,1,n + 1)cin >> a[i][j];
    }
    int l = 0, r = 1e9,mid,ans = 0;
    vector<vector<int>>  pre(n + 1,vector<int> (n + 1));
    int lim = ((k*k) / 2) + 1;
    while(l <= r){
        mid = (l + r)/2;
        // dbg(l,r);
        // prefix calculation 
        rep(i,1,n + 1){
            rep(j,1,n + 1){
                pre[i][j] = (a[i][j] > mid ? 1 : 0);
                pre[i][j] += pre[i-1][j] + pre[i][j-1] - pre[i-1][j-1];
            }
        }
        // start of the k x k square 
        bool found = 0;   
        rep(i,1,n + 1){
            rep(j,1,n + 1){
                if(i + k - 1 <= n && j + k - 1 <= n){
                    if(pre[i + k - 1][j + k - 1] - pre[i+k - 1][j - 1] - pre[i - 1][j + k - 1] + pre[i-1][j-1] < lim)found = 1;
                }       
            }
        }
        if(found){
            r = mid - 1;
            ans = mid;
        }
        else l = mid + 1;
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