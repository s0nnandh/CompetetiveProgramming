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

int main(){
    int tt;
    cin >> tt;
    while(tt--){
        int n,m,k;
        cin >> n >> m >> k;
        vector<vector<ll>> v(n+1,vector<ll> (m+1)),cnt(n+1,vector<ll> (m+1,0));
        ++n;++m;
        int ans = 0;
        rep(i,1,n){
            rep(j,1,m){
                cin >> v[i][j];
                if(v[i][j] >= k)++ans;
            }
        }
        // dbg(ans);
        rep(i,1,n){
            rep(j,1,m){
                v[i][j] += v[i-1][j] + v[i][j-1] - v[i-1][j-1];
                cnt[i][j] = 1 +  cnt[i-1][j] + cnt[i][j-1] - cnt[i-1][j-1];
            }
        }
        // rep(i,1,n){
        //     rep(j,1,m){
        //         // v[i][j] += v[i-1][j] + v[i][j-1] - v[i-1][j-1];
        //         cout << cnt[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        
        rep(i,1,n){
            rep(j,1,m){
                //ll len = 1;
                int l = 1,r = min(n-i,m-j)-1,len = -1,mid;
                while(l <= r){
                    

                    mid = (l + r)/2;
                    
                    ll s = v[i+mid][j+mid] - v[i-1][j+mid] - v[i+mid][j-1] + v[i-1][j-1];
                    ll c = cnt[i+mid][j+mid] - cnt[i-1][j+mid] - cnt[i+mid][j-1] + cnt[i-1][j-1];
                    // dbg(l,r,mid,i,j,s);
                    if(s >= c*k){
                        r = mid - 1;
                        len = mid;
                    }
                    else l = mid + 1;
                }
                // dbg(i,j,len,r);
                if(len != -1)ans+=min(n-i,m-j)-len;
                // while(len + i < n && len + j < m){
                //     // cout << len << endl;
                //     ll s = v[i+len][j+len] - v[i-1][j+len] - v[i+len][j-1] + v[i-1][j-1];
                //     ll c = cnt[i+len][j+len] - cnt[i-1][j+len] - cnt[i+len][j-1] + cnt[i-1][j-1];
                //     //cout << len << " " << c << " " << endl;
                //     if(s >= c*k){
                //         ans+=min(n-i,m-j)-len;
                //         dbg(i,j,ans);
                //         break;
                //     }
                //     ++len;
                // }
            }
        }
        cout << ans << endl;
    }
}