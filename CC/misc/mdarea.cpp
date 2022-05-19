// https://www.codechef.com/JUNE21B/problems/DAREA
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
#define all(x) x.begin(),x.end()

void solve(){
    int n;
    cin >> n;
    vector<pl> x(n),y(n);
    rep(i,0,n){
        cin >> x[i].fr >> x[i].sc;
        y[i].fr = x[i].sc;
        y[i].sc = x[i].fr;
    }
    sort(all(x));
    sort(all(y));
    vector<ll> prex(n),sufx(n),prey(n),sufy(n);
    // x prefix
    ll mx,my,mix,miy;
    prex[0] = 0;
    mx = mix = x[0].fr;
    my = miy = x[0].sc;
    rep(i,1,n){
        mx = max(x[i].fr,mx);
        mix = min(x[i].fr,mix);
        my = max(my,x[i].sc);
        miy = min(miy,x[i].sc);
        prex[i] = (mx - mix) * (my - miy);
    }   
    sufx[0] = 0;
    mx = mix = x.back().fr;
    my = miy = x.back().sc;
    for(int i = n-2;i >= 0;--i){
        mx = max(x[i].fr,mx);
        mix = min(x[i].fr,mix);
        my = max(my,x[i].sc);
        miy = min(miy,x[i].sc);
        sufx[i] = (mx - mix) * (my - miy);
    }
    prey[0] = 0;
    mx = mix = y[0].sc;
    my = miy = y[0].fr;
    rep(i,1,n){
        mx = max(mx,y[i].sc);
        mix = min(mix,y[i].sc);
        my = max(my,y[i].fr);
        miy = min(miy,y[i].fr);
        prey[i] = (mx - mix) * (my - miy);
    }
    sufy[n-1] = 0;
    mx = mix = y.back().sc;
    my = miy = y.back().fr;
    for(int i = n-2;i >= 0;--i){
        mx = max(mx,y[i].sc);
        mix = min(mix,y[i].sc);
        my = max(my,y[i].fr);
        miy = min(miy,y[i].fr);
        sufy[i] = (mx - mix) * (my - miy);
    }
    ll ans = prex.back();
    rep(i,0,n-1){
        ans = min(ans,prex[i] + sufx[i + 1]);
        ans = min(ans,prey[i] + sufy[i + 1]);
    }
    cout << ans;ln;
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