#include<bits/stdc++.h>
#include<unordered_map>
#define ll long long
#define ull unsigned long long
#define ln cout<<"\n"
#define dbg(x) cout<<#x<<" = "<<x<<" "
#define rep(i,s,n) for(ll i = (s);i<(n);++i)
using namespace std;
int fac(int k){
    int fact = 1;
    for(int i=1; i<=k; i++)
        fact = fact * i;
    return fact;
}
void solve(){
   map<char,int> g,ans;
    string s1,s2;
    cin>>s1>>s2;
    cout<<setprecision(12)<<fixed;
    int n = s1.size();
    rep(i,0,n){
        g[s1[i]]++;
        ans[s2[i]]++;
    }
    if(ans['?']+ans['+'] < g['+'] || ans['?'] + ans['-'] < g['-']){
        cout<<double(0);
    }
    else{
        double k = (1<<ans['?']);
        int a = g['+'] + g['-'] - ans['+'] - ans['-'];
        int h = g['+'] - ans['+'];int t = g['-'] - ans['-'];
        double prob = (double)fac(a)/(double)(fac(h)*fac(t));
        cout<<prob/k;
    }
    ln;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);    
    int test=1;
    //cin>>test;   
    while(test--)
        solve();
}