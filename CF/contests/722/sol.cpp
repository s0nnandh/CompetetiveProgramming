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

int timer(){
	static int t = 0;
	t++;
	return t;
}
const int nx = 3e5 + 1;
int start[nx],en[nx];

void solve(){
	
	int n;
	cin >> n;
	vector<vector<int>> g1(n),g2(n);
	// soroush
	rep(i,1,n){
		int a;
		cin >> a;
		--a;
		g1[a].pb(i);
	}
	// k
	rep(i,1,n){
		int a;
		cin >> a;
		--a;
		g2[a].pb(i);
	}
	// K dfs
	function<void(int)> Kdfs = [&](int u){
		start[u] = timer();
		for(auto x : g2[u])Kdfs(x);
		en[u] = timer();
	};
	Kdfs(0);
	set<pi> s;
	int ans = 0;
	function<void(int)> Sdfs = [&](int u){
		auto it = s.lower_bound({start[u],u});
		bool can = 1;
		if(it != s.end() && en[it -> sc] < en[u]){
			// u is a ancestor so dont add
			can = 0;
		}
		pi remove_this = {-1,-1};
		if(it != s.begin()){
			it--;
			// check if ancestor
			int node = it -> sc;
			if(start[node] < start[u] && en[node] > en[u]){
				remove_this = *it;
			}
		}
		if(can){
			if(remove_this.fr != -1){
				s.erase(remove_this);
			}
			s.insert({start[u],u});
			ans = max(ans,(int)s.size());
		}
		for(auto x : g1[u])Sdfs(x);
		// rollback
		if(can){
			s.erase({start[u],u});
			if(remove_this.fr != -1)s.insert(remove_this);
		}
	};	
	Sdfs(0);
	cout << ans;ln;
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
