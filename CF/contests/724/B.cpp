#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ln cout<<"\n"
using namespace std;
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
#define dbg(...) {}
#endif

#define pi pair<int,int>
#define pl pair<ll,ll> 
#define fr first
#define sc second
#define pb push_back
#define gcd(a,b) __gcd(a,b)
#define all(x) x.begin(),x.end()

map<int,string> mp;
string s;
int n;
bool check(string t){
    int sz = t.size();
    rep(i,0,n){
        if(s[i] == t[0] && i + sz -1 < n){
            if(s.substr(i,sz) == t)return true;
        }
    }
    return false;
}
void solve(){   
   
    
    cin >> n;   
    cin >> s;
    vector<int> count(26);
    rep(i,0,n)count[s[i]-'a']++;
    vector<string> ss;
    rep(i,0,26){
        rep(j,0,26){
            ss.pb(mp[i] + mp[j]);
        }   
    }
    int t = ss.size() + 26;
    sort(ss.begin(),ss.end());
    // dbg(t);   
    int cnt = 0;
    vector<string> three;
    while(t <= 5000){
        string c = mp[cnt];
        for(auto x : ss){
            if(x.size() == 2){
                three.pb(x + c);
                t++;
                if(t == 5000)break; 
            }   
        }
        ++cnt;
    }
    //  for(auto x : three){
    //     cout << x << " ";
    // }
    // ln;
    // size of 1
    rep(i,0,26){
        if(count[i] == 0){
            cout << char('a'+ i);
            ln;
            return;
        }
    }
    // size of two
    for(auto x : ss){
        if(!check(x)){
            cout << x;ln;
            return;
        }
    }
   
    // size of three
    sort(three.begin(),three.end());
    for(auto x : three){
        if(!check(x)){
            cout << x;ln;
            return;
        }
    }
}   


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL); 
    //gen_factorial(1e6); 
    for(int i = 0;i < 26;++i){
        mp[i] = 'a' + i;
    }
    int test=1;
    cin>>test;   
    while(test--)
        solve();
    return 0;
}