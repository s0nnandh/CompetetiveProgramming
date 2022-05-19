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

	int n;
	cin >> n;	
	string s;
	cin >> s;
	int on = 0,z = 0,two = 0;
	for(auto x : s){
		on += (x == '1' ? 1 : 0);
		z += (x == '0' ? 1 : 0);
		two += (x == '2' ? 1 : 0);
	}
	int h = n/3;
	for(int i = 0;i < n && z < h;++i){
		int v = s[i] - '0';
		if(v == 1 && on > h){
			--on;
			++z;
			s[i] = '0';
		}
		else if(v == 2 && two > h){
			--two;
			++z;
			s[i] = '0';
		}
	}	
	for(int i = n - 1;i >= 0 && two < h;--i){
		int v = s[i] - '0';
		if(v == 0 && z > h){
			--z;
			++two;
			s[i] = '2';
		}
		else if(v == 1 && on > h){
			--on;
			++two;
			s[i] = '2';
		}
	}
	for(int i = 0;i < n && on < h;++i){
		int v = s[i] - '0';
		if(v == 2 && two > h){
			--two;
			++on;
			s[i] = '1';
		}
	}
	for(int i = n - 1;i >= 0 && on < h;--i){
		int v = s[i] - '0';
		if(v == 0 && z > h){
			--z;
			++on;
			s[i] = '1';
		}
	}
	
	cout << s;ln;
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
