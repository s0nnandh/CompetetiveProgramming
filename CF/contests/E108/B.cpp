#include<bits/stdc++.h>
#include<stdio.h>
#define ll long long
#define ull unsigned long long
#define ln cout<<"\n"
using namespace std;
//#define dbg(x) cout<<#x<<" = "<<x<<" "
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
#define dbg(...) cerr << "[ ]" << endl
#endif

#define pi pair<int,int>

int n,m,k;


int mem(int i,int j,vector<int> &dp,int c){
    if(c == 0){
        if(i == 1 && j == 1)return 1;
        return 0;
    }
    if(c < 0 || i == 0 || j == 0)return 0;
    if(dp[c] == -1){
        dp[c] = mem(i-1,j,dp,c-j) | mem(i,j-1,dp,c-i);
    }   
    return dp[c];
}

void solve(){
    cin >> n >> m >> k;
    // --n;--m;
    vector<int> dp(k+1,-1);
    dp[0] = 1;
    cout << (mem(n,m,dp,k)?"YES":"NO");ln;
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

