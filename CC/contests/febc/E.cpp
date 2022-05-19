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

void solve(){
	int n;
	cin >> n;
	vector<set<string>> v(26);
	rep(i,0,n){
		string s;
		cin >> s;
		//cout << s ;ln;
		int k = s[0]-'a';
		//dbg(k);
		string t = s.substr(1);
		//cout << t;ln;
		v[k].insert(t);
	}
	int ans = 0;
	rep(i,0,26){
		rep(j,i+1,26){
			int m = min(v[i].size(),v[j].size());
			if(m == 0)continue;
			set<string> t ;
			set_intersection(v[i].begin(),v[i].end(),v[j].begin(),v[j].end(),inserter(t,t.begin()));
			ans+=(v[j].size()-t.size())*(v[i].size()-t.size());
		}
	}
	cout << 2*ans;ln;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);       
    int test=1;
    cin>>test;   
    while(test--)
        solve();
    return 0;
}

