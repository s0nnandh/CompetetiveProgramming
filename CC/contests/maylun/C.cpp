// https://www.codechef.com/MARCH21B/problems/PAPARAZI

#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ln cout<<"\n"
using namespace std;
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
#define dbg(...) {}
#endif

#define pi pair<int,int>
#define pl pair<ll,ll> 
#define fr first
#define sc second
#define pb push_back
#define gcd(a,b) __gcd(a,b)


void solve(){

   int n,k;
   cin >> n >> k;
   vector<ll> v(n);
   ll sum = 0,a = -1e18;
   for(auto &i : v)cin >> i;
   rep(i,0,n){
       sum += v[i];
       a = max(a,sum);
       sum = max(sum,0LL);
       
   }
   cout << a;ln;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL); 
    //gen_factorial(1e6);  

    int test=1;
    cin>>test;   
    while(test--)
        solve();
    return 0;
}