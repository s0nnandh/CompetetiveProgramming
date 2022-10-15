#include<bits/stdc++.h>
// #define ll long long
#define ln cout<<"\n"
#define rep(i,s,n) for(ll i = (s);i<(n);++i)
#define pc(x) __builtin_popcount(x)
#define pi std::pair<int,int>
#define pl std::pair<ll,ll> 
#define fr first
#define sc second
#define pb push_back
#define gcd(a,b) std :: __gcd(a,b)
#define len(x) (int)x.size()
#define all(x) x.begin(),x.end()
#define vi std::vector<int>
#define vl std::vector<ll>
void __dbg(int x) {std::cerr << x;}
void __dbg(long long x) {std::cerr << x;}
void __dbg(float x) {std::cerr << x;}
void __dbg(double x) {std::cerr << x;}
void __dbg(long double x) {std::cerr << x;}
void __dbg(char x) {std::cerr << '\'' << x << '\'';}
void __dbg(const char *x) {std::cerr << '\"' << x << '\"';}
void __dbg(const std::string &x) {std::cerr << '\"' << x << '\"';}
void __dbg(bool x) {std::cerr << (x ? "true" : "false");} 
template<class T,class V>void __dbg(const std::pair<T, V> &x) {std::cerr << "{ "; __dbg(x.first); std::cerr << ','; __dbg(x.second); std::cerr << "}";}
template<class T>void __dbg(const T &x) {int f = 0; std::cerr << "{ "; for (auto &i: x) std::cerr << (f++ ? "," : ""), __dbg(i); std::cerr << "}";}
void _dbg() {std::cerr << " ]" << std::endl;}
template <class T, class... V>void _dbg(T t, V... v) {__dbg(t); if (sizeof...(v)) std::cerr << ", "; _dbg(v...);} 
#ifdef _DEBUG
#define dbg(x...) std::cerr << "[" << #x << "] = [ "; _dbg(x)
#else
#define dbg(x...)
#endif

using namespace std;

void solve(){
    string s;
    std :: cin >> s;
    vector<int> cnt(10);
    auto give_pos = [&]() {
        for(int i = 0;i < 10;++i)if(cnt[i])return i;
        return 10;  
    };
    for(char x : s)cnt[x - '0']++;
    int n = s.size();
    vector<bool> ok(n);
    vector<char> bad, ans;
    int mx_pos = 0, me = give_pos();
    char k = '9';
    for(int i = 0;i < n;++i) {
        if(s[i] - '0' == me){
            ans.push_back(s[i]);
            --cnt[me];
            mx_pos = i;
            ok[i] = 1;
        }
        else {
            --cnt[s[i] - '0'];
            k = min((char)(s[i] + 1), k);
        }
        me = give_pos();
        if(k - '0' < me)break;
    }
    for(int i = 0;i <= mx_pos;++i)if(!ok[i])bad.push_back(min((char)(s[i] + 1), '9'));
    for(int i = mx_pos + 1;i < n;++i) {
        if(s[i] - '0' == me){
            bad.push_back(s[i]);
            --cnt[me];
        }
        else {
            --cnt[s[i] - '0'];
            bad.push_back(min((char)(s[i] + 1), '9'));
        }
        me = give_pos();
    }
    sort(all(bad));
    for(char x : ans)std :: cout << x;
    for(auto x : bad)std :: cout << x;
    cout << '\n';
}   

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);  	
    int test=1;
    std :: cin>>test;   
    while(test--)
        solve();
    return 0;
}
