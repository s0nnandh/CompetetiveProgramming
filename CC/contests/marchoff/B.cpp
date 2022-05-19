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

void solve(){    
    
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i,0,n)cin >> a[i];

    rep(i,0,n){
        int sum = 0;    
        rep(j,0,i-1){
            if(a[j] > a[i])break;
            else if(a[j] == a[i])++sum;
        }
        rep(j,i+1,n){
            if(a[j] > a[i])break;
            else if(a[j] == a[i])++sum;
        }
        cout << sum << " ";
    }
    ln;

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

