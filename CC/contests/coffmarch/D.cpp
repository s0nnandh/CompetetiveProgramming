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

#define pi pair<ll,ll>
#define pb push_back

int computeXOR(int n){ 
  if (n % 4 == 0)
    return n;
 
  
  if (n % 4 == 1)
    return 1;
 
  
  if (n % 4 == 2)
    return n + 1;
 
  
  return 0;
}

void solve(){
    ll n,m,k;
    cin >> n >> m >> k;
    ll maxx = max(n,m),minn = min(n,m);    
    ll f = computeXOR(k+1+maxx)^computeXOR(k+1);
    ll first = k + 2,last = k + maxx+1;
    //dbg(first,last,f);
    ll ans = f;
    rep(i,0,minn-1){
        last++;
        //ll t=f^last^first;
        f^=last;
        f^=first;
        ans^=f;
        ++first;
        //dbg(f,last,first);
    }
    cout << ans;ln;
    // ll f = computeXOR(k+1+n)^computeXOR(k+1);
    // ll ff = k+2,l = k + 1 + n;
    // //dbg(f,ff,l);
    // dbg(f);
    // rep(i,0,m-1){
    //     ++l;
    //     ll t = f ^ l ^ ff;
    //     dbg(ff,l);
    //     f^=t;
    //     dbg(t,f,l,ff);
    //     ++ff;
        
    // }
    // cout << f;ln;
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
