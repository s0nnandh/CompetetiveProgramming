// https://www.codechef.com/JUNE21B/problems/SUBTRCOV
#define ll long long
#include<bits/stdc++.h>
#define ull unsigned long long
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
#define dbg(...) {}
#endif

#define pi pair<int,int>
#define pl pair<ll,ll> 
#define fr first
#define sc second
#define pb push_back
#define gcd(a,b) __gcd(a,b)
#define all(x) x.begin(),x.end()

vector<vector<int>> adj;
vector<int> c;
vector<int> ans;
vector<bool> v;
int y;

void childfs(int u,int p){
    for(auto x : adj[u]){
        if(x == p)continue;
        childfs(x,u);
        c[u] = max(c[u],1 + c[x]);
    }
}

void color(int u,int p,int val){
    int cnt = 0,mx = 0,idx = 0;
    for(auto x : adj[u]){
        if(x == p)continue;
        ++cnt;
        if(mx <= c[x]){
            mx = c[x];
            idx = x;
        }
    }
    if(cnt == 0){
        ans.pb(val);
        return;
    }
    for(auto x : adj[u]){
        if(x == p)continue;
        if(x == idx)color(x,u,val + 1);
        else color(x,u,1);
    }
}

void solve(){
    int n,k;
    cin >> n >> k;
    adj.resize(n);
    c.resize(n,1);
    ans.resize(n);
    v.resize(n);
    rep(i,0,n-1){
        int a,b;
        cin >> a >> b;
        --a;-- b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    if(k == 1){
        cout << 1;ln;
        return;
    }
    // bfs from 0 to identify y
    queue<pi> q;    
    q.push({0,0});
    int mx = 0;
    while(!q.empty()){
        pi p = q.front();
        q.pop();
        int u = p.fr,d = p.sc;
        if(v[u])continue;
        v[u] = 1;
        if(d > mx){
            mx = d;
            y = u;
        }
        ++d;
        for(auto x : adj[u]){
            if(!v[x])q.push({x,d});
        }
    }
    v.clear();
    // root tree at y and perform child dfs
    childfs(y,-1);
    // now colour the tree rooted at y 
    color(y,-1,1);  

    sort(ans.rbegin(),ans.rend());
    int sum = 0,i = 0;
    while(sum < k){
        sum += ans[i++];
    }
    cout << i + 1;ln;    
    for(auto &a : adj)a.clear();
    adj.clear();
    v.clear();
    ans.clear();
    c.clear();
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