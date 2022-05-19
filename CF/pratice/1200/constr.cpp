// https://codeforces.com/contest/1512/problem/C

#include<bits/stdc++.h>
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
#define pl pair<ll,ll> 
#define fr first
#define sc second
#define pb push_back
#define gcd(a,b) __gcd(a,b)

void solve(){

    int a,b;
    cin >> a >> b;
    string s;
    cin >> s ;
    int n = s.size();
    // priotize single question marks pairs
    rep(i,0,n/2){
        if(s[i] =='?' && s[n-i-1]=='?')continue;
        if(s[i] == '?'){
            if(s[n-i-1] == '1'){
                s[i] = '1';
                b -= 2;
            }
            else{
                s[i] = '0';
                a -= 2;
            }
        }
        else if(s[n-i-1] == '?'){
            if(s[i] == '1'){
                s[n-i-1] = '1';
                b -= 2;
            }
            else{
                s[n-i-1] = '0';
                a -= 2;
            }
        }
        else if(s[i] != s[n-i-1]){
            cout << -1;ln;
            return;
        }
        else{
            if(s[i] == '1'){
                b -= 2;
            }
            else{
                a -= 2;
            }
        }
    }
    if(n&1){
        if(s[n/2] == '1'){
            --b;
        }
        else if(s[n/2] == '0')--a;
    }
    // cout << s << " " << a << " " << b;ln;
    if(a < 0 || b < 0){
        cout << -1;ln;return;
    }
    // now deal for pairs of question marks
    rep(i,0,n/2){
        if(s[i] == '?' && s[n-i-1] =='?'){
            if(a > b){
                a -= 2;
                s[i] = s[n-i-1] = '0';
            }
            else{
                b -= 2;
                s[i] = s[n-i-1] = '1';
            }
        }
    }
    if(n&1){
        if(s[n/2] == '?'){
            if(a > b){
                --a;
                s[n/2] = '0';
            }
            else {
                --b;
                s[n/2] = '1';
            }
        }
    }
    if(a != 0 || b != 0){
        cout << -1;ln;
        return;
    }
    cout << s;ln;
    	
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

// real nice implementation prblm . HAve to priotize single pairs . If we can 
// priortize somrthing we must do it . here priotize single pairs.