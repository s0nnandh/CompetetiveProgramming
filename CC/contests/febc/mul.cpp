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
    int n,q,m;
    cin >> n >> q >> m;
    vector<int> v(n+1);
    rep(i,1,n+1){
        cin >> v[i];
        v[i]+=v[i-1];
    }
    vector<int> ans(m+1);
    rep(i,0,q){
        int L,R;
        cin >> L >> R;
        //bool pos = 0;
        rep(j,1,m+1){
            int l = L,r = R,mid,idx = -1;
            while(l <= r){
                mid = (l+r)/2;
                if(v[mid]-v[L-1] >= j){
                    r = mid -1;
                }
                else {
                    idx = mid;
                    l = mid + 1;
                }
            }
            if(idx&1)ans[j]++;
        }        
    }
    cout << ans[max_element(ans.begin(),ans.end()) - ans.begin()];ln;
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

