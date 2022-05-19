#include<bits/stdc++.h>
#include<stdio.h>
#define ll long long
#define ull unsigned long long
#define ln cout<<"\n"
using namespace std;
//#define dbg(x) cout<<#x<<" = "<<x<<" "
#define rep(i,s,n) for(ll i = (s);i<(n);++i)
#define pc(x) __builtin_popcount(x)
#define pb push_back
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

int merge(vector<int> v,int a,int b,int k){
    if(k < 0)return 1e9;
    v.pb(a);v.pb(b);
    sort(v.begin(),v.end());
    k /= 2;
    int ans = 0;
    for(int i=0;i<-k+(int)v.size();i++) ans += v[i];
    return ans;
}
void solve(){
    int n,k;
    cin >> n >> k;
    string s;
    cin >> s;
    int f = -1,l = 0;
    rep(i,0,n){
        if(s[i] == '1'){
            if(f == -1)f = i;
            l = i;
        }
    }
    if(f == -1){
        cout << 0;
        ln;
    }
    int cnt = 0;
    vector<int> v;
    rep(i,f+1,l){
        if(s[i] == '1'){
            if(cnt)v.pb(cnt);
            cnt = 0;
        }
        else ++cnt;
    }
    if(cnt)v.pb(cnt);
    rep(i,0,(int)v.size())cout << v[i] << " ";
    ln;
    dbg(f,l,n-1-l,n);
    int ans = n;
    ans = min(ans,min(min(merge(v,0,0,k-2),merge(v,0,n-1-l,k-1)),min(merge(v,f,0,k-1),merge(v,f,n-1-l,k))));
    cout << ans;
    ln;

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

// codechef prblm