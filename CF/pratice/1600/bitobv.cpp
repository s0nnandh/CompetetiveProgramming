// https://codeforces.com/problemset/problem/1395/C

#include<bits/stdc++.h>
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
#define dbg(...) cerr << "" << endl
#endif

#define pi pair<int,int>
#define pl pair<ll,ll> 
#define fr first
#define sc second
#define pb push_back
#define gcd(a,b) __gcd(a,b)

void solve(){

	int n,m;
	cin >> n >> m;
	vector<int> a(n),b(m);
	rep(i,0,n)cin >> a[i];
	rep(i,0,m)cin >> b[i];
	rep(i,0,(1<<9)){
		bool f = 1;
		rep(j,0,n){
			bool d = 0;
			rep(k,0,m){
				if(((a[j]&b[k])|i) == i){
					d = 1;
				}
			}
			f&=d;
		}
		if(f == 1){
			cout << i;ln;
			return;
		}
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

// very nice problem (obsevation ) . If u find small constraints look for propeties that would hold if some 
// x was the answer and basicalluy first idea must be brute force . 
// here observation is that is x is answer than then for each i there exists a j such that ( ai & aj ) | x == x beeaceuse
// bacuse ci | x is x. 