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
    int n,x;
    cin >> n >> x;
    vector<int> v(n);
    for(auto& i : v){
        cin >> i;
    }
    ll sum = 0,l = 0,r = n-1;
    priority_queue<int,vector<int>,greater<int>> min_heap;
    while(l<=r){
        //if(sum >= x)break;
        min_heap.push(max(v[l],v[r])) ;
        if(l!=r && min_heap.top() < min(v[l],v[r])){
            min_heap.pop();
            min_heap.push(min(v[l],v[r]));
        }
        ++l;
        --r;
    }
    while(!min_heap.empty()){
        sum+=min_heap.top();
        min_heap.pop();
    }
    if(sum >= x){
        cout << "YES";
    }
    else cout << "NO";
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

// WE HAVE TO CHECK THAT THE MIN VALUE OF V[L] AND V[R] IS GREATER THAN THAT OF 
// THE MINIMUM VALUE THAT WE HAVE ADDED TEMPOARRILY  IN THIS CASE A MIN_HEAP.