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

ll cal(string ss,int n,int i){
    //if(ss == "")return 0;
    if(i >= n)return 0;
    if(ss[0] > ss[i+ n])return ss[0]-'0'-1;
    return (ss[0]-'0'-1)*(ll)pow(10,n-i-1) + cal(ss,n,i+1);

}

void solve(){
    string s;
    cin >> s;
    int n = s.size();
    bool ev = 1;
    if(n&1)ev = 0;
    n/=2;    
    ll t = 0,k = 1;
    if(!ev)++n;
    rep(i,0,n-1){
        t+=9*k;
        k*=10;
    }
    if(!ev){
        cout << t;ln;
        return;
    }
    //string ss = s.substr(0,n);
    cout << t + cal(s,n,0);ln;
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

