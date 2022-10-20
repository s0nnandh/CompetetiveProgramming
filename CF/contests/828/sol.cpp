#include<bits/stdc++.h>
#define ll long long
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

std :: vector<std :: pair<long long,int>> pff(long long n){
    std :: vector<std :: pair<long long,int>> fac;
    long long cnt=0;
    while (n % 2 == 0)
    {
        cnt++;
        n = n/2;
    }
    if(cnt!=0)
    fac.push_back({2,cnt});


    for (long long i = 3; i * i <= n; i = i + 2)
    {
        cnt=0;
        if(n==1)break;
        while (n % i == 0)
        {
            cnt++;
            n = n/i;
        }
            if(cnt!=0)
    fac.push_back({i,cnt});
    }
    if (n > 2)
    fac.push_back({n,1});
    
    return fac;
}

ll process(int a, int b, int c) {
    map<int, int> mp;
    for(auto x : pff(a))mp[x.first] += x.second;
    for(auto x : pff(b))mp[x.first] += x.second;
    for(auto x : pff(c))mp[x.first] -= x.second;
    ll ans = 1;
    for(auto x : mp)for(int i = 0;i < max(0, x.second);++i)ans *= x.first;
    return ans;
}

void solve() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    bool a_in_ac = (c / a - 1) > 0;
    bool a_in_bd = (d / a - b / a) > 0;
    bool b_in_ac = (c / b - a / b) > 0;
    bool b_in_bd = (d / b - 1) > 0;
    bool ok = a_in_ac || a_in_bd;
    ok &= b_in_ac || b_in_bd;
    if(ok == 0) {
        cout << -1 << " " << -1 << '\n';
        return;
    }
    int x = -1, y = -1;
    if(a_in_ac)x = 2 * a;
    if(y == - 1 && a_in_bd)y = b + 1 + ((b + 1) % a == 0 ? 0 : a - (b + 1) % a);
    if(b_in_bd)y = 2 * b;
    dbg(x, y, a, b);
    if(x == -1 && b_in_ac)x = a + 1 + (((a + 1) % b == 0) ? 0 : b - (a + 1) % b);
    // dbg(x, y, a * b, c, d);
    if(y == -1) {
        bool s = 0;
        if(x == -1) {
            s = 1;
            swap(x, y);
            swap(a, b);
            swap(c, d);
        }
        ll p = process(a, b, c);
        if(p == 0 || (d / p - b / p) > 0) {
            x = c;
            y = p == 0 ? b + 1 : b + 1 + ((b + 1) % p == 0 ? 0 : p - (b + 1) % p);
        }
        else x = -1;
        if(s)swap(x, y);
    }
    cout << x << " " << y << '\n';
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
