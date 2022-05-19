// https://www.codechef.com/MARCH21B/problems/PAPARAZI

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

    int n,k;
    cin >> n >> k;
    string s;
    cin >> s;
    ll sum = 0;
    if(n == 1){
        rep(i,0,k){
            int q;
            cin >> q;
            cout << sum;ln;
        }
        return;
    }
    rep(i,1,n){
        if(s[i] == s[i-1])sum += 2;
        else sum++;
    }

    auto change = [&](int j){
        if(s[j] == '1'){
            s[j] = '0';
        }
        else s[j] = '1';
    };
    // cout << sum ;ln;
    rep(i,0,k){
        int q;
        cin >> q;
        --q;
        if(q == 0){
            if(s[q+1] == s[q]){
                --sum;
            }
            else ++sum;
            
        }
        else if(q == n-1){
            if(s[q-1] == s[q]){
                --sum;
            }
            else ++sum;
        }
        else{
            if(s[q] == s[q+1]){
                --sum;
            }
            else ++sum;
            if(s[q] == s[q-1]){
                --sum;
            }
            else ++sum;
        }
        change(q);
        cout << sum;ln;
    }

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