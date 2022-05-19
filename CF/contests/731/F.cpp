#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ln cout<<"\n"
#define rep(i,s,n) for(ll i = (s);i<(n);++i)
#define pc(x) __builtin_popcount(x)
#define pi pair<int,int>
#define pl pair<ll,ll> 
#define fr first
#define sc second
#define pb push_back
#define gcd(a,b) __gcd(a,b)
#define len(x) (int)x.size()
#define all(x) x.begin(),x.end()
#define vi vector<int>
#define vl vector<ll>
void __dbg(int x) {cerr << x;}
void __dbg(long long x) {cerr << x;}
void __dbg(float x) {cerr << x;}
void __dbg(double x) {cerr << x;}
void __dbg(long double x) {cerr << x;}
void __dbg(char x) {cerr << '\'' << x << '\'';}
void __dbg(const char *x) {cerr << '\"' << x << '\"';}
void __dbg(const string &x) {cerr << '\"' << x << '\"';}
void __dbg(bool x) {cerr << (x ? "true" : "false");} 
template<class T,class V>void __dbg(const pair<T, V> &x) {cerr << "{ "; __dbg(x.first); cerr << ','; __dbg(x.second); cerr << "}";}
template<class T>void __dbg(const T &x) {int f = 0; cerr << "{ "; for (auto &i: x) cerr << (f++ ? "," : ""), __dbg(i); cerr << "}";}
void _dbg() {cerr << " ]" << endl;}
template <class T, class... V>void _dbg(T t, V... v) {__dbg(t); if (sizeof...(v)) cerr << ", "; _dbg(v...);} 
#ifdef _DEBUG
#define dbg(x...) cerr << "[" << #x << "] = [ "; _dbg(x)
#else
#define dbg(x...)
#endif   

template<class T> 
struct segtree{
    vector<T> tree,lazy;
    bool islazy;
    int sz;
    int n;
    segtree(){

    }
    segtree(T N,T val,bool do_lazy = false){
        sz = 4 * N;
        tree.assign(sz,val);
        islazy = 0;
        if(do_lazy){
            lazy.assign(sz,0);
            islazy = 1;
        }
    }
    T segf(T a,T b){  // the function 
        if(a * b == 0)return max(a,b);
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
        int left = ask_range(2 * node,low,mid,l,r);
        int right = ask_range(2 * node + 1,mid + 1,high,l,r);
        return segf(left,right);
    }
    T query(int l,int r){
        // l--;
        // r--;
        return ask_range(1,0,n - 1,l,r);
    }

    // lazy upd incomplete
};

void solve(){
    int n;
    cin >> n;
    vi v(2 * n);
    rep(i,0,n)cin >> v[i];
    rep(i,0,n)v[n + i] = v[i];
    segtree<int> st(len(v),0);
    st.construct(v);
    // dbg(v);
    function<bool(int)> ok = [&](int k){
        set<int> s;
        rep(i,0,n){
            // dbg(k,i,i + k - 1,st.query(i,i + k - 1));
            s.insert(st.query(i,i + k - 1));
        }
        return s.size() == 1;
    };    
    int l = 1,r = n;
    int ans = n;
    while(l <= r){
        int mid = (l + r) / 2;
        if(ok(mid)){
            r = mid - 1;
            ans = min(ans,mid - 1);
        }
        else l = mid + 1;
    }
    cout << ans;ln;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);     
    int test=1;
    cin>>test;   
    while(test--)
        solve();
    return 0;
}
