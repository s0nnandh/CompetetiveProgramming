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
    int a,b,c;
    cin >> a >> b >> c;
    if(c == 0){
        while(a >= 0 && b >= 0){
            a--;
            if(a < 0)break;
            b--;
        }
        if(a == -1){
            cout << "Aoki";ln;
            return;
        }
        else {
            cout << "Takahashi";ln;
            return;
        }
    }
    else{
        while (a >= 0 && b >= 0)
        {
            /* code */
            --b;
            if(b < 0)break;
            --a;

        }
        if(a == -1){
            cout << "Aoki";ln;
            return;
        }
        else {
            cout << "Takahashi";ln;
            return;
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);    
    int test=1;
    //cin>>test;   
    while(test--)
        solve();
    return 0;
}

