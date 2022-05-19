#include<bits/stdc++.h>
#define ll long long
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
#define gcd(a,b) __gcd(a,b)
#define sz(x) (int)x.size()
#define all(x) x.begin(),x.end()



void solve(){


    int n,m;
    cin >> n >> m;
    vector<int> v(n);
    for(auto &i : v){
        cin >> i;
        --i;
    }
    vector<int> p(m);
    for(auto &i : p)cin >> i;
    priority_queue<int> q;
    rep(i,0,n)q.push(p[v[i]]);
    rep(i,0,m){
        if(q.top() > p[i]){
            q.pop();
            q.push(p[i]);
        }
        else break;
    }
    ll sum = 0;
    while(!q.empty()){
        sum += q.top();
        q.pop();
    }
    cout << sum;ln;

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
