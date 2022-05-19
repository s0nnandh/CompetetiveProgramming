#include<bits/stdc++.h>
#include<unordered_map>
#define ll long long
#define ull unsigned long long
#define ln cout<<"\n"
#define dbg(x) cout<<#x<<" = "<<x<<" "
#define rep(i,s,n) for(ll i = (s);i<(n);++i)
#define DEBUG(x) do { std::cerr << #x << ": " << x << std::endl; } while (0)
using namespace std;
int n;
void dfs(vector<vector<bool>> &marked,vector<vector<int>> &v,int i,int j){
    if(i == -1 || j == -1 || i == n || j == n)return;
    if(v[i][j] == 0)return;
    if(marked[i][j])return;
    marked[i][j] = 1;
    dfs(marked,v,i-1,j);
    dfs(marked,v,i,j-1);
}
void solve(){
    cin>>n;
    vector<vector<int>> v(n,vector<int> (n));
    rep(i,0,n){
        rep(j,0,n){
            char ch;cin>>ch;
            v[i][j] = ch-'0';
        }
    }
    vector<vector<bool>> marked(n,vector<bool> (n,0));
    rep(i,0,n){
        dfs(marked,v,i,n-1);
        dfs(marked,v,n-1,i);
    }
    string ans = "YES";
    rep(i,0,n){
        rep(j,0,n){
            if(v[i][j] == 1 && !marked[i][j]){
                ans = "NO";
                break;
            }
        }
        if(ans == "NO")break;
    }
    cout<<ans;ln;
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

//APPLY DFS AT THE RIGHT EDGE AND THE BOTTOM EDGE.