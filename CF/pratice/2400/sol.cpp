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
#define dbg(...) cerr << "[ ]" << endl
#endif

#define pi  pair<int,int>
 
map<int,bool> mp;

bool fib(int n){
    if(n == 1)return true;

    return true;
}

pi find(vector<int> &child,vector<vector<int>> &adj,int root,int total){
    if(mp[total - child[root]]){
        
    }
}  

int cnt(int u,vector<vector<int>> &adj,vector<int> &child){
    int s = 0;
    for(auto x : adj[u]){
        s+=cnt(x,adj,child);
    }
  map<int,bool> mp;  child[u] = s;
    return s;   
}

void solve(){   

    int a,b,c;
    
    mp[1] = 1;
    mp[2] = 1;
    a = 1;b = 2;
    while(c < (int)2e5){
        c=a+b;
        a = b;
        b = c;
        mp[c]=1;
    }
    int n;
    cin >> n;
    vector<vector<int>> adj(n+1);
    int pos = -1;
    vector<int> parent(n+1,-1);
    rep(i,0,n){
        int a,b;        
        cin >> a >> b;
        parent[b] = a;
        adj[a].push_back(b);
    }
    int root;
    rep(i,1,n+1){
        if(parent[i] == -1){
            root = i;
            break;
        }
    }
    vector<int> child(n+1);
    cnt(root,adj,child);

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