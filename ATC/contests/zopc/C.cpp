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
#define ctz(x) __builtin_ctzll(x)
#define pb push_back


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);    
    int tt = 1;
	// cin >> tt;	
	while(tt--){	
        int n;
        cin >> n;
        int A = 0,B = 0,C = 0,D = 0,E = 0;
        rep(i,0,n){
            int a,b,c,d,e;
            cin >> a >> b >> c >> d >> e;
            A = max(A,a);
            B = max(B,b);
            C = max(C,c);
            D = max(D,d);
            E = max(E,e);
        }

        cout << min(A,min(B,min(C,min(D,E))));
	}   
}


