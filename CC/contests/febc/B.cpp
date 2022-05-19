#include<bits/stdc++.h>
#define ll long long     
using namespace std;
int main(){
    int tt;
    cin >> tt;
    while (tt--)
    {
        int n;
        cin >> n;
        vector<ll> v(n);
        for(int i = 0;i<n;++i)cin >> v[i];
        sort(v.begin(),v.end());
        ll ans = 2*(v[n-1]-v[0]);
        cout << ans << endl;
    }
    
}