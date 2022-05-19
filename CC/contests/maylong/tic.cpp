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

int x , o;

bool win(vector<string> &s,char c){
    
    bool won = 0;

    won|=(s[0][0] == s[1][1] && s[0][0] == s[2][2] && s[0][0] == c);
    won|=(s[2][0] == s[1][1] && s[0][2] == s[1][1] && s[1][1] == c);
        
        // check row
    rep(i,0,3){            
        won|=(s[i][0] == s[i][1] && s[i][0] == s[i][2] && s[i][0] == c);
            
        won|=(s[0][i] == s[1][i] && s[0][i] == s[2][i]  && s[0][i] == c);
            
    }
    return won;

    
}


void solve(){
    
    vector<string> s(3);
    x = 0;o = 0;
    for(auto &i : s){
        cin >> i;
        for(auto ax : i){
            if(ax == 'X')++x;
            else if(ax == 'O')++o;
        }
    }
    // dbg(x,o);
    if(o > x || x - o > 1){
        cout << 3;
    }
    else{
        
        bool r1 = win(s,'X'),r2 = win(s,'O');
        if(r1){
            if(!r2 && (9 - x - o) % 2 == 0 && x > o){
                cout << 1;
            }
            else cout << 3;
        }
        else if(r2){
            if((9 - x - o) % 2 != 0 && x ==  o){
                cout << 1;
            }
            else cout << 3;
        }
        else if(9 - x - o == 0){
            cout << 1;  
        }     
        else cout << 2;

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