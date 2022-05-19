#include<bits/stdc++.h>
#include<unordered_map>
#define ll long long
#define ull unsigned long long
#define ln cout<<"\n"
#define dbg(x) cout<<#x<<" = "<<x<<" "
#define rep(i,s,n) for(ll i = (s);i<(n);++i)
#define DEBUG(x) do { std::cerr << #x << ": " << x << std::endl; } while (0)
using namespace std;
ll max_(ll a,ll b,ll c,ll d){
    return max(max(a,b),max(c,d));
}
void solve(){
    int n,k;
    cin>>n>>k;
    vector<int> v(n);
    for(auto& it : v)cin>>it;    
    // ll a = 0,ans = -1e9,s = 0,end = 0,t = 0,sum = 0,pos = 0,maxi = -1e9;
    // rep(i,0,n){
    //     maxi = max(maxi,(ll)v[i]);
    //     if(v[i] >= 0)++pos;
    //     sum += v[i];
    //     a+=v[i];
    //     if(a<0){
    //         t = i+1;
    //         a = 0;
    //     }
    //     if(a >= ans){
    //         s = t;
    //         end = i;
    //         ans = a;
    //     }        
    // }
    // ll left = 0,right = 0;
    // rep(i,0,s)left+=v[i];
    // rep(i,end+1,n)right+=v[i];
    // dbg(left);dbg(right);ln;
    // if(pos == 0){
    //     cout<<maxi;ln;
    //     return;
    // }
    // if((s != 0 && end != n-1) || (s == 0 && end == n-1)){
    //     if(ans > abs(left) + abs(right)){
    //         cout<<sum*k + abs(left) + abs(right);ln;
    //         return;
    //     }
    //     cout<<ans;ln;
    //     return;
    // }
    // if(s == 0){
    //     if(ans > abs(right)){
    //         cout<<sum*k + abs(right);ln;
    //         return;
    //     }
    //     if(2*ans > abs(right)){
    //         cout<<2*ans + right;ln;
    //         return;
    //     }
    //     cout<<ans;ln;
    //     return;
    // }
    // if(end == n-1){
    //     if(ans > abs(left)){
    //         cout<<sum * k + abs(left);ln;
    //         return;
    //     }
    //     if(2*ans > abs(left)){
    //         cout<<2*ans + left;ln;
    //         return;
    //     }
    //     cout<<ans;ln;
    //     return;
    // }
    ll a = 0,ans = -1e9,pos = 0,mini = -1e9;
    rep(i,0,n){
        mini = max(mini,(ll)v[i]);
        if(v[i] > 0)pos++;
        a+=v[i];
        if(a<0)a = 0;
        ans = max(ans,a);
    }
    //dbg(ans);ln;
    if(pos == 0){
        cout<<mini;ln;
        return;
    }
    vector<ll> suffix(n+1,0),prefix(n+1,0);ll msuf = -1e9,mpref = -1e9;
    rep(i,1,n+1){
        suffix[i]=suffix[i-1]+v[i-1];
        msuf = max(msuf,suffix[i]);
    }
    for(int i = n-1;i>=0;--i){
        prefix[i]=prefix[i+1]+v[i];
        mpref = max(mpref,prefix[i]);
    }
    if(k>=2)cout<<max_(ans,suffix[n]*k,msuf+mpref,(suffix[n]*(k-2))+mpref+msuf);
    else cout<<ans;
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

// CASE CHECKING PROBLEM BY USING SUFFIX SUMS AND PREFIX SUM
//  Case 1
// When the answer is just the maximum sum present inside a single array of size N.

// Eg.

// 3 2

// -1e9 5 -1e9

// The answer in this case will be 5

//  Case 2
// When the answer is the sum of the entire array, K times.

// Eg.

// 3 3

// 3 3 3

// The answer in this case will be 27

//  Case 3
// When the answer is the maximum suffix of one array and the maximum prefix of the next.

// Eg:

// 4 2

// 4 -1e9 -1e9 4

// The answer in this case will be 4 + 4 = 8

//  Case 4
// When the answer is the maximum suffix of the first array + the maximum prefix of the last array + all of the arrays in the middle

// Eg.

// 3 4

// 3 -5 3

// The answer in this case will be 8.

