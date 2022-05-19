// https://codeforces.com/problemset/problem/1234/D

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


struct Fenwick{
	int n;
	vector<vector<int>> v;

	Fenwick(int nn){
		n = nn + 1;
		v.resize(26);
		rep(i,0,26)v[i].resize(n);
	}
	void add(int a,int i,int x){
		while(i < n){
			v[a][i] += x;
			i += i & (-i);
		}

	}
	int get(int a,int i){
		int x = 0;
		while(i > 0){
			x += v[a][i];
			i -= i & (-i);
		}
		return x;
	}
	void update(int a,int b,int i){
		add(a,i,-1);
		add(b,i,1);
	}	
	int ans(int l,int r){
		int k = 0;
		rep(i,0,26){
			k += (get(i,r) - get(i,l-1) >= 1);
		}
		return k;
	}

};


void solve(){

	string s;
	cin >> s;
	int n = s.size();
	Fenwick f(n);
	rep(i,0,n){
		f.add(s[i] - 'a',i + 1,1);
	}	
	int q;
	cin >> q;
	rep(i,0,q){
		int x;
		cin >> x;
		if(x == 1){
			int pos;char c;
			cin >> pos >> c;
			f.update(s[pos-1] - 'a',c - 'a',pos);
			s[pos-1] = c;
		}
		else{
			int l,r;
			cin >> l >> r;
			cout << f.ans(l,r);ln;
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