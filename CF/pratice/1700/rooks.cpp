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

// USING STACK TO KEEP TRACK OF VERTICES WE HAVE ENCOUNTERED
// ALGO FOR FINDING IF THERE IS A CYCLE IN A DIRECTED GRAPH
bool cyc(vector<bool> &vis,vector<bool> &stack,vector<vector<int>> &adj,int i){
    //dbeugqeiugouaNDOND ojsnd 
    if(stack[i])return true;
    if(!vis[i]){
        vis[i] = 1;
        stack[i] = 1;
        for(auto x : adj[i]){
            return cyc(vis,stack,adj,x);
        }
    }
    //stack[i] = 0;
    return false; 
}   
void solve(){
    int n,m;
    cin >> n >> m;
    vector<vector<int>> adj(n+1);
    int ans = 0;
    rep(i,0,m){
        int a,b;
        cin >> a >> b;
        if(a!=b){
            adj[a].push_back(b);
            ++ans;
        }
    }
    vector<bool> vis(n+1);
    rep(i,1,n+1){
        vector<bool> stack(n+1);
        if(!vis[i] && cyc(vis,stack,adj,i))++ans;
    }
    cout << ans ;
    ln;
    
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

// THIS CAN BE INTERPRETED AS A DIRECTED GRAPH IN WHICH IF THERE IS A CYCLE IT WOULD 
// TAKE AN EXTRA MOVE OR OTHERWISE IT WOULD BE JUST ONE MOV FOR EACH ROOK