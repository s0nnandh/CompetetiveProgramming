// https://codeforces.com/contest/1364/problem/C
#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ln cout<<"\n"
using namespace std;
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
#define dbg(...) {}
#endif

#define pi pair<int,int>
#define pl pair<ll,ll> 
#define fr first
#define sc second
#define pb push_back
#define gcd(a,b) __gcd(a,b)



void solve(){   

    int n;
    cin >> n;
    vector<bool> cnt(3*n + 1);
    vector<int> v(n);
    for(auto &i : v){
        cin >> i;
        cnt[i] = 1;
    }
    priority_queue<int,vector<int>,greater<int>> q;
    rep(i,0,3*n + 1){
        if(!cnt[i])q.push(i);
    }
    vector<int> b(n,-1);
    rep(i,1,n){
        if(v[i] != v[i-1])b[i] = v[i-1];
    }
    rep(i,0,n){
        if(b[i] == -1){
            b[i] = q.top();
            q.pop();
        }
    }
    for(auto x : b)cout << x << " ";
    ln;

}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL); 
    //gen_factorial(1e6);   
    int test=1;
    // cin>>test;   
    while(test--)
        solve();
    return 0;
}