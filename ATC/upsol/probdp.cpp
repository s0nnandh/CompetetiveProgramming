// https://atcoder.jp/contests/abc184/tasks/abc184_d

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

double dp[101][101][101];

double ans(int a,int b,int c){
    if(dp[a][b][c])return dp[a][b][c];
    if(a == 100 || b == 100 || c == 100){
        dp[a][b][c] = 0;
        return 0;
    }
    double s = 0;
    s += (1 + ans(a+1,b,c)) * a / (a + b + c);
    s += (1 + ans(a,b + 1,c)) * b / (a + b + c);
    s += (1 + ans(a,b,c + 1)) * c / (a + b + c); 
    dp[a][b][c] = s; 
    
    return dp[a][b][c];
}

void solve(){   
    int a,b,c;
    cin >> a >> b >> c;
    cout << setprecision(15) << fixed;
    cout << ans(a,b,c);ln;
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