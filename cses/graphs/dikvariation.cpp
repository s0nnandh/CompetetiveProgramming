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

vector<vector<pl>> adj;
const ll inf = 1e18;
void dijkstra(int s, vector<vector<ll>> & d) {

    d[s][0] = 0;
    d[s][1] = 0;
    using pii = pair<ll,pi>;
    priority_queue<pii, vector<pii>, greater<pii>> q;
    q.push({0, {s,0}});
    while (!q.empty()) {
        int v = q.top().second.fr;
        ll d_v = q.top().first;
        int type = q.top().sc.sc;
        q.pop();
        // dbg(d_v,type,v + 1);
        if (d_v != d[v][type]){
			d[v][type] = min(d[v][type],d_v);
            continue;
		}

        for (auto edge : adj[v]) {
            int to;ll len;
            tie(to,len) = edge;
            if(type == 0){
                if(d[v][0] + len < d[to][0]){
                    d[to][0] = d[v][0] + len;
                    q.push({d[to][0],{to,0}});
                }
                if(d[v][0] + len/2 < d[to][1]){
                    d[to][1] = d[v][0] + len/2;
                    q.push({d[to][1],{to,1}});
                }
            }
            else{
                if(d[v][1] + len < d[to][1]){
                    d[to][1] = d[v][1] + len;
                    q.push({d[to][1],{to,1}});
                }
            }
            // if (d[v] + len < d[to]) {
            //     if(type == 0){
            //         ll k = len;
            //         d[to] = d[v] + (len/2);
            //         q.push({d[to],{to,1}});
            //         q.push({d[v] + k,{to,0}});
            //     }
            // }
        }
    }
}

void solve(){
    int n,m;
    cin >> n >> m;
    adj.resize(n);
    rep(i,0,m){
        int a,b,c;
        cin >> a >> b >> c;
        --a;--b;
        adj[a].pb({b,c});
    }
    vector<vector<ll>> d(n,vector<ll> (2,inf));
    vector<int> p;
    dijkstra(0,d);
    cout << d[n-1][1];ln;
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