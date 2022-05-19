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
    map<int,int> mp;
    vector<int> ans(m+2);
    rep(i,1,n+1){
        cin >> v[i];
        ans[v[i]]++;
    }
    
    rep(i,0,q){
        int L,R;
        cin >> L >> R;
        // rep(g,v[L],m+1){            
        //     int cnt = 0,x = g;
        //     bool pos = 1;
        //     while(pos){
        //         int idx = lower_bound(v.begin()+L,v.begin()+R,x) - v.begin();
        //         if(idx == L && v[L] != x)break;
        //         for(int j = idx;j >= L;--j){
        //             if(mp[x-v[j]] == 0  || !(mp[x-v[i]] <= idx && mp[x-v[i]] >= L)){
        //                 x = x - v[j];
        //                 break;
        //             }
        //             if(j == L){
        //                 x = x - v[L];
        //             }
        //         }
        //         ++cnt;
        //     }
        //     if(cnt&1)ans[g]++;
        // }
        // rep(j,L,R+1){
        //     if(v[j] > m)break;
        //     int x = min(v[j]+v[0],m);
        //     ans[v[j]] = 1;
        //     ans[x+1] = -1;
        // }
        
    }
    //rep(i,1,m+1)ans[i]+=ans[i-1];
    rep(i,1,m+1)cout << ans[i] << " ";
    ln;
    cout << ans[max_element(ans.begin(),ans.end())- ans.begin()];ln;
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

