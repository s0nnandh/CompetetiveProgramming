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
#define all(x) x.begin(),x.end()

void solve(){   
   
    int n;
    cin >> n;
    string s;
    cin >> s;
    map<pi,int> mp;
    pi pre = {0,0};
    rep(i,0,n){
        pre.fr += (s[i] == 'D' ? 1 : 0);
        pre.sc += (s[i] == 'K' ? 1 : 0);
        if(min(pre.fr,pre.sc) == 0){
            cout << max(pre.fr,pre.sc) << " ";
        }
        else{
            int f = pre.fr,S = pre.sc;
            int g = gcd(f,S);
            f/=g;S/=g;
            mp[{f,S}]++;
            cout << mp[{f,S}] << " ";
        }
    }
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