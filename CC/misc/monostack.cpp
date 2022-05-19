#include<bits/stdc++.h>
#define ll long long
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

vector<int> ans,v,tree;

void build(int node,int st,int end,vector<int> &tree,vector<int> &a){
    if(st == end){
        tree[node] = st;
        return; 
    }
    int mid = (st + end)/2;
    build(2*node,st,mid,tree,a);
    build(2*node + 1,mid + 1,end,tree,a);
    // tree[node] = min(tree[2*node],tree[2*node + 1]);
    ll left = tree[2*node],r = tree[2*node + 1];
    if(a[left] > a[r]){
        tree[node] = left;
    }
    else tree[node] = r;
}

int query(int node,int st,int end,int l,int r,vector<int> &tree,vector<int> &a){

    if(l > end || r < st)return -1;

    if(st >= l && end <= r){
        return tree[node];
    }

    int mid = (st + end)/2;

    ll q1 = query(2*node,st,mid,l,r,tree,a);
    ll q2 = query(2*node + 1,mid + 1,end,l,r,tree,a);

    int lt = -1,rt = -1;
    if(q1 == -1){
        lt = 0;
    }
    else{
        lt = a[q1];
    }
    if(q2 == -1){
        rt = 0;
    }
    else{
        rt = a[q2];
    }
    if(rt > lt)return q2;
    return q1;
}

void solve(){

    int n,m;
    cin >> n >> m;
    // vector<int> v(n),ans(n);
    v.resize(n);
    ans.resize(n);
    rep(i,0,n)cin >> v[i];
    stack<int> st;
    st.push(n-1);
    for(int i = n-2;i >= 0;--i){
        
        if(!st.empty() && v[i] >= v[st.top()]){
            while(!st.empty() && v[i] >= v[st.top()]){
                st.pop();
            }
            ans[i] = st.size();
            st.push(i);
        }
        else{
            if(!st.empty())ans[i] = 1 + ans[st.top()];
            st.push(i);
        }        
    }
    tree.resize(4*n);
    // rep(i,0,n){
    //     cout << ans[i] << " ";
    // }
    // ln;
    // vector<int> tree(4*n);
    build(1,0,n-1,tree,v);
    rep(i,0,m){
        int l,r;
        cin >> l >> r;
        --l;--r;
        int idx = query(1,0,n-1,min(l,r),max(l,r),tree,v);
        // assert(idx < n);assert(idx >= 0);
        // dbg(idx);
        cout << ans[idx];ln;
    }

    tree.clear();ans.clear();v.clear();
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