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
int main(){
    int tt = 1;
    cin >> tt;
    while(tt--){        

        int n,m;
        cin >> n >> m;
        vector<ll> v(m);
        // ll mmax = 0;
        rep(i,0,m){
            cin >> v[i];
            // mmax = max(mmax,v[i]);
        }
        vector<vector<pl>> adj(n);
        rep(i,0,n-1){
            ll a,b,k;
            cin >> a >> b >> k;
            --a;--b;
            adj[a].pb({b,k});
            adj[b].pb({a,k});
        }
        vector<bool> vis(n);
        multiset<ll,greater<ll>> s;
        queue<pair<int,pl>> q;
        q.push({0,{0,0}});
        while(!q.empty()){
            int ch = q.front().first;
            // if(!vis[ch]){
                vis[ch] = 1;
                pl p = q.front().second;
                ll d = p.first;
                ++d;
                if(adj[ch].size() == 1){
                    // dbg(ch + 1,p.second);
                    s.insert(p.second);
                }
                else{
                    ll ic = p.second;
                    // if(ic < mmax){
                        //dbg(ic);
                        for(auto x : adj[ch]){
                            if(!vis[x.first]){
                                ll k = x.second;
                                // ic += (c*d);
                                q.push({x.first,{d,ic + (k*d)}});
                            }
                            // dbg(x.first + 1,d,ic);
                        }
                    // }
                }
            // }
            q.pop();
        }
        sort(v.rbegin(),v.rend());
        int ans = 0;
        for(auto x : s){
            // dbg(x);
            if(v[ans] >= x)++ans;
            if(ans == m)break;
        }
        cout << ans;ln;

    }
}
