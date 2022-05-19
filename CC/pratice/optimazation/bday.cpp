#include<bits/stdc++.h>
#include<unordered_map>
#define ll long long
#define ull unsigned long long
#define ln cout<<"\n"
#define dbg(x) cout<<#x<<" = "<<x<<" "
#define rep(i,s,n) for(ll i = (s);i<(n);++i)
#define DEBUG(x) do { std::cerr << #x << ": " << x << std::endl; } while (0)
using namespace std;
vector<int> squares;
void solve(){
    string s;
    cin>>s;
    int n = s.length();
    vector<int> cnt1(n+1,0),cnt0(n+1,0);
    rep(i,0,n){
        if(s[i] == '1'){
            cnt1[i+1]=1;
        }
        else cnt0[i+1] = 1;
    }
    rep(i,1,n+1){
        cnt1[i]+=cnt1[i-1]; // PREFIX SUMS OF NO OD ONES.
        cnt0[i]+=cnt0[i-1];
    }
    int x = 1;int l = x*x + x;
    int ans = 0;
    while(l <= n){
        rep(j,0,n-l+1){
            if(cnt1[l+j]-cnt1[j] == x)++ans; // SUBSTRINGS WHOSE LENGTH IS IN REQUIRED FORM
        }
        ++x;
        l = x*x + x;
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

// MAIN OBSERVATION : LENGTH IS IN THE FORM CNT1*CNT1 + CNT1 
// SO WE HAVE TO COUNT NO OF SUBSTRINGS WHOSE LENGTH IS IN THE FORM 
// X*X + X THE VALUE X MUST BE EQUAL TO THE NO OF ONES.