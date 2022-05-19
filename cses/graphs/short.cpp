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

vector<int> parent;
vector<vector<pair<int,ll>>> adj;
ll inf = 4e18;

void dijkstra(int s, vector<ll> & d, vector<int> & p) {
    int n = adj.size();
    d.assign(n, inf);
    p.assign(n, -1);

    d[s] = 0;
    // using pii = pair<int, int>;
    priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> q;
    q.push({0, s});
    while (!q.empty()) {
        int v = q.top().second;
        ll d_v = q.top().first;
        q.pop();
        if (d_v != d[v]){
			d[v] = min(d[v],d_v);
            continue;
		}

        for (auto edge : adj[v]) {
            int to = edge.first;
            ll len = edge.second;

            if (d[v] + len < d[to]) {
                d[to] = d[v] + len;
                p[to] = v;
                q.push({d[to], to});
            }
        }
    }
}

void solve(){
	int n,m;
	cin >> n >> m;
	// v.resize(n);
	adj.resize(n);
	rep(i,0,m){
		int a,b,c;
		cin >> a >> b >> c;
		--a;--b;
		adj[a].pb({b,c});
	}
	vector<ll> d;
	vector<int> p;
	dijkstra(0,d,p);
	for(auto x : d)cout << x << " ";
	ln;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL); 
    //gen_factorial(1e6);   
    int test=1;
    // cin>>test;   
    while(test--)
        solve();
    return 0;
}