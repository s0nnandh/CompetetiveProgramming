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
    
    int n,k;
    cin >> n >> k;
    vector<ll> x(n),y(n),v(n);
    ll ans = 0;
    rep(i,0,n){
        cin >> x[i] >> y[i] >> v[i];
        //ans = max(ans,v[i]-k*(y[i]-x[i]));
    }    
    // rep(i,0,n){
    //     rep(j,i+1,n){
    //         ll maxx = -1e9,minn = 1e9,s = 0;
    //         rep(kk,i,j+1){
    //             s+=v[kk];
    //             maxx = max(maxx,y[kk]);
    //             minn = min(minn,x[kk]);
    //         }
    //         //dbg(i,j,s,maxx,minn);
    //         ans = max(ans,s-k*(maxx-minn));

    //     }
    // }
    for(int start = 0;start < n; ++start){
        for(int end = start;end < n;++end){
            ll maxx = -1e18,minn = 1e18,s = 0;
            for(int i = start;i <= end;++i){
                s+=v[i];
                maxx = max(maxx,y[i]);
                minn = min(minn,x[i]);
            }
            dbg(start,end,s,maxx,minn);
            if(k*(maxx-minn) < s)ans = max(ans,s - (k*(maxx-minn)));
        }
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

