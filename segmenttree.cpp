#include<bits/stdc++.h>
using namespace std;
template<class T> 
struct segtree{
    vector<T> tree,lazy;
    bool islazy;
    int sz;
    int n;
    segtree(){

    }
    segtree(T N,T val = 0,bool do_lazy = false){
        sz = 4 * N;
        tree.assign(sz,val);
        islazy = 0;
        if(do_lazy){
            lazy.assign(sz,0);
            islazy = 1;
        }
    }
    T segf(T a,T b){  // the function 
        if(a == 0 || b == 0)return max(a,b);
        return gcd(a,b); 
    }
    void construct(vector<T> &v){  // 2 *i  , 2 *i + 1
        n = v.size();
        cst(1,0,n - 1,v);
    }   
    void cst(int node,int l,int r,vector<T> &v){ // 0 indexed (l , r)
        if(l > r)return;
        if(l == r){
            tree[node] = v[l];
            return;
        }
        int mid = (l + r) / 2;
        cst(2 * node,l,mid,v);
        cst(2 * node + 1,mid + 1,r,v);
        tree[node] = segf(tree[2 * node],tree[2 * node + 1]);
    }
    void push(int node){   // incomplete
        tree[node] += lazy[node];
        if(node < n){
            lazy[2 * node] += lazy[node];
            lazy[2 * node + 1] += lazy[node];
        }
        lazy[node] = 0;
    }
    T ask_range(int node,int low,int high,int l,int r){ // low high is of tree , l r is of query
        if(low > high){
            return 0;
        }        
        if(islazy)push(node);
        if(r < low || l > high){
            return 0;
        }
        if(l <= low && r >= high)return tree[node];
        int mid = (low + high) / 2;
        T left = ask_range(2 * node,low,mid,l,r);
        T right = ask_range(2 * node + 1,mid + 1,high,l,r);
        return segf(left,right);
    }
    T query(int l,int r){   /// Change on requirments 
        // l--;   
        // r--;
        return ask_range(1,0,n - 1,l,r);
    }

    // lazy upd incomplete
};