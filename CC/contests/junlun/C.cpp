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
#define vi vector<int>
#define vl vector<ll>

bool check(ll b){
    while(b % 2 == 0){
        b /= 2;
    }
    if(b == 1)return 1;
    // while(b % 5 == 0){
    //     b /= 5;
    // }
    if(b == 1)return 1;
    return 0;
}

void solve(){
	
    ll a,b;
    cin >> a >> b;
    cout << (check(b) ? "Yes" : "No");ln;   
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
