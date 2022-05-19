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


void solve(){
    ll x,y,a,b;
    cin >> x >> y >> a >> b;
    vector<ll> p;
    ll t = x*a;
    while(t <= 1e18){
        //dbg(t);
        p.push_back(t);
        t*=a;
    }
    ll l = 1,r = y,mid,ans = 0;
    while(l <= r){
        mid = l + (r-l)/2;
        int le = 0,rr = p.size()-1,id = 0,m;
        while(le <= rr){
            m = (le + rr)/2;
            if(p[m] <= mid){
                id = m;
                le = m + 1;
            }
            else rr = m - 1;
        }
        id++;
        ll k = max(id+(p[id-1]-mid)/b,mid/b);
        dbg(mid,id+(p[id-1]-mid)/b,mid/b,id,(mid-p[id-1])/b);
        ans = max(ans,k);
        l = mid + 1;
    } 
    cout << ans;ln;

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

