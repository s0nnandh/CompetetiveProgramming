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
#define dbg(...) cerr << "" << endl
#endif

#define pi pair<int,int>
#define pl pair<ll,ll> 
#define fr first
#define sc second
#define pb push_back
#define gcd(a,b) __gcd(a,b)


void solve(){
    
	string s;
	cin >> s;	
	string t;
	cin >> t;
	int n = s.size();
	map<char,bool> mp;
	vector<vector<int>> v(26);
	rep(i,0,n){
		mp[s[i]] = 1;
		v[s[i]-'a'].pb(i);
	}
	for(auto x : t){
		if(mp[x] == 0){
			cout << -1;ln;
			return;
		}
	}
	int i = 0,ptr = -1;
	int ans = 0;
	while(i < (int)t.size()){
		++ans;
		if(ptr == -1){
			ptr = v[t[i]-'a'][0];
			++i;
		}
		if(i == (int)t.size())break;
		while(ptr != -1 && i < (int)t.size()){
			auto p = upper_bound(v[t[i]-'a'].begin(),v[t[i]-'a'].end(),ptr);

			if(p == v[t[i]-'a'].end()){
				ptr = -1;
			}	
			else{
				int j = p - v[t[i]-'a'].begin();
				ptr = v[t[i]-'a'][j];
				++i;
			}
		}

	}

	cout << ans;ln;

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