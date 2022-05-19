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

#define pi pair<int,int>
#define pb push_back
const int MAX = 100;

int lookup[MAX][MAX];
 
// Structure to represent a query range
struct Query {
    int L, R;
};
 
// Fills lookup array 
// lookup[][] in bottom up manner.
void preprocess(vector<ll> &arr, int n)
{
    // Initialize M for the 
    // intervals with length 1
    for (int i = 0; i < n; i++)
        lookup[i][0] = i;
 
    // Compute values from smaller 
    // to bigger intervals
    for (int j = 1; (1 << j) <= n; j++) 
    {
        // Compute minimum value for 
        // all intervals with size
        // 2^j
        for (int i = 0; (i + (1 << j) - 1) < n; i++) 
        {
            // For arr[2][10], we 
            // compare arr[lookup[0][3]]
            // and arr[lookup[3][3]]
            if (arr[lookup[i][j - 1]]
                > arr[lookup[i + (1 << (j - 1))][j - 1]])
                lookup[i][j] = lookup[i][j - 1];
            else
                lookup[i][j]
                    = lookup[i + (1 << (j - 1))][j - 1];
        }
    }
}
 
// Returns minimum of arr[L..R]
int query(vector<ll> &arr, int L, int R)
{
    // For [2,10], j = 3
    int j = (int)log2(R - L + 1);
 
    // For [2,10], we compare arr[lookup[0][3]] and
    // arr[lookup[3][3]],
    if (arr[lookup[L][j]]
        >= arr[lookup[R - (1 << j) + 1][j]])
        return arr[lookup[L][j]];
 
    else
        return arr[lookup[R - (1 << j) + 1][j]];
}
 

void solve(){    
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i,0,n)cin >> a[i];
    //preprocess(a,n);
    vector<ll> p(60);
    p[0] = 1;
    rep(i,1,60)p[i]=2*p[i-1];
    vector<vector<int>> one(60,vector<int> (n+1)),z(60,vector<int> (n+1));
    rep(i,0,60){
        rep(j,1,n+1){
            one[i][j]+=((1LL<<i)&a[j-1])+one[i][j-1];
        }
    }
    rep(i,0,60){
        rep(j,1,n+1){
            z[i][j]+=!((1LL<<i)&a[j-1])+z[i][j-1];
        }
    }
    ll ans = 0;
    rep(i,1,n+1){
        ll m = a[i-1];
        rep(j,i,n+1){
            ll t = 0;
            rep(k,0,60){
                int o = one[k][j] - one[k][i-1],zz = z[k][j] - z[k][i-1];
                if(o != 0 && zz != 0)t+=p[k]; 
                //dbg(k,o,zz,j-i+1,t);             
            }
            m = max(m,a[j-1]);
            if(t >= m){
                ++ans;
                dbg(i,j);
            }
            //dbg(t,query(a,i-1,j-1));
        }
    }
    cout << ans ;ln;

    // precompute or's

    // unordered_set<ll> s,c;
    // ll t = 0;
    // rep(i,0,n){
    //     s.insert(a[i]);
    //     c = s;
    //     for(auto x : c){
    //         s.insert(a[i]|x);
    //     }

    // }
    // for(auto x : s){
    //     cout << x << " ";
    // }
    // ln;

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

