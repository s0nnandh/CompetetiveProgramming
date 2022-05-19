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
    bool st = 0;
    rep(i,0,n){
        string s;
        cin >> s;
        if(s == "start"){
            // if(st){
            //     cout << 404;ln;
            //     return;
            // }
            // else 
            st = 1;
        }
        else if(s == "restart")st = 1;
        else if(s == "stop"){
            if(!st){
                cout << 404;ln;
                return;
            }
            else st = 0;
        }
    }
    cout << 200 ;ln;
   
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

