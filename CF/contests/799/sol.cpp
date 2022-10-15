#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>

int INF = -1e9;

int main() { 
    int n;
    std :: cin >> n;
    std :: vector<int> v(n);
    for(int &i : v)std :: cin >> i;
    int ans = 0;
    auto maximize = [&](int x, int y) {
        int val = x ^ y;
        ans = std :: max(ans, val);
    };
    for(int j = 0;j < 2;++j) {
        std :: stack<int> s;
        s.push(INF);
        for(int i = 0;i < n;++i) {
            while(s.top() > v[i]) {
                maximize(s.top(), v[i]);
                s.pop();
            }
            s.push(v[i]);
        }
        std :: reverse(v.begin(), v.end());
    }
    std :: cout << ans << '\n';
}