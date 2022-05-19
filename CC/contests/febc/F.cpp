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
const int N = 1e6;
vector<int> v(N+1,1);
void solve(){
    int x,y;
    cin >> x >> y;
    if(y < v[x]){
        cout << "Divyam";
    }
    else{
        cout << "Chef";
    }
    ln;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);       
    int test=1;
    cin>>test;
    v[0] = 0;v[1] = 0;
    for(int i = 2;i*i<=N;++i){
        if(v[i]){
            for(int j = i*i;j<=N;j+=i)v[j] = 0; 
        }
    }
    for(int i = 1;i<=N;++i)v[i]+=v[i-1];   
    while(test--)
        solve();
    return 0;
}

