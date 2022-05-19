#include<bits/stdc++.h>
using namespace std;
struct LCA{
    int n;
    int root;
    vector<vector<int>> g;
    vector<vector<int>> up; 
    vector<int> depth;  
    int LOG;
    LCA(){

    }
    LCA(vector<vector<int>> &adj,int r = 0){ // 0 indexed based LCA 
        g = adj; 
        n = adj.size();
        root = r;
        preprocess();   
    }
    void preprocess(){
        LOG = 17; // change log if required(17 if 1e5 20 if 1e6)
        up.assign(n,vector<int> (LOG));
        depth.assign(n,0);
        for(int i = 0;i < LOG;++i)up[root][i] = root;
        dfs(root,-1);
    }
    void dfs(int u,int par){
        if(par == -1){
            depth[u] = 0;
        }
        else{
            depth[u] = 1 + depth[par];
        }
        for(auto x : g[u]){
            if(x == par)continue;
            up[x][0] = u;
            for(int j = 1;j < LOG;++j){
                up[x][j] = up[up[x][j - 1]][j - 1]; // powers of 2 2 ^ 3 = 2 ^ 2 + 2 ^ 2
            }
            dfs(x,u);
        }
    }
    int kth_anc(int u,int k){
        for(int j = LOG - 1;j >= 0;--j){
            if(k&(1 << j))u = up[u][j];
        }
        return u;
    }
    int lca(int a,int b){
        // d b > d a
        if(depth[a] > depth[b]){
            swap(a,b);
        }
        // make them both at same depth
        int k = depth[b] - depth[a];
        b = kth_anc(b,k);
        if(a == b){
            return a;
        }
        // start from higher powers
        for(int j = LOG - 1;j >= 0;--j){
            if(up[a][j] != up[b][j]){
                a = up[a][j];
                b = up[b][j];
            }
        }
        return up[a][0];
    }
    int dis(int a,int b){
        int x = lca(a,b);
        return depth[a] + depth[b] - 2 * depth[x];
    }
};