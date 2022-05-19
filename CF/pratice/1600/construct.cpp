#include<bits/stdc++.h>
#include<stdio.h>
#define ll long long
#define ull unsigned long long
#define ln cout<<"\n"
using namespace std;
//#define dbg(x) cout<<#x<<" = "<<x<<" "
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
#define dbg(...) cerr << "" << endl
#endif

#define pi pair<int,int>
#define pl pair<ll,ll> 
#define fr first
#define sc second
#define pb push_back

struct Seg{
    int l,r,len;
    Seg(int left,int ri){
        l = left;
        r = ri;
        len = r - l + 1;
    }
    
    // bool operator<(const Seg& s){
    //     if(len < s.len)return 1;
    //     if(l > s.l)return 1;
    //     return 0;
    // }

};

struct comp{
    bool operator()(Seg &s1,Seg &s2){
        if(s1.len < s2.len)return 1;
        if(s1.len == s2.len){
            return s1.l > s2.l;
        }
        return 0;
    }
};

void solve(){
    
    int n;
    cin >> n;
    priority_queue<Seg,vector<Seg>,comp> q;
    q.push(Seg(1,n));
    vector<int> ans(n+1);
    int cnt = 1;
    while(!q.empty()){
        if(cnt == n+1)break;
        Seg s = q.top();
        q.pop();
        int l = s.l,r = s.r,len = s.len;
        if(len == 0)continue;
        // dbg(l,r,len);
        int x = (len&1?(l+r)/2:(l+r-1)/2);
        ans[x] = cnt;
        ++cnt;
        q.push(Seg(l,x-1));q.push(Seg(x+1,r));        
    }
    rep(i,1,n+1){
        cout << ans[i] << " ";
    }
    ln;

    
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL); 
    //gen_factorial(1e6);   
    int test=1;
    cin>>test;   
    while(test--)
        solve();
    return 0;
}