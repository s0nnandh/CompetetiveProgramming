#include<bits/stdc++.h>
#define ll long long
#define ln "\n"
#define dbg(x) cout<<#x<<" = "<<x<<ln
#define FOR(i,n) for(int i = 0;i<(n);++i)
#define FORS(i,s,n) for(ll i = (s);i<(n);++i)
using namespace std;
int m,n,r;float pr;
double _pow(double &a, int b) {
    double res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a ;
        a = a * a;
        b >>= 1;
    }
    return res;
}
void solve(){
   cin>>n>>m;
   int arr[n+1];int idx = 1;
   for(int i = 1;i<=n;++i){
       cin>>arr[i];
       if(arr[i] != i)idx = i;
   }
   cout<<setprecision(6)<<fixed;   
   vector<pair<int,float>> p;
   for(int i = 0;i<m;++i){
       cin>>r>>pr;
       if(r>=idx){
           p.push_back(make_pair(r,pr));
       }
   }
   if(idx == 1){
       cout<<float(1)<<ln;
       return;
   }
   //sort(p.begin(),p.end());int l = p.size();
   /*for(auto x : p){
       dbg(x.first);
       dbg(x.second);
   }*/
   int l = p.size();
   float t = 1;
   for(int i = 0;i<l;++i){
       t*=(1-p[i].second);
   }
   
   cout<<1-t<<ln;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);    
    int test=1;
    cin>>test;   
    while(test--)
        solve();
}