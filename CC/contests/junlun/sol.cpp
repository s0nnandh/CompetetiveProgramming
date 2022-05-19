#include<bits/stdc++.h>
#define ll long long
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
#define dbg(...) cerr << "" << endl
#endif

#define pi pair<int,int>
#define pl pair<ll,ll> 
#define fr first
#define sc second
#define pb push_back
#define gcd(a,b) __gcd(a,b)
#define sz(x) (int)x.size()
#define all(x) x.begin(),x.end()
#define vi vector<int>
#define vl vector<ll>

void solve(){
    int n;
    cin >> n;
    // vector<vector<int>> q(n,vector<int> (n));
    auto ask = [&](int k,bool b){
        vector<vector<int>> q(n,vector<int> (n,1));
        // b 1 row b 0 col
        if(b){
            rep(i,0,n)q[k][i] = 0;
        }
        else{
            rep(i,0,n)q[i][k] = 0;
        }
        cout << '?' << endl;
        rep(i,0,n){
            rep(j,0,n)cout << q[i][j];
            cout << endl;
        }
        int reply;
        cin >> reply;
        return reply;
    };
    // ask rows 
    int row = 0,col = 0;
    rep(i,1,n - 1){
        int r = ask(i,1);
        if(r == 1){
            row = i;
            break;
        }
    }
    rep(i,1,n-1){
        int r = ask(i,0);
        if(r == 1){
            col = i;
            break;
        }
    }
    cout << '!' << endl;
    cout << row << " " << col << endl;
    int ans;
    cin >> ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL); 
    // gen_factorial(1e6);  	
    int test=1;
	cin>>test;   
    while(test--)
        solve();
    return 0;
}
