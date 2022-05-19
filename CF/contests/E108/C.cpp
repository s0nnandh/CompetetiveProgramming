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

#define pi pair<int,int>


void solve(){
    map<int,int> cc;
    int n;
    cin >> n;
    vector<int> u(n);
    set<int> t;
    rep(i,0,n){
        cin >> u[i];
        t.insert(u[i]);
        //mp[u[i]] = 1;
    }
    
    int r = 0;   
    for(auto x : t){
        cc[x] = r;
        ++r;
    } 
    int k = cc.size();
    ll sum = 0;
    vector<vector<ll>> c(k);
    
    rep(i,0,n){
        ll s;
        cin >> s;
        // cout << k <<  " " << u[i] << endl;
        if(c[cc[u[i]]].size() == 0)c[cc[u[i]]].push_back(0);
        c[cc[u[i]]].push_back(s);
        sum+=s;
    }   
    rep(i,0,k){
        sort(c[i].begin(),c[i].end());
    }
    rep(i,0,k){
        rep(j,1,(int)c[i].size() + 1){
            dbg(c[i][j-1]);
            c[i][j]+=c[i][j-1];
        }
    }
    cout << sum << " ";
    int l = 2;
    rep(i,2,n+1){
        ll s = sum;
        rep(j,0,k){
            if(i+1 > (int)c[j].size()){
                s-=c[j][c[j].size()-1];
            }
            else{
                int kk = (c[j].size()-1) % i;
                s-=c[j][kk];
            }
        }
        cout << s << " ";
        ++l;
        if(s == 0)break;
    }
    rep(i,l,n+1)cout << 0 << " ";
    cout << endl;
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

