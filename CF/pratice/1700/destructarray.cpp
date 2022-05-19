#include<bits/stdc++.h>
#define ll long long
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
#define gcd(a,b) __gcd(a,b)
#define len(x) (int)x.size()
#define all(x) x.begin(),x.end()
#define vi vector<int>
#define vl vector<ll>

void solve(){
    int n;
    cin >> n;
    vector<int> v(2 * n);
    for(auto &i : v)cin >> i;
    if(n == 1){
        cout << "YES";
        ln;
        cout << v[0] + v[1];ln;
        cout << v[0] << " " << v[1];
        ln;
        return;
    }
    sort(all(v));
    // int m = *max_element(all(v));
    for(int i = 0;i < 2 * n - 1;++i){
        // unordered_map<int,vector<int>> pos;
        multiset<int,greater<int>> s;
        for(auto x : v){
            // pos[x].pb(1);
            s.insert(x);
        }
        bool ok = 1;
        vector<pi> op;
        int val = v[i] + v.back();
        int MaxElem = val;
        while(s.size()){
            int other = MaxElem - (*s.begin());
            MaxElem = *s.begin();
            // dbg(*s.begin());
            s.erase(s.begin());
            // pos[*s.begin()].pop_back();
            if(s.find(other) == s.end()){
                ok = 0;
                break;
            }        
            
            op.pb({MaxElem,other});  
            // dbg(*s.begin(),*s.find(other));         
            s.erase(s.find(other));            
        }
        if(ok){
            cout << "YES";
            ln;
            cout << val;ln;
            for(auto x : op){
                cout << x.fr << " " << x.sc;
                ln;
            }
            return; 
        }
    }
    cout << "NO";ln;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL); 
    // gen_factorial(1e6);  	
    int test=1;
	cin>>test;   
    while(test--)
        solve();
    return 0;
}
