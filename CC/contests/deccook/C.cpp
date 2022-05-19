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
    string s;
    cin>>s;int n = s.size();
    int sum = 0;
    rep(i,0,n){
        if(s[i] == '1')++sum;
        else --sum;
    }
    if(sum == 0 || (abs(sum) != n && abs(sum) % 2 == 0))cout<<abs(sum)/2;
    else cout<<-1;
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