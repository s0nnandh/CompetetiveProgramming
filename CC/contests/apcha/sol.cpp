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
#define dbg(...) cerr << "[ ]" << endl
#endif

#define pl pair<ll,ll>
#define pb push_back
int main(){
    int tt = 1;
    cin >> tt;
    while(tt--){        

        string s;
        cin >> s;
        int n = s.size();
        bool z = 0,o = 0;
        rep(i,0,n){
            if(s[i] == '1')o = 1;
            else z = 1;
        }
        if(!o){
            cout << 1;ln;
            continue;
        }
        else if(!z){
            cout << 0;ln;
            continue;
        }
        vector<int> dp(n),nex0(n,-1),nex1(n,-1);
        bool s1= 0 ,s0 = 0;int cnt = 0;
        for(int i = n-1; i>= 0; --i){
            dp[i] = cnt;
            if(s[i] == '0')s0 = 1;
            else s1 = 1;
            if(s0 & s1){
                ++cnt;
                s1 = s0 = 0;
            }
        }   
        
        int p0 = -1,p1 = -1;
        for(int i = n-1 ; i >= 0;--i){
            nex0[i] = p0;nex1[i] = p1;
            if(s[i] == '0')p0 = i;
            else p1 = i;
        }
        // rep(i,0,n){
        //     dbg(dp[i],nex0[i],nex1[i]);
        // } 
        int i = p1,n0,n1;
        string ans = "";
        while(i < n){
            ans+=s[i];
            n0 = nex0[i];n1 = nex1[i];
            if(n0 == -1){
                ans+='0';
                break;
            }
            else if(n1 == -1){
                ans+='1';
                break;
            }
            else{
                if(dp[n0] > dp[n1]){
                    // ans+='1';
                    i = nex1[i];
                }
                else{
                    // ans+='0';
                    i = nex0[i];
                }
            }
        }
        cout << ans;ln;
    }
}
