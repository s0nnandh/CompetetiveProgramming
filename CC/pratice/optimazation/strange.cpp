#include<bits/stdc++.h>
#include<unordered_map>
#define ll long long
#define ull unsigned long long
#define ln cout<<"\n"
#define dbg(x) cout<<#x<<" = "<<x<<" "
#define rep(i,s,n) for(ll i = (s);i<(n);++i)
#define DEBUG(x) do { std::cerr << #x << ": " << x << std::endl; } while (0)
using namespace std;
int n,x;ll m;
const int mod = 1e9 + 7;
const int MAXN = 100002;
vector<ll> factorial(MAXN+1);
/*struct  Matrix
{
	ll **a;
    ll X;
	Matrix(ll y){
       this -> X = y;
        for(ll i = 0; i < X; ++i)
            a[i] = new ll[X];
	}
	Matrix operator *(Matrix &other){
		Matrix product(X);
		rep(i,0,X){
			rep(j,0, X){
				rep(k,0,X){
					product.a[i][k] += a[i][j] * other.a[j][k];
				}
			}
		}
		return product;
	}	
};
*/
long long nck(int n, int k) {
    return factorial[n]/(factorial[k] * factorial[n - k] % mod) % mod;
}
void solve(){
    
    cin>>n>>x>>m;
    vector<ll> a(n+1);
    rep(i,1,n+1)cin>>a[i];
    ll ans = 0;
    // 4c0 D
    for(int i = n;i>=1;--i){
        //ans=ans + (a[n]*(nck()))%mod
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL); 
    factorial[0] = 1;
    for (int i = 1; i <= MAXN; i++) {
        factorial[i] = factorial[i - 1] * i % mod;
    }   
    int test=1;
    cin>>test;   
    while(test--)
        solve();
    return 0;
}