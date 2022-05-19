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
    
    int n;
    cin >> n;
    vector<ll> v(n);
    for(auto &i : v)cin >> i;
    ll ev = 0,od = 0,ans = 0,ptr = 0,sum = 0;
    while(ptr < n){        
        if(ptr&1){
            od += v[ptr];
            if(od > ev){
                ans = max(ans,od - ev);
            }
            else{
                od = 0;
                ev = 0;
            }
        }
        else{
            sum += v[ptr];
            ev += v[ptr];
        }
        ++ptr;
    }
    ptr = 1;od = 0;ev = 0;
    while(ptr < n){
        if(ptr&1){
            od += v[ptr];
        }
        else{
            ev += v[ptr];
            if(od > ev){
                ans = max(ans,od - ev);
            }
            else{
                od = 0;
                ev = 0;
            }
        }
        ++ptr;
    }
    cout << sum + ans;ln;
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