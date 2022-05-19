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
#define dbg(...) cerr << "" << endl
#endif

#define pi pair<int,int>


void solve(){
    int n,l,r;
    cin >> n >> l >> r;
    /// rmeove matching pairs first
    vector<int> L(n),R(n);
    rep(i,0,n){
        int a;
        cin >> a;
        --a;
        if(i < l)L[a]++;
        else R[a]++;
    }
    rep(i,0,n){
        int k = min(L[i],R[i]);
        L[i]-=k;
        R[i]-=k;
        l-=k;
        r-=k;
    }
    // removing matching pairs and simalraneously decreasing l,r whch represent no of unmatched socks in both left and right array. 
    if(r > l){
        swap(l,r);
        swap(L,R);
    }
    int rem = (l - r)/2,ans = 0;
    rep(i,0,n){
        int cando = L[i]/2;
        int du = min(rem,cando); // Here u are essentially makings sock right and there are of same colour.
        l-= 2*du;
        rem -= du;
        ans += du;
    }   
    // main idea : you have to make (l-r)/2 right anyway so do those which are already paired .
    // rem -> represents the left socks to make them right

    cout << ans + (l + r)/2 + rem;ln; // here rem is the cost of making left to right and (l + r)/2 here is the no of socks that need to be paired i.e,
    // change their colour. 

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