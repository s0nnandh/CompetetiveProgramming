// https://codeforces.com/problemset/problem/1108/D

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

void solve(){
	
	int n;
	cin >> n;

	string s;
	cin >> s;
	// r 0 g 1 b 2
	map<int,char> mp;
	mp[0] = 'R';
	mp[1] = 'G';
	mp[2] = 'B';
	vector<pi> dp[3];
	rep(i,0,3)dp[i].resize(n);
	auto cost = [&](int i,int diff){
		int val;
		val = (s[i] == 'R'?0:(s[i] == 'G'?1:2));
		return !(diff == val);
	};
	dp[0][0].fr = !(s[0] == 'R');
	dp[1][0].fr = !(s[0] == 'G');
	dp[2][0].fr = !(s[0] == 'B');
	dp[0][0].sc = 0;
	dp[1][0].sc = 1;
	dp[2][0].sc = 2;
	rep(i,1,n){
		dp[0][i].fr = cost(i,0) + min(dp[1][i-1].fr,dp[2][i-1].fr);
		dp[1][i].fr = cost(i,1) + min(dp[0][i-1].fr,dp[2][i-1].fr);
		dp[2][i].fr = cost(i,2) + min(dp[0][i-1].fr,dp[1][i-1].fr);
		if(dp[0][i-1].fr < dp[1][i-1].fr){
			dp[2][i].sc = 0;
		}
		else dp[2][i].sc = 1;
		if(dp[0][i-1].fr < dp[2][i-1].fr){
			dp[1][i].sc = 0;
		}
		else dp[1][i].sc = 2;
		if(dp[1][i-1].fr < dp[2][i-1].fr){
			dp[0][i].sc = 1;
		}
		else dp[0][i].sc = 2;
		
	}

	cout << min(dp[0].back().fr,min(dp[1].back().fr,dp[2].back().fr));ln;
	auto process = [&](int i){
		string ans = "";
		int k = n - 1;
		while(k >= 0){
			ans = mp[i] + ans;
			i = dp[i][k].sc;
			--k;
		}
		cout << ans << endl;
	};
	if(dp[0].back().fr < dp[1].back().fr && dp[0].back().fr < dp[2].back().fr){
		process(0);
	}
	else if(dp[1].back().fr < dp[0].back().fr && dp[1].back().fr < dp[2].back().fr){
		process(1);
	}
	else{
		process(2);
	}
}	

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL); 
    // gen_factorial(1e6);   
    int test=1;
	// cin>>test;   
    while(test--)
        solve();
    return 0;
}

// Dp sub problems ending with R,G,B
