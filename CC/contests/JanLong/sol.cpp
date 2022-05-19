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
    int n,x,y;
    cin >> n >> x >> y;
    int arr[n],a[n];
    rep(i,0,n){
        cin >> arr[i];
        a[i] = arr[i];
    }
    // if(arr[0] >= x && arr[0] <= y){
    //     cout << 0;
    //     ln;
    //     return;
    // }
    // rep(i,1,n){
    //     if(a[i] >=x && a[i] <= y){
    //         cout << 1;
    //         ln;
    //         return;
    //     }
    // }
    int ans = 1e9;
    do { 
        int s = 0,ch = 0;
        rep(i,0,n){
            if(arr[i] != a[i])++ch;
        }
        rep(i,0,n){
            s+=arr[i];
            if((s>=x && s<=y) || s > y)break;
        }
        if(s >= x && s<=y)ans = min(ans,ch/2);
        if(ans == 0 || ans == 1)break;
	} while (next_permutation(arr, arr + n)); 
    cout << (ans==1e9?-1:ans);ln;
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

