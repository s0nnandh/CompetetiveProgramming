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
    int n;
    cin >> n;
    if(n == 1){
        int m;
        cin >> m;
        vector<int> v(m);
        ll minus = 0,pos = 0;
        rep(i,0,m){
            cin >> v[i];
            if(v[i] < 0)++minus;
            else ++pos;
        }
        cout << minus*pos ;ln;
    }
    else{
        cout << -1;ln;
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

// FOR N = 1 IT IS THE PRODUCT OF NUMBERS IN LEFT AND RIGHT OF O.