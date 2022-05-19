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
   
    int n;
    cin >> n;
    vector<int> v(n);
    int sum = 0;
    for(auto &i : v){
        cin >> i;
        sum += i;
    }
    vector<bool> dp(sum + 1);
    dp[0] = 1;
    rep(i,0,n){
        for(int j = sum;j >= 0;--j){
            if(dp[j] && j + v[i] <= sum)dp[j + v[i]] = 1;
        }
    }
    int m = 1e9;
    for(int i = sum/2;i >= 0;--i){
        if(dp[i]){
            m = min(m,max(i,sum - i));
        }
    }
    cout << m;ln;
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