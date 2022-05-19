#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ln cout<<"\n"
using namespace std;
#define rep(i,s,n) for(ll i = (s);i<(n);++i)
#define pc(x) __builtin_popcount(x)
void DBG() {
	cerr << "" << endl;
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
#define dbg(...) cerr << "" << endl
#endif

#define pi pair<int,int>
#define pl pair<ll,ll> 
#define fr first
#define sc second
#define pb push_back

void solve(){
    
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> v(n),ans(n,-1);
    rep(i,0,n){
        v[i] = (s[i]=='0'?0:1);
    }
    stack<int> ones,z;
    int k = 0;
    rep(i,0,n){
        if(v[i] == 1){
            if(z.size() == 0){
                ++k;
                ones.push(i);
                ans[i] = k;
            }
            else{
                int p = z.top();
                ans[i] = ans[p];
                z.pop();
                ones.push(i);
            }
        }
        else{
            if(ones.size() == 0){
                ++k;
                z.push(i);
                ans[i] = k;
            }
            else{
                int p = ones.top();
                ones.pop();
                ans[i] = ans[p];
                z.push(i);
            }
        }
       //  ans[i] = k;

    }
    cout << k;ln;
    rep(i,0,n)cout << ans[i] << " ";
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