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
#define dbg(...) cerr << "" << endl
#endif

#define pi pair<int,int>
#define pl pair<ll,ll> 
#define fr first
#define sc second
#define pb push_back

void solve(){

    int n;
    cin >> n;
    vector<bool> seen(n+1);vector<int> m(n),less(n),g(n);
    rep(i,0,n){
        int a;
        cin >> a;        
        m[i] = a;
        if(i == 0){
            less[i] = a;
            g[i] = a;
        }
        else if(m[i-1] != m[i]){
            less[i] = a;
            g[i] = a;
        }
        seen[a] = 1;
    }
    
    // vector<int> s;
    set<ll> s,s1;
    rep(i,1,n+1){
        if(!seen[i])s.insert(i);
    }
    s1 = s;
    // int j = 0;
    rep(i,0,n){
        if(less[i] == 0){
            less[i] = *s.begin();
            s.erase(s.begin());
        }
    }
    vector<int> f(s1.begin(),s1.end());    
    // rep(i,0,n){
    //     cout << g[i] << " ";
    // }
    rep(i,0,n){
        if(g[i] == 0){
            int l = 0,r = f.size() - 1,mid,idx;
            while(l <= r){
                mid = (l + r)/2;
                if(f[mid] < m[i]){
                    idx = mid;
                    l = mid + 1;
                }
                else r = mid - 1;
            }
            g[i] = f[idx];
            f.erase(f.begin()+idx);
        }
        // else dbg(i,m[i]);
    }
    rep(i,0,n)cout << less[i] << " ";
    ln;
    rep(i,0,n)cout << g[i] << " ";
    ln;    

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