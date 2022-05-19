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
    // map<char,int> mp;
    string s;
    cin >> s;
    vector<char> v;
    rep(i,0,n){
        if(v.size()==0)v.pb(s[i]);
        else if(s[i] != v[v.size()-1]){
            v.pb(s[i]);
        }
    }
    map<char,int> mp;
    bool ans = 1;
    for(auto x : v){
        if(mp[x] != 0){
            ans = 0;
            break;
        }
        mp[x]++;
    }
    cout << (ans?"YES":"NO");ln;

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