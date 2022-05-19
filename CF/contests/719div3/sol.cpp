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
#define dbg(...) cerr << "" << endl
#endif

#define pi pair<int,int>
#define pl pair<ll,ll> 
#define fr first
#define sc second
#define pb push_back

void solve(){

    int n,t,k;
    cin >> n >> t;
    cin >> k;
    ll l = 1,r = n;
    ll mid;
    int q = 20;bool type = 0;
    ll val0,val1;
    while(q--){
        mid = (l + r)/2;        
        if(!type){
            cout << '?' <<" " << l << ' ' << mid << endl;
            cin >> val0;  
            val0 = mid - l + 1 - val0;        
        }
        else{           
            cout << '?' <<" " << mid + 1 << ' ' << r << endl;
            cin >> val1;
            val1 = r - mid - val1;
        }        
        if(type){
            // dbg(val0,val1);
            if(k > val0){
                k -= val0;
                l = mid + 1;
            }
            else{
                r = mid;
            }            
        }
        else{
            if(k <= val0){
                r = mid;
                type = 1;
            }
        }
        type = !type;
        if(l == r){
            cout << '!' << ' ' << l << endl;
            break;
        }        
    }   



}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL); 
    //gen_factorial(1e6);   
    int test=1;
    // cin>>test;   
    while(test--)
        solve();
    return 0;
}