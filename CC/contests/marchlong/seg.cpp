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

#define pi pair<ll,ll>
#define pb push_back

// void update(int node,int l,int r,int idx,int x,vector<int> &tree){
//     if(l == r){
//         tree[node] = x;
//     }
//     else{
//     int mid = (l+r)/2;
//     if(idx < mid){
//         update(2*node,l,mid,idx,x,tree);
//     }
//     else update(2*node + 1,mid + 1,r,idx,x,tree);

//     tree[node] = min(tree[2*node],tree[2*node + 1]);
//     }
// }

void update(int node, int start, int end, int idx, int val ,vector<int> &tree)
{
    if(start == end)
    {
        /// Leaf node
        //A[idx] += val;
        tree[node] = val;
    }
    else
    {
        int mid = (start + end) / 2;
        if(start <= idx and idx <= mid)
        {
            // If idx is in the left child, recurse on the left child
            update(2*node, start, mid, idx, val,tree);
        }
        else
        {
            // if idx is in the right child, recurse on the right child
            update(2*node+1, mid+1, end, idx, val,tree);
        }
        // Internal node will have the sum of both of its children
        tree[node] = min(tree[2*node],tree[2*node+1]);
    }
}

int query(int node, int start, int end, int l, int r,vector<int> &tree)
{
    if(r < start or end < l)
    {
        // range represented by a node is completely outside the given range
        return 1e9;
    }
    if(l <= start and end <= r)
    {
        // range represented by a node is completely inside the given range
        return tree[node];
    }
    // range represented by a node is partially inside and partially outside the given range
    int mid = (start + end) / 2;
    int p1 = query(2*node, start, mid, l, r,tree);
    int p2 = query(2*node+1, mid+1, end, l, r,tree);
    return min(p1,p2);
}

// int query(int node,int l,int r,int start,int end,vector<int> &tree){

//     if(start > r || end < l)return 1e9;
//     if(start >= l && r <= end){
//         return tree[node];
//     }
//     int mid = (l + r)/2;
//     int q1 = query(2*node,l,mid,start,end,tree);
//     int q2 = query(2*node + 1,mid+1,r,start,end,tree);
//     return min(q1,q2);
// }

void solve(){    
    int n,q;
    cin >> n >> q;
    vector<int> v(n);
    int m = 1e9;
    rep(i,0,n){
        cin >> v[i];
        m = min(m,v[i]);
    }
    vector<int> tree(2*n);
    rep(i,n,2*n){
        tree[i] = v[i-n];
    }
    for(int i = n-1;i >= 0; --i){
        tree[i] = min(tree[2*i],tree[(2*i) +1]); 
    }
    tree[0] = m;
    rep(i,0,2*n)cout << tree[i] << " ";
    ln;
    rep(i,0,q){
        char c;
        int a,b;
        cin >> c;
        if(c == 'q'){
            cin >> a >> b;
            --a;//--b;
            cout << query(0,0,2*n -1,a,b,tree);ln;
        }
        else{
            cin >> a >> b;
            --a;
            update(0,0,2*n -1,a,b,tree);
        }
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

