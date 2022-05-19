// https://atcoder.jp/contests/abc186/tasks/abc186_d

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

vector<vector<ll>> dp(61,vector<ll> (61));

// ll f(int a,int b){
//     if(a == 0 || b == 0){
//         dp[a][b] = 1;
//         return 1;
//     }
//     if(dp[a-1][b] == 0){
//         dp[a-1][b] = f(a-1,b);
//     }
//     if(dp[a][b-1] == 0){
//         dp[a][b-1] = f(a,b-1);
//     }
//     dp[a][b] = dp[a][b-1] + dp[a-1][b];
//     return dp[a][b];

// }

// nck by dp . . . .. . . . . 


void solve(){   
   
    ll a,b,k;
    cin >> a >> b >> k;

    rep(i,0,60){
        dp[i][0] = 1;
    }
    rep(i,1,60){
        rep(j,1,i+1){
            dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
        }
    }
    string ans = "";
    while(a && b){
        // string starting with a
        // dbg(k);
        // dbg(dp[a+b-1][a-1],a,b);
        if(dp[a+b-1][a-1] < k){
            // then start from b instead
            k -= dp[a+b-1][a-1];
            ans += 'b';
            --b;
        }
        else{
            ans += 'a';
            --a;
        }
    }
    while(a){
        ans += 'a';
        --a;
    }
    while(b){
        ans += 'b';
        --b;
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