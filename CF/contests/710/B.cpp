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


void solve(){
   
  
  int n,k;
  cin >> n >> k;
  string s;
  cin >> s;
  //int  f = -1 ,l = -1;
  vector<int> v;
    rep(i,0,n){
        if(s[i] == '*'){
            v.push_back(i);
        }
    }
    // int sz = v.size();
    // f = v[0];l = v[sz-1];
    // if(n == 1 || l-f == 0){
    //     cout << 1;ln;

    // }
    // else if(l-f < k){
    //     cout << 2;ln;
    // }
    // else{
    //     int ans = 2;
    //     //if(v.size() == 1)ans = 1;
    //     int ptr = 1,pre = 0;
    //     while(ptr < sz-1){
    //         while(v[ptr] - v[pre] < k){
    //             if(ptr >= sz-1)break;
    //             ++ptr;
    //         }
    //         if(ptr >= sz-1)break;
    //         pre = ptr;
    //         ++ans;
    //     }
    //     cout << ans;ln;

    
    int sz = v.size();
    stack<int> st;
    rep(i,0,min(2,sz)){
        st.push(v[i]);
    }
    rep(i,2,sz){
        int last = st.top();
        st.pop();
        int beflast = st.top();
        if(v[i]-beflast >= k){
            //st.push(beflast);
            st.push(last);
            st.push(v[i]);
        }
        else{
            //st.push(beflast);
            
            st.push(v[i]);
        }
        dbg(beflast,last,v[i],k);
        stack<int> sss;
        sss = st;
        
        
            while(!st.empty()){
        
            dbg(st.top());
            st.pop();
        }
        st = sss;
    }
    
    cout << st.size();ln;


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

