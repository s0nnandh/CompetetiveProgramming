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


void solve(){
    
    int n;
    cin >> n;
    vector<int> x,y;
    rep(i,0,2*n){
        int a,b;
        cin >> a >> b;
        if(a == 0){
            y.push_back(b);
        }
        else x.push_back(a);
    }
    sort(x.begin(),x.end());
    sort(y.begin(),y.end());
    cout << setprecision(15) << fixed;
    double ans = 0;
    rep(i,0,n){
        dbg((1.0*x[i]*x[i])+(y[i]*y[i]));
        ans+=sqrt((1.0*x[i]*x[i])+(1.0*y[i]*y[i]));
    }
    cout << ans;ln;
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

