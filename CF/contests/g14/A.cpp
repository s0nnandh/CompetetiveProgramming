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

#define pi pair<int,int>


void solve(){
    int n,k;
    cin >> n >> k;
    vector<int> v(n);
    int s = 0;
    rep(i,0,n){
        cin >> v[i];
        s+=v[i];
    }
    if(s == k){
        cout << "NO";
        ln;
    }   
    else{
        cout << "YES";
        ln;
        int ss = 0;
        vector<int> ans(n); 
        rep(i,0,n){
            ans[i] = v[i];
            ss+=v[i];
            if(ss == k){
                ans[i] = v[i+1];
                //++i;
                ans[i+1] = v[i];
                s+=v[i+1];
                ++i;
            }
        }   
        rep(i,0,n){
            cout << ans[i] << " ";
        }
        ln;
    }
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

