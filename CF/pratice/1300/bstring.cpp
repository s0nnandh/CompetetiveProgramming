#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ln cout<<"\n"
#define dbg(x) cout<<#x<<" = "<<x<<" "
#define rep(i,s,n) for(ll i = (s);i<(n);++i)
using namespace std;
void solve(){
   int n,k;
   cin>>n>>k;
   vector<char> ans(n,'a');
   int pos = 0;
   while(k>0){
       k-=++pos;
   }
   ans[n-pos-1] = 'b';
   ans[n-pos-k] = 'b';
   rep(i,0,n)cout<<ans[i];
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
}