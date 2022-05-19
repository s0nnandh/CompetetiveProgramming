#include<bits/stdc++.h>
#include<unordered_map>
#define ll long long
#define ull unsigned long long
#define ln cout<<"\n"
#define dbg(x) cout<<#x<<" = "<<x<<" "
#define rep(i,s,n) for(ll i = (s);i<(n);++i)
using namespace std;

void solve(){
    int n,x;
    cin>>n>>x;
    vector<int> v(n);
    rep(i,0,n)cin>>v[i];
    int ans = 1e9;
    //sort(v.begin(),v.end(),greater<int>());
    rep(i,0,n){
        int t = x/v[i];
        if(t == 0){
            ans = min(ans,2);
        }
        else if((x%v[i]) == 0){
            ans = min(ans,t);
        }   
        else{
            ans = min(ans,t+1);
        }
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

//---