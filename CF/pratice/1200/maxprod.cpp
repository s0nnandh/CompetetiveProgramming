#include<bits/stdc++.h>
#include<unordered_map>
#define ll long long
#define ull unsigned long long
#define ln cout<<"\n"
#define dbg(x) cout<<#x<<" = "<<x<<" "
#define for(i,s,n) for(ll i = (s);i<(n);++i)
using namespace std;
bool cmp(ll a,ll b){
    return abs(a) > abs(b);
}
void solve(){
    int n;
    cin>>n;
    vector<ll> v(n);ll mx = -1e9;
    for(i,0,n){
        cin>>v[i];
        mx = max(mx,v[i]);
    }
    sort(v.begin(),v.end(),cmp);
    //for(i,0,n)cout<<v[i]<<" ";
    //ln;
    if(mx < 0){
        cout<<v[n-1]*v[n-2]*v[n-3]*v[n-4]*v[n-5];
    }
    else{
        ll ans = v[0]*v[1]*v[2]*v[3]*v[4];
        //dbg(ans);ln;
        for(i,5,n){
            for(j,0,5){
                ll tmp = v[i];
                for(k,0,5){
                    //dbg(j);dbg(k);ln;
                    if(j != k)tmp*=v[k];
                }
                ans = max(ans,tmp);
            }
        }
        cout<<ans;
    }
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

// UPADTE ANSWER BY CHECKING CREATING PRODUCT OF EVERY FIVE NUMBERS BY FIRST 
// CREATING A VARIABLE WHICH SRORES INITILALLY THE PRODUCT OF THE FIRST FIVE NUMBERS.