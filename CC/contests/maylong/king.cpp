#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ln cout<<"\n"
using namespace std;
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
#define dbg(...) {}
#endif

#define pi pair<int,int>
#define pl pair<ll,ll> 
#define fr first
#define sc second
#define pb push_back
#define gcd(a,b) __gcd(a,b)

vector<vector<int>> adj;
vector<int> dp,ans;

void dfs(int u,int p){
    for(auto x : adj[u]){
        if(x != p){
            dfs(x,u);
        }   
    }
    map<int,int> mp;
    for(auto x : adj[u]){
            if(x != p){
                mp[dp[x]]++;
            }
        }
    if(u){        
        
        if(mp.size() == 0){
            dp[u] = 0;
        }
        else if(mp.size() == 1){
            dp[u] = 1 + (*mp.begin()).fr;
        }
        else{
            dp[u] = 2 + (*mp.begin()).fr;
        }
        
    }
    else{
        dp[u] = 1 + (*mp.begin()).fr;
    }
    mp.clear();
}


void dfs2(int u,int p,ll pval){
    if(pval == 0){
        ans.pb(u + 1);
        return;
    }
    for(auto x : adj[u]){
        if(x != p){
            if(!u){
                dfs2(x,u,dp[u] - 1);
            }
            else{
                if(pval < dp[u]){
                    dfs2(x,u,pval);
                }
                else if(pval > dp[u]){
                    return;
                }
                else{
                    dfs2(x,u,pval-1);
                }
            }
        }
    }
}

void dfs_find_answer(int z,int p,int T){
	if(T > dp[z]){
		// vertices in the subtree of z are already above vertex z (hence dead)
		return;
	}
	for(int x:adj[z]){
		if(x == p){
			continue;
		}
		if(p == -1){
			// no killing happens on root
			if(dp[x] == T - 1){
				dfs_find_answer(x, z, T - 1);
			}
		}
		else{
			if(T < dp[z]){
				// if T < dp[z], we need to go in the past, so go deeper in the tree
				dfs_find_answer(x, z, T);
			}
			else{
				// vertices alive in subtree of z at time T were alive in subtree of child at time T - 1
				dfs_find_answer(x, z, T - 1);
			}
		}
	}
	if(T == 0){
		// z is a valid leaf
		ans.push_back(z + 1);
	}
}

void solve(){
    
    int n;
    cin >> n;
    adj.resize(n);
    dp.resize(n);
    // ans.resize(n);
    rep(i,0,n-1){
        int a,b;
        cin >> a >> b;
        --a;--b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    dfs(0,-1);
    // dfs2(0,-1,dp[0]);
    dfs_find_answer(0,-1,dp[0]);
    sort(ans.begin(),ans.end());
    cout << (int)ans.size() << " " << dp[0] ;ln;
    for(auto x : ans)cout << x << " ";
    ln;
    dp.clear();
    for(auto &x : adj)x.clear();
    ans.clear();
    adj.clear();


}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);   
    //gen_factorial(1e6);   
    int test=1;
    cin>>test;   
    while(test--)
        solve();
    return 0;
}