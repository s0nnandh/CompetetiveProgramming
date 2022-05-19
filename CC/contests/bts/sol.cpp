#include<bits/stdc++.h>
#include<stdio.h>
#define ll long long
#define ull unsigned long long
#define ln cout<<"\n"
using namespace std;
//#define dbg(x) cout<<#x<<" = "<<x<<" "
#define rep(i,s,n) for(ll i = (s);i<(n);++i)
#define pc(x) __builtin_popcount(x)
void DBG() {
	cerr << "]" << endl;
}
template<class H, class... T> void DBG(H h, T... t) {
    //cerr << '[' << endl;
	cerr << to_string(h);
	if(sizeof...(t))
		cerr << ", ";
	DBG(t...);
}
#ifdef _DEBUG
#define dbg(...) cerr << "LINE(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)
#else
#define dbg(...) cerr << "[ ]" << endl
#endif

#define pl pair<ll,ll>

void solve(){
    
   int n,k;
   cin >> n >> k;
   map<int,int> mp;
   rep(i,0,n){
       int a;
       cin >> a;
        mp[a%k]++;  
   }
   if(pc(k) == 1){
       cout << "YES";ln;
       return;
   }
   if(mp[1] && mp[k-1]){
       cout << "YES";ln;
       return;
   }
   if(!mp[1]){
        for(auto x : mp){
            int y = x.first;
            if(mp[y] != x.second){
                cout << "NO";
                ln;
                return;
            }
        }
        cout << "YES";ln;
        return;
   }
   cout << "NO";ln;
   

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

