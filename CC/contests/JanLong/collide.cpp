#include<bits/stdc++.h>
#include<unordered_map>
#define ll long long
#define ull unsigned long long
#define ln cout<<"\n"
#define dbg(x) cout<<#x<<" = "<<x<<" "
#define rep(i,s,n) for(ll i = (s);i<(n);++i)
#define DEBUG(x) do { std::cerr << #x << ": " << x << std::endl; } while (0)
using namespace std;
void solve(){
    int n, k , x, y;
    cin >> n >> k >> x >> y;
    --k;
    //bool corner = false;
    if(x == y){
       cout << n << " " << n;
       ln;
       return;
    }
    vector<pair<int,int>> collisions;
    int d = n - max(x,y);
    x+=d;y+=d;
    collisions.push_back({x,y});
    d = min(x,y);
    collisions.push_back({x-d,y-d});
    if(x > y){        
        x-=n-y;y=n;
        collisions.push_back({x,y});
        collisions.push_back({0,y-x});
    }
    else {
        y-=n-x;x=n;
        collisions.push_back({x,y});
        collisions.push_back({x-y,0});
    }
    auto it = collisions.begin();
    ++it;
    pair<int,int> p = collisions[1];
    collisions.erase(it);
    collisions.push_back(p);
    cout << collisions[k%4].first << " " << collisions[k%4].second ;
    ln;
    // rep(i,0,(int)collisions.size()){
    //     cout << collisions[i].first << " " << collisions[i].second ;
    //     ln;
    // }
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

// FIND POINTS OF COLLISION AT MOST 4 ONLY.