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

#define pi pair<ll,ll>
#define pb push_back

void solve(){    
    
    int n;
    cin >> n;
    vector<int> v(n),lj(n,-1),rj(n,-1),l(n),rr(n);
    rep(i,0,n){
        cin >> v[i];
    }
    stack<int> s;
    rep(i,0,n){
        while(!s.empty()){
            if(v[s.top()] >= v[i])break;
            s.pop();
        }
        if(s.empty())lj[i] = -1;
        else lj[i] = s.top();
        s.push(i);
    }
    stack<int> r;
    for(int i = n-1;i >= 0;--i){
        while(!r.empty()){
            if(v[r.top()] >= v[i])break;
            r.pop();
        }
        if(r.empty())rj[i] = -1;
        else rj[i] = r.top();
        r.push(i);
    }

    rep(i,0,n){
        if(lj[i] == -1 || v[i] != v[lj[i]])continue;
        l[i] = l[lj[i]] + 1;
    }

    for(int i = n-1 ; i >= 0;--i){
        if(rj[i] == -1 || v[i] != v[rj[i]])continue;
        rr[i] = rr[rj[i]] + 1;
    }


    rep(i,0,n){
        cout << l[i] + rr[i] << " ";
    }
    ln;

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);       
    int test=1;
    cin>>test;    
    while(test--)
        solve();
    return 0;
}

// MONOTONIC STACK