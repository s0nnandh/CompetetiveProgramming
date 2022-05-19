#include<bits/stdc++.h>
using namespace std;
int main(){
    int a,b;
    cin >> a >> b;
    int x = 0;
    int ans = 0;
    while(x<=b){
        int t = x;
        while(t > 0){
            int d = t%10;
            if(d == a)++ans;
            t/=10;
        }
        ++x;
    }
    cout << ans << endl;
}