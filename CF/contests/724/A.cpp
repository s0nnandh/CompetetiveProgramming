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
    vector<int> v(n),cnt(101);
    set<int> s;
    bool neg = 0;
    rep(i,0,n){
        cin >> v[i];
        if(v[i] >= 0){
            cnt[v[i]]++;
        }
        s.insert(v[i]);
        neg |= (v[i] < 0);
    }
    if(neg || (int)s.size() != n){
        cout << "NO";
        ln;
        return;
    }
    while(1){
        set<int> req;
        rep(i,0,101){
            rep(j,i + 1,101){
                if(cnt[i] & cnt[j]){
                    if(cnt[abs(j-i)] == 0){
                        req.insert(abs(j-i));
                    }
                }
            }
        }
        if(req.size() == 0){
            cout << "YES";ln;
            int t = 0;
            rep(i,0,101){
                t += cnt[i];
            }
            cout << t << endl;
            rep(i,0,101){
                if(cnt[i])cout << i << " ";
            }
            ln;
            return;
        }
        else{
            for(auto x : req)cnt[x] = 1;
        }

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