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
#define all(x) x.begin(),x.end()



void solve(){
    
    int n,k;
    cin >> n >> k;
    string S;
    cin >> S;
    vector<vector<int>> s(k,vector<int> (2));
    rep(i,0,n){
        if(S[i] == '?')continue;
        s[i%k][S[i] - '0']++;
    }
    int z = 0,on = 0;
    rep(i,0,k){
        if(s[i][0] && s[i][1]){
            cout << "NO";
            ln;
            return;
        }
        z += (s[i][0] ? 1 : 0);
        on += (s[i][1] ? 1 : 0);
    }
    cout << (z > k/2 || on > k/2 ? "NO" : "YES");ln;
    
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
