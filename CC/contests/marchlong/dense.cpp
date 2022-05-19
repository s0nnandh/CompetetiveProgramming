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
#define pb push_back

struct cmp{
    bool operator()(const pi& a,const int& b){
        return a.first < b;
    }
};

struct comp{
    bool operator()(const pi& a,const pi& b){
        return a.first < b.first;
    }
};

struct compp{
    bool operator()(const int& a,const int& b){
        return  b < a;
    }
};


void solve(){    
    int n,m,x,y;    
    cin >> n >> m >> x >> y;
    vector<pi> ab(m),cd(m),rcd(m);
    map<pi,set<pi>> mp;
    rep(i,0,m){
        int a,b,c,d;
        cin >> a >> b >> c >> d;
        mp[{a,b}].insert({c,d});
    }
    priority_queue<pair<int,pi>,vector<pair<int,pi>>,greater<pair<int,pi>>> pq;
    rep(i,0,m){
        if(x>=ab[i].first && x <= ab[i].second)pq.push({0,ab[i]});
    }
    while(!pq.empty()){
        pair<int,pi> node = pq.top();
        pq.pop();
        int key = node.first;
        pi p = node.second;
        if(y >= p.first && y <= p.second && key != 0){
            cout << key ;ln;
            return;
        }
        for(auto c : mp[p]){
            pq.push({key+1,c});
        }
    }
    cout << -1;ln;
    // sort(cd.begin(),cd.end());sort(rcd.begin(),rcd.end());
    // //vector<vector<pair<int,int>>> mp;
    // //int for_left = lower_bound(rcd.begin(),rcd.end(),1,cmp()) - rcd.begin();
    // //map<int,set<pi,comp>> mp;
    // map<pi,set<pi>> mp;
    // rep(i,0,m){
    //     int L = ab[i].first,R = ab[i].second;
    //     int for_left = lower_bound(rcd.begin(),rcd.end(),make_pair(L,0),comp()) - rcd.begin();
    //     rep(j,for_left,m){
    //         if(rcd[i].second > R)break;
    //         mp[ab[i]].insert({rcd[i].second,rcd[i].first});
    //     }
    //     int for_r8 = upper_bound(cd.begin(),cd.end(),make_pair(R,0),comp()) - cd.begin();
    //     rep(j,0,for_r8){
    //         if(cd[i].second < L)break;
    //         mp[ab[i]].insert(cd[i]);
    //     }
    // }
    // priority_queue<pair<int,pi>,vector<pair<int,pi>>,greater<pair<int,pi>>> pq;
    // rep(i,0,m){
    //     if(x>=ab[i].first && x <= ab[i].second)pq.push({0,ab[i]});
    // }
    // while(!pq.empty()){
    //     pair<int,pi> node = pq.top();
    //     pq.pop();
    //     int key = node.first;
    //     pi p = node.second;
    //     if(y >= p.first && y <= p.second && key != 0){
    //         cout << key ;ln;
    //         return;
    //     }
    //     for(auto c : mp[p]){
    //         pq.push({key+1,c});
    //     }
    // }
    // cout << -1;ln;
    

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

