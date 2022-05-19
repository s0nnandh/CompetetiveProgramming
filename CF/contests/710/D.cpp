#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ln cout<<"\n"
using namespace std;
#define rep(i,s,n) for(ll i = (s);i<(n);++i)
#define pc(x) __builtin_popcount(x)
void DBG() {
	cerr << "" << endl;
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

    int n;
    cin >> n ;
    map<int,int> mp;
    rep(i,0,n){
        int a;
        cin >> a;
        mp[a]++;
    }    
    priority_queue<pl> q;
    for(auto x : mp){
        q.push({x.sc,x.fr});
    }
    while(!q.empty()){
        if(q.size() == 1)break;
        pl p1 = q.top();
        q.pop();
        pl p2 = q.top();
        q.pop();
        p1.fr--;
        p2.fr--;
        if(p1.fr>0)q.push(p1);
        if(p2.fr>0)q.push(p2);
    }
    cout << (q.empty()?0:q.top().fr);ln;
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