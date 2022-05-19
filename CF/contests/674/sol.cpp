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
 
ll gcd(ll a,ll b){
    if(b == 0)return a;
    if(a%b == 0)return b;
    if(a > b)return gcd(b,a%b);
    return gcd(a,b%a);
}
// bool check(){
//     rep(i,0,n){
//             mp[v[i]%gc]++;
//         }
//         bool f = 1;
//         rep(i,0,n){
//             if(mp[gc - (v[i]%gc)] == 0){
//                 f = 0;
//                 break;
//             }
//             else{
//                 mp[gc - (v[i] % gc)]--;
//             }
//         }
// }
void solve(){
    int n;
    cin >> n;
    //set<ll> s;
    vector<ll> v(n);
    ll s = 0;
    rep(i,0,n){
        cin >> v[i];
        s+=v[i];
    }
    // set<ll,greater<int>> possible;
    // sort(v.begin(),v.end());
    // ll ans = -1;
    // rep(i,0,n){
    //     rep(j,i+1,n){
    //         ll t = v[i] + v[j];
    //         possible.insert(t);
    //         //dbg(s-t,t,gcd(s-t,t));
    //     //     map<ll,ll> mp;
    //     //     ll gc = gcd(s-t,t);
    //     //     dbg(s-t,t,gc);
    //     //     rep(l,0,n){
    //     //         mp[v[l]%gc]++;
    //     //     }
    //     //     bool f = 1;
    //     //     rep(l,0,n){
    //     //     if(mp[v[l] % gc] == 0)continue;
    //     //     if(mp[gc - (v[l]%gc)] == 0){
    //     //         f = 0;
    //     //         break;
    //     //     }
    //     //     else{
    //     //         mp[gc - (v[l] % gc)]--;
    //     //         mp[v[l] % gc]--;
    //     //     }
    //     // }
    //     // if(f == 1)ans = max(ans,gc);
    //     }
    // }
    // ll least = -1;
    // for(auto x : possible){
    //     least = x;
    //      map<ll,ll> mp;
    //         ll gc = gcd(x,s-x);
    //         //dbg(s-t,t,gc);
    //         rep(l,0,n){
    //             mp[v[l]%gc]++;
    //         }
    //         bool f = 1;
    //         rep(l,0,n){
    //         if(mp[v[l] % gc] == 0)continue;
    //         if(mp[gc - (v[l]%gc)] == 0){
    //             f = 0;
    //             break;
    //         }
    //         else{
    //             mp[gc - (v[l] % gc)]--;
    //             mp[v[l] % gc]--;
    //         }
    //     }
    //     if(f == 1){
    //         ans = gc;
    //         break;
    //     }
    //     mp.clear();
    //     gc = x;
    //     rep(l,0,n){
    //             mp[v[l]%gc]++;
    //         }
    //         f = 1;
    //         //bool f = 1;
    //         rep(l,0,n){
    //         if(mp[v[l] % gc] == 0)continue;
    //         if(mp[gc - (v[l]%gc)] == 0){
    //             f = 0;
    //             break;
    //         }
    //         else{
    //             mp[gc - (v[l] % gc)]--;
    //             mp[v[l] % gc]--;
    //         }
    //     }
    //     if(f == 1){
    //         ans = gc;
    //         break;
    //     }

    // }
    // if(ans == -1){
    //     for(ll i = least - 1;i >= 2;--i){
    //         map<ll,ll> mp;
    //         ll gc = i;
    //         //dbg(s-t,t,gc);
    //         rep(l,0,n){
    //             mp[v[l]%gc]++;
    //         }
    //         bool f = 1;
    //         rep(l,0,n){
    //         if(mp[v[l] % gc] == 0)continue;
    //         if(mp[gc - (v[l]%gc)] == 0){
    //             f = 0;
    //             break;
    //         }
    //         else{
    //             mp[gc - (v[l] % gc)]--;
    //             mp[v[l] % gc]--;
    //         }
    //     }
    //     if(f == 1){
    //         ans = gc;
    //         break;
    //     }
    //     }
    // }
    // if(ans == -1)ans = 1;
    // cout << ans;ln;
}
 
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);    
    int test=1;
    //cin>>test;   
    while(test--)
        solve();
    return 0;
}
