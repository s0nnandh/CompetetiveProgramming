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
#define dbg(...) cerr << "" << endl
#endif

#define pi pair<int,int>
#define pl pair<ll,ll> 
#define fr first
#define sc second


void solve(){
    int n;ll d;
    cin >> n >> d;
    vector<pl> v(n);
    vector<ll> s(n + 1);
    rep(i,0,n){
        cin >> v[i].first >> v[i].second ;
        // s[i+1] = s[i] + v[i].second;  
    } 
    sort(v.begin(),v.end());
    rep(i,1,n+1){
        s[i] = s[i-1] + v[i-1].sc;
    }
    // ln;
    ll ans = 0;
    rep(i,0,n){
        int l = i,r = n-1,mid,idx = -1;
        while(l <= r){
            mid = (l + r)/2;
            if(v[mid].first < d + v[i].fr){
                l = mid + 1;
                idx = mid;
            }
            else r = mid - 1;
        }
        if(idx > -1){
            // if(v[idx].fr <= v[i].first + d){
            //     ++idx;
            // }
            // dbg(i,idx + 1,v[idx].fr,s[idx + 1],s[i]);
            ans = max(ans,s[idx + 1]-s[i]);
        }
        
    }
    // O(nlogn) solution 
    cout << ans;ln;

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