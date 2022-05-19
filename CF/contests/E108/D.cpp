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


void solve(){
    int n;
    cin >> n;
    vector<ll> a(n),b(n),c(n + 1);
    rep(i,0,n)cin >> a[i];
    ll ans = 0;
    rep(i,0,n){
        cin >> b[i];
        c[i+1] = a[i] * b[i];        
        ans+=c[i+1];
        c[i+1]+=c[i];
    }
    rep(i,1,n-1){
        int l = i-1,r = i + 1; ll sum = a[i] * b[i];
        while(l >= 0 && r < n){
            // dbg(l,r);
            sum += a[l] * b[r];
            sum += a[r] * b[l];
            ans = max(ans,sum + c[l] + c[n]-c[r + 1]);
            --l;
            ++r;
        }
        // dbg(l,r);
        
    }
    rep(i,0,n-1){
        int l = i,r = i+1;ll sum = 0;
        while(l >= 0 && r < n){
            sum += a[l] * b[r];
            sum += a[r] * b[l];
             ans = max(ans,sum + c[l] + c[n]-c[r + 1]);
            --l;
            ++r;
        }
        // dbg(l,r);
        // ans = max(ans,sum + c[l + 1] + c[n]-c[r]);
    }
    cout << ans ;ln;
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

