#include<bits/stdc++.h>
#include<unordered_map>
#define ll long long
#define ull unsigned long long
#define ln cout<<"\n"
#define dbg(x) cout<<#x<<" = "<<x<<" "
#define rep(i,s,n) for(ll i = (s);i<(n);++i)
#define DEBUG(x) do { std::cerr << #x << ": " << x << std::endl; } while (0)
using namespace std;
const int m = 1e9 + 7;
const int MOD = 1e9+7;
const int MAX = 1e5+7;
ll prefixValue[MAX];
ll suffixValue[MAX];
// DONT FORGET TO KEEP BRACKETS IDIOT
void solve(){
    int n;
    cin>>n;
    vector<ll> v(n+1),suffix(n+2,0),prefix(n+2,0);
    rep(i,1,n+1)cin>>v[i];
    rep(i,1,n+1){
        prefix[i] = prefix[i-1] + v[i];
    }
    rep(j,0,3){
        rep(i,1,n+1){
            prefix[i] = (prefix[i-1] + prefix[i]) % m;
        }
    }
    // rep(i,0,n+2)cout<<prefix[i]<<" ";
    // ln;
    for(int i = n;i>0;--i){
        suffix[i] = suffix[i+1] + v[i];
    }
    rep(j,0,3){
        for(int i = n;i>0;--i){
            suffix[i] = (suffix[i+1] + suffix[i]) % m;
        }
    }
    //rep(i,0,n+2)cout<<suffix[i]<<" ";
    //ln;
    rep(i,1,n+1){
        ll ans = (prefix[i-1] + suffix[i+1]) % m;
        cout<<ans<<" ";
    }
    ln;
    // int n; cin >> n;
	// 	ll p[n+1];
	// 	ll answer;
	// 	for(int i=1; i<=n; i++) cin >> p[i];
	// 	for(int j=0; j<4; j++){
	// 		if(j==0){
	// 			for(int i=1; i<=n; i++){
	// 				prefixValue[i] = p[i];
	// 				suffixValue[i] = p[i];	
	// 			}	
	// 		}
	// 		for(int i=1; i<=n; i++) prefixValue[i] = (prefixValue[i-1] + prefixValue[i])%MOD;
	// 		for(int i=n; i>0; i--) suffixValue[i] = (suffixValue[i+1] + suffixValue[i])%MOD;
	// 	}
    //     rep(i,0,n+2)cout<<prefixValue[i]<<" ";
    //     ln;
    //     rep(i,0,n+2)cout<<suffixValue[i]<<" ";
    //     ln;
	// 	for(int i=1; i<=n; i++){
	// 		answer = (prefixValue[i-1]+suffixValue[i+1])%MOD;
	// 		cout << answer << " ";	
	// 	} 
	// 	cout << "\n";
	// 	for(int i=1; i<=n; i++){
	// 		prefixValue[i] = 0;
	// 		suffixValue[i] = 0;	
	// 	} 
    
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

// TRIAL
// #include<bits/stdc++.h>
// #include<unordered_map>
// #define ll long long
// #define ull unsigned long long
// #define ln cout<<"\n"
// #define dbg(x) cout<<#x<<" = "<<x<<" "
// #define rep(i,s,n) for(ll i = (s);i<(n);++i)
// #define DEBUG(x) do { std::cerr << #x << ": " << x << std::endl; } while (0)
// using namespace std;
// const int MAXN  = 1e5;
// vector<ll> factorial(MAXN+1);
// const int m = 1e9 + 7;
// //vector<vector<ll>> store(MAXN+1,vector<ll> (MAXN+1,-1));
// vector<ll> store(MAXN+1,-1);
// void nck(int n, int k) {
//     store[n] =  (factorial[n]/((factorial[k] * factorial[n - k]) % m)) % m;
//     //return store[n];
// }
// void solve(){
//     int n;
//     cin>>n;
//     vector<ull> v(n),ans(n,0);
//     for(auto& i : v)cin>>i;
//     int l,r,k;
//     rep(i,0,n){
//         l = i-1,r = i+1;k = 3;
//         while(l>=0 && r<n){
//             ans[i]=(ans[i]+(store[k]*(v[l]+v[r])) % m)%m;
//             ++k;
//             --l;
//             ++r;
//         }
//         while(l >= 0){
//             ans[i]=(ans[i] + (store[k]*v[l] % m))%m;
//             --l;
//             ++k;
//         }
//         while(r<n){
//             ans[i]=(ans[i] + (store[k]*v[r] % m))%m;
//             ++r;
//             ++k;
//         }
//     }
//     rep(i,0,n)cout<<ans[i]<<" ";
//     ln;
// }

// int main(){
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     cout.tie(NULL);
//     factorial[0] = 1;
//     for (int i = 1; i <= MAXN; i++) {
//         factorial[i] = (factorial[i - 1] * i) % m;
//         //cout<<factorial[i]<<"\n";
//         if(i>=3)nck(i,3);
//     }  

//     int test=1;
//     cin>>test;   
//     while(test--)
//         solve();
//     return 0;
// }