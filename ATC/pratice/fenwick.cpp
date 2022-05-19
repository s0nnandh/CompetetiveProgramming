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
#define gcd(a,b) __gcd(a,b)

struct Fenwick{   // 1 - indexed Fenwick tree
    int n;
    vector<ll> bit;  

    Fenwick(int nn){
        this -> n = nn;
        bit.resize(nn + 1);
    }
    void add(ll x,int i){
        while(i <= n){
            bit[i] += x;
            i += i & (-i);
        }
    }
    ll get(int i){
        ll sum = 0;
        while(i > 0){
            sum += bit[i];
            i -= i & (-i);
        }  
        return sum; 
    }
    ll query(int l,int r){
        return get(r) - get(l-1);
    }
};

void solve(){   
    int n,q;
    cin >> n >> q;
    Fenwick F(n);
    rep(i,1,n+1){
        int a;
        cin >> a;
        F.add(a,i);
    }
    rep(I,0,q){
        char ch;
        cin >> ch;
        if(ch == 'S'){
            int i,j;
            cin >> i >> j;
            ++i;++j;
            cout << F.query(i,j);ln;
        }
        else if(ch == 'G'){

            ll x,i;

            cin >> i >> x;
            ++i;
            F.add(x,i);
        }
        else{
            ll x,i;
            cin >> i >> x;
            ++i;
            F.add(-x,i);
        }
    }
	
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL); 
    //gen_factorial(1e6);   
    int test=1;
    // cin>>test;   
    while(test--)
        solve();
    return 0;
}