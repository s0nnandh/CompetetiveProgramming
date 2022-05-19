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

int cnv(string a,string b){
	int num = (a[0]-'0')*1000 + (a[1]-'0')*100 + (a[3]-'0')*10 + (a[4]-'0');
	if(b[0] == 'A' && num >= 1200)num-=1200;
	if(b[0] == 'P' && num < 1200)num+=1200;
	return num;
}
void solve(){
	string a,b,ans = "";
	cin >> a >> b;
	int num = cnv(a,b);
	int n;
	cin >> n;
	rep(i,0,n){
		string p,q,r,s;
		cin >> p >> q >> r >> s;
		int x = cnv(p,q),y = cnv(r,s);
		ans += (num >= x && num <= y)?'1':'0';
	}
	cout << ans;ln;
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

