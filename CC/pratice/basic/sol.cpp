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
    ll k,d0,d1;
    cin >> k >> d0 >> d1;
    vector<int> store;
    if(k == 2){
        if((d1+d0) %3 == 0 )cout << "YES";
        else cout << "NO";
        ln;
    }
    int sum  = (d1 + d0)%10;
    store.push_back(d0);
    store.push_back(d1);
    store.push_back((d1 + d0)%10);
    k-=3;
    while(k > 0){
        sum = (sum + store[store.size()-1])%10;
        if(sum == 4 || sum == 0)break;
        store.push_back(sum);
        --k;
    } 
    //cout << k;
    //ln;
    if(sum == 4){
        ll t = (2*(k/4))%3;
        //dbg(t);ln;
        int arr[4] = {4,8,6,2};
        k  = k%4;int j = 0;
        while(k--){
            store.push_back(arr[j]);
            ++j;
        }
        //dbg(t);ln;
        rep(i,0,(int)store.size()){
            //cout << store[i] << " ";
            t = (t + store[i])%3;
        }
        //dbg(t);
        //ln;
        if(t%3 == 0)cout<<"YES";
        else cout << "NO";
        ln;
    }
    else{
        int t = 0;
        int sz = store.size();
        rep(i,0,sz){
            //cout << store[i] << " ";
            t = (t + store[i])%3;
        }
        if(t%3 == 0)cout<<"YES";
        else cout << "NO";
        ln;
    }
    
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
