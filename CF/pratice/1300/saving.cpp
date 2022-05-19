#include<bits/stdc++.h>
#include<unordered_map>
#define ll long long
#define ull unsigned long long
#define ln cout<<"\n"
#define dbg(x) cout<<#x<<" = "<<x<<" "
#define rep(i,s,n) for(ll i = (s);i<(n);++i)
using namespace std;

void solve(){
    ll a,b;
    cin>>a>>b;
    string s;;
    cin>>s;
    int n = s.size();
    vector<int> v;
     rep(i,0,n){        
        if(i == 0)v.push_back(s[i]-'0');
        else{
            if(s[i] == '1'){
                if(v[v.size()-1] != 1)v.push_back(1);
            }
            else v.push_back(0);
        }
    }
    ll l = v.size(),prev = -1,ans = 0;
    rep(i,0,l){
        if(v[i] == 1){
            if(prev == -1){
                prev = i;
                ans = a;
            }
            else{
                ans+=min((i-prev-1)*b,a);
                prev = i;
            }
        }
    }
    //if(ans == a && !there)ans = 0;
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

// YOU HAVE TO DECIDE WHETHER IT IS BETTER TO ADD MINES OR ACTIVATE A
// NEW MINE GREEDILY.
// EG:-
// 100100101
// AFTER THE FIRST ONE U DO ans+=min(2*b,a) TO SEE WHETHER WHICH IS BETTER
// TO ADD OR ACTIVATE THE NEW 1.