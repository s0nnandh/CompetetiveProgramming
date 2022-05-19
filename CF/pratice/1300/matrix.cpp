#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ln cout<<"\n"
#define dbg(x) cout<<#x<<" = "<<x<<" "
#define rep(i,s,n) for(ll i = (s);i<(n);++i)
#define DEBUG(x) do { std::cerr << #x << ": " << x << std::endl; } while (0)
using namespace std;
ll n,m;
void solve(){
    cin>>n>>m;
    vector<vector<ll>> v(n,vector<ll> (m));
    rep(i,0,n)
        rep(j,0,m)cin>>v[i][j];
    ll ans = 0;
    rep(i,0,n/2)
        rep(j,0,m/2){
            ll sum = 0;
            sum+=v[i][m-1-j]+v[n-1-i][j]+v[i][j]+v[n-1-i][m-1-j];
            vector<int> temp;
            temp.push_back(v[i][m-1-j]);
            temp.push_back(v[n-1-i][j]);
            temp.push_back(v[i][j]);
            temp.push_back(v[n-1-i][m-1-j]); 
            sort(temp.begin(),temp.end());           
            // dbg(i);dbg(m-1-j);ln;
            // dbg(n-1-i);dbg(j);ln;
            // dbg(i);dbg(j);ln;
            // dbg(n-1-i);dbg(m-1-j);ln;
            // DEBUG(sum/4);
            ans+=temp[1]-temp[0] + temp[2]-temp[1] + temp[3]-temp[1];
            //ans+=abs(v[i][m-1-j]-(sum/4))+abs(v[n-1-i][j]-(sum/4))+abs(v[i][j]-(sum/4))+abs(v[n-1-i][m-1-j]-(sum/4));
        }
    if(n&1){
        rep(i,0,m/2){
            ll sum = 0;
            sum+=v[(n-1)/2][m-1-i]+v[(n-1)/2][i];
        //    dbg((n-1)/2);dbg(m-1-i);dbg(i);ln;
        //     DEBUG(sum/2);
             ans+=abs(v[(n-1)/2][m-1-i]-v[(n-1)/2][i]);
        }
    }
    if(m&1){
        rep(i,0,n/2){
            ll sum = 0;
            sum+=v[i][(m-1)/2]+v[n-1-i][(m-1)/2];
            // dbg((m-1)/2);dbg(i);dbg(n-1-i);ln;
            //DEBUG(sum/2);
            ans+=abs(v[i][(m-1)/2]-v[n-1-i][(m-1)/2]);
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

//YOU HAVE TO MAKE ALL THE 4 OR 2 VALUES TAKEN AND MAKE IT EQUAL TO ONE OF THE NUMBERS.