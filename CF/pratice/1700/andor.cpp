// https://codeforces.com/problemset/problem/1368/D

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
#define pl pair<ll,ll> 
#define fr first
#define sc second
#define pb push_back

void solve(){

	int n;
	cin >> n;
	vector<int> v(20);
	rep(i,0,n){
		int a;
		cin >> a;
		rep(j,0,20){
			if(a&(1<<j))v[j]++;
		}
	}
	ll ans = 0;
	while(1){
		ll cnt = 0,sum = 0;
		rep(i,0,20){
			if(v[i]){
				++cnt;
				sum |= (1 << i);
				--v[i];
			}
		}
		if(cnt == 0)break;
		ans += sum * sum;
	}
	cout << ans;ln;
   
}       
 


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);    
    int test=1;
    // cin>>test;   
    while(test--)
        solve();
    return 0;
}

// Have to observe that the number of one bits are presereved in any operation . Hence optimal to shift bits
// to larger numbers . 
// Very nice observation .(( For bitmask prbolms observe .))