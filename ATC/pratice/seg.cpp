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

#define pl pair<ll,ll>

const ll mod  = 1e9 + 7;
namespace modop {
	ll madd(ll a, ll b) {
        ll k = a + b;
        if(k < 0)return mod + k;
        if(k >= mod)return k - mod;
        return k;

	}
	ll msub(ll a, ll b) {
	  return (((a - b) % mod) + mod) % mod;
	}
	ll mmul(ll a, ll b) {
	  return ((a % mod) * (b % mod)) % mod;
	}
	ll mpow(ll base, ll exp) {
	  ll res = 1;
	  while (exp) {
		if (exp % 2 == 1){
			res = (res * base) % mod;
		}
		exp >>= 1;
		base = (base * base) % mod;
	  }
	  return res;
	}
	ll minv(ll base) {
	  return mpow(base, mod - 2);
	}
	ll mdiv(ll a, ll b) {
	  return mmul(a, minv(b));
	}
	
	const ll FACTORIAL_SIZE = 1.1e6;
	ll fact[FACTORIAL_SIZE], ifact[FACTORIAL_SIZE];
	void gen_factorial(ll n) {
		fact[0] = fact[1] = ifact[0] = ifact[1] = 1;
		
		for (ll i = 2; i <= n; i++) {
			fact[i] = (i * fact[i - 1]) % mod;
            //dbg(fact[i]);
		}
		ifact[n] = minv(fact[n]);
		for (ll i = n - 1; i >= 2; i--) {
			ifact[i] = ((i + 1) * ifact[i + 1]) % mod;
		}
	}
	ll nck(ll n, ll k) {
		ll den = (ifact[k] * ifact[n - k]) % mod;
        //dbg(ifact[k],ifact[n - k]);
		return (den * fact[n]) % mod;
	}
}
 
using namespace modop;

ll X;

const int MAX = 2e5 + 5;

int n,q;

void update(int node,int l,int r,ll x,ll val,vector<ll> &a,vector<ll> &tree){

    if(x < l || r < x)return;

    

    if(l == x && r == x){
        tree[node] = val;
        a[x] = val;
        return;
    }
    int mid = (l+r)/2;
    if(x <= mid)
        update(2*node,l,mid,x,val,a,tree);
    else update(2*node + 1,mid+1,r,x,val,a,tree);
    tree[node] = min(tree[2*node],tree[2*node + 1]);

}

ll query(int node,int st,int end,int l,int r,vector<ll> &tree){

    if(l > end || r < st)return 1e9;

    if(st >= l && end <= r){
        return tree[node];
    }

    int mid = (st + end)/2;

    ll q1 = query(2*node,st,mid,l,r,tree);
    ll q2 = query(2*node + 1,mid + 1,end,l,r,tree);
    return min(q1,q2);
}

ll qq(vector<ll> &a,int xi,int vi,vector<ll> &tree){

    int l = xi-1,r = n-1,idx = -1;

    while(l <= r){
        int mid = (l+r)/2;
        if(a[mid] >= vi){
            idx = mid;
            r = mid - 1;
        }
        else l = mid + 1;
    }

    if(idx == -1)return n + 1;
    return idx + 1;

}

void build(int node,int st,int end,vector<ll> &tree,vector<ll> &a){
    if(st == end){
        tree[node] = a[st];
        return; 
    }
    int mid = (st + end)/2;
    build(2*node,st,mid,tree,a);
    build(2*node + 1,mid + 1,end,tree,a);
    tree[node] = min(tree[2*node],tree[2*node + 1]);
}

void solve(){
    
    
    cin >> n >> q;
    vector<ll> a(n);
    rep(i,0,n)cin >> a[i];
    vector<ll> tree(4*n);
    // rep(i,n,2*n){
    //     tree[i] = a[i-n];
    // }

    build(1,0,n-1,tree,a);

    // for(int i = n - 1;i >= 1;--i){

    //     tree[i] = min(tree[2*i],tree[2*i + 1]);

    //     cout << 2 * i << " " << 2 * i + 1 << " " << tree[i] << endl;

    // }

    // rep(i,0,q){
    //     char c;
    //     int x,val;
    //     cin >> c;
    //     if(c == 'q'){
    //         cin >> x >> val;
    //         //--a;//--b;
    //         cout << query(1,0,n -1,x-1,val-1,tree);ln;
    //     }
    //     else{
    //         cin >> x >> val;
    //         //--a;
    //         update(1,0,n -1,x-1,val,a,tree);
    //     }
    // }

    rep(i,0,q){
        int t,x,v;
        cin >> t >> x >> v;
        if(t == 1)update(1,0,n - 1,x-1,v,a,tree);
        else if(t == 2) cout << query(1,0,n-1,x-1,v-1,tree) << endl;
        else cout << qq(a,x,v,tree) << endl;
        // cout << endl;
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


