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

int n;
void create(vector<int> &dpt,vector<int> &r,int i ,int j,int p){
    if(i > j)return;
    //dbg(i,j);
    int m = 0,idx = -1;
    rep(k,i,j+1){
        if(m < r[k]){
            m = r[k];
            idx = k;
        }
    }
    //dbg(m,p);
    dpt[m]=dpt[p]+1;
    create(dpt,r,i,idx-1,m);
    create(dpt,r,idx+1,j,m);
}   

void solve(){
    
    cin >> n;
    vector<vector<int>> adj(n+1);
    vector<int> pos(n+1),r(n+1);
    rep(i,1,n+1){
        //int k;
        cin >> r[i];
        pos[i] = r[i];
        //r[k] = n-k;
        //dbg(r[i]);
    }
    vector<int> dpt(n+1);
    create(dpt,r,1,n,0);
    rep(i,1,n+1)cout << --dpt[pos[i]] << " ";
    ln;
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

