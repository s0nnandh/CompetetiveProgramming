#include<bits/stdc++.h>
#include<unordered_map>
#define ll long long
#define ull unsigned long long
#define ln cout<<"\n"
#define dbg(x) cout<<#x<<" = "<<x<<" "
#define rep(i,s,n) for(ll i = (s);i<(n);++i)
#define DEBUG(x) do { std::cerr << #x << ": " << x << std::endl; } while (0)
using namespace std;
ll check(ll a,ll b,ll c,ll d){
     ll max1 = max(a,b),max2 = max(c,d);
     if(max1 > max2){
         if(min(a,b) > max2)max2 = min(a,b);
     }
     else if(max2 > max1){
         if(min(c,d) > max1)max1 = min(c,d);
     }
     return max1+max2;
}
void solve(){
    ll n;
    cin >> n;
    vector<ll> v(n);
    rep(i,0,n){
        cin>>v[i];
    }
    ll ans = 0;
    rep(i,0,n){
        //ll left = max(v[(n-1+i)%n],v[(n-2+i)%n]);
        //ll right  = max(v[(i+1)%n],v[(i+2)%n]);
        //dbg(v[(n-1+i)%n]);dbg(v[(n-2+i)%n]);dbg(v[i]);dbg(v[(i+1)%n]);dbg(v[(i+2)%n]);ln;
        ans = max(ans,v[i]+v[(n-1+i)%n]+v[(i+1)%n]);
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

// SHOULD NOTICE THAT IT IS ENOUGH TO CHECK CONSECUTIVE THREE NUMBERS 
// BECAUSE THERE IS NO WAY TO BE IN A TEAM.