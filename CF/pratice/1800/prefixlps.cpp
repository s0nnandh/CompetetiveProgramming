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
#define len(x) (int)x.size()
#define all(x) x.begin(),x.end()
#define vi vector<int>
#define vl vector<ll>

vector<int> LPS(string s){

	vector<int> lps;
	int m = s.size();
	lps.resize(m);
	int i = 1,len = 0;
	while(i < m){
		if(s[i] == s[len]){
			lps[i] = len + 1;
			++i;
			++len;
		}
		else{
			if(len){
				len = lps[len - 1];
			}
			else{
				lps[i] = 0;
				++i;
			}
		}
	}
	return lps;

}		

void solve(){
    
    string s;
	cin >> s;
	int n = len(s);
	if(n == 1){
		cout << s;
		ln;
		return;
	}
	int l = 0,r = n - 1;
	string ok1 = "",ok2 = "";
	while(l < r){
		if(s[l] != s[r])break;
		// ok1 += s[l];
		// ok2 = s[r] + ok2;
		++l;
		--r;
	}	
	// search for palindrom in left
	string a = "";
	rep(i,l,r + 1)a += s[i];
	string ar = a;
	reverse(all(ar));
	string pre = a + '#' + ar;
	auto lps1 = LPS(pre);
	// cout << pre;ln;
	// for(auto x : lps1)cout << x << " ";
	// ln;
	string suf = ar + '#' + a;
	auto lps2 = LPS(suf);
	string w = "";
	if(lps1.back() > lps2.back()){
		rep(i,0,lps1.back())w += a[i];
	}
	else{
		rep(i,0,lps2.back())w += ar[i];
		reverse(all(w));
	}
	// cout << w;ln;
	cout << s.substr(0,l) + w + s.substr(n - l,l);ln;
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