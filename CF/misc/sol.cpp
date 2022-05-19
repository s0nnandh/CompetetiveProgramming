#include<bits/stdc++.h>
using namespace std;
int ok(int n){
    int cnt = 0;
    while(n){
        int d = n % 10;
        if(d != 2 || d != 5)return 0;
        ++cnt;
        n /= 10;
    }
    return cnt;
}
vector<int> dp(1e6 + 1,-1);
int go(int n){
    if(n == 0)return -1;
    int ans = ok(n);
    if(ans)return ans;
    if(dp[n] != -1)return dp[n];
    return dp[n] = min(dp(n - (5 * (n / 5))))
}
int main(){
    
}