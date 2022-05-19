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
    vector<int> even,odd;
    int a;
    rep(i,0,n){
        cin >> a;
        if(a&1)odd.push_back(a);
        else even.push_back(a);
    }
    sort(even.begin(),even.end());
    sort(odd.begin(),odd.end());
    ll ev = 0;
    ll od = 0;
    string ans = "Alice";
    // if(ev < od){
    //     if(even.size() == 1 &&  odd.size() == 2)ans = "Tie";
    //     else ans = "Bob";
    // }
    // else{

    // }
    while(1){
        if(odd.size() == 0)break;
        else{
            if(even[even.size()-1] > odd[odd.size()-1])ev+=even[even.size()-1];
            
        }
    }
    cout << ans;ln;
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

