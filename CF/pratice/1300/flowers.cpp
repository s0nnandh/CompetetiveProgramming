#include<bits/stdc++.h>
#include<unordered_map>
#define ll long long
#define ull unsigned long long
#define ln cout<<"\n"
#define dbg(x) cout<<#x<<" = "<<x<<" "
#define rep(i,s,n) for(ll i = (s);i<(n);++i)
#define DEBUG(x) do { std::cerr << #x << ": " << x << std::endl; } while (0)
using namespace std;
void solve(){
    int n;cin>>n;
    vector<int> v(n);int maf = 0, mif = 1e9;
    rep(i,0,n){
        cin>>v[i];
        maf = max(maf,v[i]);
        mif = min(mif,v[i]);
    }
    ll n1 = 0,n2 = 0;
    rep(i,0,n){
        if(v[i] == maf)++n1;
        else if(v[i] == mif)++n2;
    }   
    ll ans = n1 * n2;
    if(maf == mif)ans = (n1*(n1-1))/2;
    cout<<maf - mif<<" "<<ans;ln;

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);    
    int test=1;
    //cin>>test;   
    while(test--)
        solve();
    return 0;
}

// JUST FIND MAX AND MIN ELEMENT AND THEIR NO OF OCCURENCES