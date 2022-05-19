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

bool cmp(pair<int,int> p1,pair<int,int> p2){
    bool x =  (p1.first < p2.first && p1.second < p2.second) || (p1.first < p2.second && p1.second < p2.first);
    if(!x){
        if(p1.first == p2.first)return p1.second < p2.second;
        return p1.first < p2.first;
    }
    return 1;
}
void solve(){
    int n;
    cin >> n;
    vector<pair<int,int>> p,t;
    map<pair<int,int>,int> mp;
    rep(i,0,n){
        int a,b;
        cin >> a >> b;
        p.push_back({a,b});
        t.push_back({a,b});
        mp[{a,b}] = i+1;
    }
    sort(p.begin(),p.end(),cmp);
    // for(auto x : p){
    //     cout << x.first << " " << x.second ;ln;
    // }
    rep(i,0,n){
        int l = 0,r = n-1,mid,idx = -1,h = t[i].first,w = t[i].second;
        int me;
        while (l<=r)
        {
            mid = l+(r-l)/2;
            if(h == p[i].first && w == p[i].second){
                me = mid;
                break;
            }
            else if(h > p[i].first || w >)
        }
        
        while(l <= r){            
            mid = l + (r-l)/2;
            //if(i == n-1)dbg(h,w,p[mid].first,p[mid].second);
            if((p[mid].first < h && p[mid].second < w) || (p[mid].first < w && p[mid].second < h)){
                idx = mid;
                break;
                l = mid + 1;
            }
            else r = mid - 1;
        }
        if(idx == -1)cout << -1 << " ";
        else cout << mp[p[idx]] << " ";
    }
    ln;
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

