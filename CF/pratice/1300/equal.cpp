#include<bits/stdc++.h>
#include<unordered_map>
#define ll long long
#define ull unsigned long long
#define ln cout<<"\n"
#define dbg(x) cout<<#x<<" = "<<x<<" "
#define rep(i,s,n) for(ll i = (s);i<(n);++i)
using namespace std;
string s,f;int n;
int check(int i){
    if(i>0 && s[i-1] == '1' && f[i-1] != '1'){
        s[i-1] = '0';
        s[i] = '1';
        return 1;
    }
    if(i<n-1 && s[i+1] == '1' && f[i+1] != '1'){
        s[i+1] = '0';
        s[i] = '1';
        return 1;
    }
    return 1;
}
void solve(){    
    cin>>n;    
    cin>>s>>f;int ans = 0;
    rep(i,0,n){
        if(f[i] == '1' && s[i] != '1'){
            ans+=check(i);
        }
    }
    //int scnt = 0,fcnt = 0;
    rep(i,0,n){
        if(s[i] == '1' && f[i] != '1')++ans;
    }
    cout<<ans;ln;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);    
    int test=1;
    //cin>>test;   
    while(test--)
        solve();
}

// JUST SIMPLY IT IS EITHER 1 OR 2 FOR EACH INDEX.