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
void _dbg() {cerr << " ]" << endl ;}
template <class T, class... V>void _dbg(T t, V... v) {__dbg(t); if (sizeof...(v)) cerr << ", "; _dbg(v...);} 
#ifdef _DEBUG
#define dbg(x...) cerr << "[" << #x << "] = [ "; _dbg(x)
#else
#define dbg(x...)

#endif


/*

    i    h   n   h   h    i   

*/

ll inf = 1e18;

void solve(){
    int n,m;
    cin >> n >> m;
    vector<ll> p(n),x(m);
    for(auto &i : p)cin >> i;
    vector<ll> pref(n + 1);
    for(int i = 1;i <= n;++i)pref[i] = pref[i - 1] + p[i - 1];
    if(m == 0){
        cout << pref.back() << "\n";
        return;
    }
    for(auto &i : x)cin >> i;
    sort(all(x));

    ll ans = 0;
    int dist = -100,j = 0;
    vector<ll> left_ans;
    for(int i = 0;i < n;++i){
        dist += 100;
        if(dist < x[0]){
            ans = max(pref[i + 1],ans);
            continue;
        }        
        j = upper_bound(all(x),dist) - x.begin();
        j -= 1;
        ll left_d = dist - x[j],my_d = dist + left_d,nxt = (j + 1 < m ? x[j + 1] : inf);
        if(left_d == 0)continue;
        if(nxt == inf){
            ans = max(ans,pref[n] - pref[i]);
            break;
        }
        my_d = min((my_d + nxt) / 2,nxt - 1);
        my_d /= 100;
        ans = max(ans,pref[min(my_d + 1,(ll)n)] - pref[i]);
    }
    cout << ans << '\n';

}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);    
    int test=1;
    // cin>>test;  
    while(test--)
        solve();
    return 0;
}