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

int ans(vector<int> *adj,int u,int v){
    int children = adj[u].size();
    //dbg(children);
    if(children == 0)return 0;
    if(v%children != 0)return v;
    ll sum = 0;
    for(auto x : adj[u]){
        sum+=ans(adj,x,v/children);
    }
    return sum;
}
void solve(){
    int n;
    cin >> n;
    vector<int> adj[n+1],parent(n+1);
    rep(i,1,n){
        int a;
        cin >> a;
        adj[a].push_back(i+1);
        parent[i+1] = a;
    }
    vector<int> depth(n+1,-1);
    depth[1] = 0;
    queue<int> q;
    q.push(1);
    while(!q.empty()){
        int v = q.front();
        q.pop();
        if(v != 1)depth[v] = depth[parent[v]]+1;
        for(auto x : adj[v]){
            q.push(x);
        }
    }
    
    int qq;
    cin >> qq;
    rep(i,0,qq){
        int v,w;
        cin >> v >> w;
        cout << ans(adj,v,w);ln;
    }
    
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);    
    int test=1;
    //cin>>test;   
    while(test--)
        solve();
    return 0;
}

