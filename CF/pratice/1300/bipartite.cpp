#include<bits/stdc++.h>
#include<unordered_map>
#define ll long long
#define ull unsigned long long
#define ln cout<<"\n"
#define dbg(x) cout<<#x<<" = "<<x<<" "
#define rep(i,s,n) for(ll i = (s);i<(n);++i)
using namespace std;
int n,a,b;
void dfs( vector<vector<int>> &adj,vector<int> & color,int u,int c){
    if(color[u] == -1){
        color[u] = c;
        c = (c+1)%2;
        for(auto v : adj[u]){
            dfs(adj,color,v,c);
        }
    }
}
void solve(){    
    cin>>n;
    vector<vector<int>> adj(n+1);    
    rep(i,0,n-1){
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<int> color(n+1,-1);
    dfs(adj,color,1,0);
    ll z= 0,one = 0;
    rep(i,1,n+1){
        //dbg(color[i]);
        if(color[i] == 0)++z;
        else ++one;
    }
    cout<<(one*z)-n+1;ln;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);    
    int test=1;
    //cin>>test;   
    while(test--)
        solve();
}

// OUR GOAL IS TO CONVERT THE TREE TO A COMPLETE BIPARTITE GRAPH 