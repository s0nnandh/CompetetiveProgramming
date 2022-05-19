#include<bits/stdc++.h>
#include<unordered_map>
#define ll long long
#define ull unsigned long long
#define ln cout<<"\n"
#define dbg(x) cout<<#x<<" = "<<x<<" "
#define rep(i,s,n) for(ll i = (s);i<(n);++i)
#define DEBUG(x) do { std::cerr << #x << ": " << x << std::endl; } while (0)
using namespace std;
map<int,char> mp;
void solve(){
    int n , k;
    cin >> n >> k;
    vector<int> a(26);
    int len = 0 ;
    for(int i = 25;i >=0 ;--i){
        if(k&(1<<i)){
            a[i] = 1;
            ++len;
        }
    }
    // rep(i,0,n){
    //     cout << a[i] << " ";
    // }
    // cout << endl;
    if(n>k || n<len){
        cout << -1;
        ln;
        return;
    }
    while(1){
        if(len == n)break;
        //cout << "Ji";
        for(int i = 25;i>=0;--i){
            if(i == 0)continue;
            if(a[i] >= 1){                
                --a[i];
                a[i-1]+=2;
                len++;
                break;
            }
        }
        //break;
    }
    string ans = "";
    rep(i,0,26){
        rep(j,0,a[i]){
            ans+='a'+i;
        }
    }
    cout << ans;
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
