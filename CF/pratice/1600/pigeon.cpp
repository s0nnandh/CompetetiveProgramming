// https://codeforces.com/contest/1501/problem/C

// intresting application of pigeon hole principle
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

struct ind{
    int i,j;
    ind(int l,int r){
        i = l;
        j = r;
    }
};
const int nx = 5e6 + 1;

void solve(){   

    int n;
    cin >> n;
    vector<int> v(n);
    for(auto &i : v)cin >> i;
    vector<vector<ind>> seen(nx);
    rep(i,0,n){
        rep(j,0,i){
            int sum = v[i] + v[j];
            if(seen[sum].size() == 0)seen[sum].pb(ind(i,j));
            else{
                for(auto x : seen[sum]){
                    int l = x.i,r = x.j;
                    if(l != i && l != j && r != i && r != j){
                        cout << "YES";
                        ln;
                        cout << i + 1 << " " << j + 1 << " " <<  l + 1 << " " << r + 1;
                        ln;
                        return;
                    }
                }
                seen[sum].pb(ind(i,j));
            }
        }
    }
    cout << "NO";ln;
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