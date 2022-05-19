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

ll ninf = -1e18,pinf = 1e18;
vector<ll> p,pre;
void solve(){   
	
	ll n;
	cin >> n;
	ll k = n;
	int id = lower_bound(pre.begin(),pre.end(),n) - pre.begin();	
	if(pre[id] == k){
		cout << k;ln;
		return;
	}
	// ++id;
	ll val = pre[id];
	// dbg(val,id);
	for(int i = id;i >= 0;--i){
		if(val - p[i] >= k)val -= p[i];
	}
	cout << val;ln;

}   


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL); 
    //gen_factorial(1e6);    
	ll k = 1;
	p.resize(40);
	pre.resize(40);
	int sz  = 0;
	p[0] = 1;
	while((double)k * 3.0 < 2e18){		
		k *= 3;
		++sz;
		p[sz] = k;
	}
	pre[0] = 1;
	rep(i,1,40){
		pre[i] += p[i] + pre[i-1];
	}
    int test=1;
    cin>>test;   
    while(test--)
        solve();
    return 0;
}