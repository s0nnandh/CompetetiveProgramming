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
#define pb push_back
 

ll mod = 1e9 + 7;
int main(){
    int tt = 1;
    cin >> tt;
    while(tt--){        

        int n,m,b;
        cin >> n >> m >> b; 
        vector<vector<int>> v(n+1,vector<int>(m+1));vector<int> row(n+1),col(m+1);
        ll sum = 0;
        rep(i,1,n+1){
            rep(j,1,m+1){
                cin >> v[i][j];
                sum += v[i][j];
            }
        }
        rep(i,1,n+1){
            rep(j,1,m + 1){
                row[i] += v[i][j];
            }
            cout << row[i] << " ";
        }
        ln;
        rep(j,1,m+1){
            rep(i,1,n + 1){
                col[j]+=v[i][j];
            }
            cout << col[j] << " ";
        }  
        ln;   
        int ans = 0;
        // dbg(1<<n);
        rep(i,0,(1<<n)){
            rep(j,0,(1<<m)){
                ll s = sum;
                rep(k,0,n){
                    if((i&(1<<k)) == 0){
                        s-=row[k+1];
                    }   
                }
                rep(k,0,m){
                    if((j&(1<<k)) == 0){
                        s-=col[k+1];
                    }   
                }
                if(s == b)ans++;
                if(ans > mod)ans -= mod;

            }
        }
        cout << ans;ln;

    }
}
