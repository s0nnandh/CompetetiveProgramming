#include<bits/stdc++.h>
#define ll long long
#define ln cout<<"\n"
#define dbg(x) cout<<#x<<" = "<<x<<" "
#define FOR(i,n) for(int i = 0;i<(n);++i)
#define FORS(i,s,n) for(ll i = (s);i<(n);++i)
using namespace std;
int n,q,s;set<ll> sums;
void check(int i,int j,vector<int> &arr,vector<ll> &sum){
    if(i == j){
        sums.insert(arr[i]);
        return;
    }
    if(arr[i] == arr[j])return;
    int idx = upper_bound(arr.begin()+i,arr.begin()+j,(arr[i]+arr[j])/2)-arr.begin();
    //dbg(idx);
    sums.insert(sum[idx-1]-sum[i-1]);sums.insert(sum[j]-sum[idx-1]);
    check(i,idx-1,arr,sum);check(idx,j,arr,sum);
}
void solve(){
    sums.clear();
    cin>>n>>q;
    vector<int> arr(n+1);vector<ll> sum(n+1,0);
    //arr = new int[n+1];sum = new int[n+1];
    for(int i = 1;i<=n;++i)cin>>arr[i];
    sum[0] = 0;    
    sort(arr.begin(),arr.end());
    for(int i = 1;i<=n;++i)sum[i] = sum[i-1]+arr[i];
    sums.insert(sum[n]);
    check(1,n,arr,sum);
    for(int i = 0;i<q;++i){
        cin>>s;
        sums.find(s)!=sums.end()?cout<<"YES":cout<<"NO";ln;
    }    
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

// DIVIDE AND CONQUER THE PROBLEM BY FINDING ALL POSSIBLE SUB ARRAYS
// AND STORE THEM IN A SET AND USE PREFIX SUMS TO CALCULATE SUM IN
// O(1) TIME.