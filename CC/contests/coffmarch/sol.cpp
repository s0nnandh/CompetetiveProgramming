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

#define pi pair<ll,ll>
#define pb push_back

vector<int> sq(2000);

void solve(){
    int n,k;
    cin >> n >> k;
    vector<ll> v(n+1);
    rep(i,1,n+1){
        cin >> v[i];
    }
    rep(i,1,n+1)v[i]+=v[i-1];
    ll m = n;
    rep(i,1,n+1){
        if(i-k >= 0)m = min(m,v[i]-v[i-k]);
        //dbg(i-k,i);
    } 
    ll s = m;  
    m*=m+1;
    m/=2;
    cout << m + v[n] - s;ln;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL); 
    rep(i,0,2000){
        sq[i] = i*i;
    }      
    int test=1;
    cin>>test;      
    while(test--)
        solve();
    return 0;
}
