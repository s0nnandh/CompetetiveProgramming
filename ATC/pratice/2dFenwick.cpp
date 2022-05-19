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

struct Fenwick2
{
    int r,c;
    vector<vector<ll>> bit;
    Fenwick2(int row,int col){
        r = row;
        c = col;
        bit.resize(row + 1);
        for(auto &x : bit)x.resize(col + 1,0);
    }
    void add(ll x,int row,int col){
        int cc = col;
        while(row <= r){
            col = cc;
            while(col <= c){
                bit[row][col] += x;
                col += col & (-col);
            }
            row += row & (-row);
        }
    }
    ll get(int row,int col){
        ll sum = 0;
        int cc = col;
        while(row > 0){
            col = cc;
            while(col > 0){
                sum += bit[row][col];
                col -= col & (-col);
            }
            row -= row & (-row);
        }
        return sum;
    }
    ll query(int x1,int y1,int x2,int y2){
        return get(x2,y2) + get(x1-1,y1-1) - get(x2,y1-1) - get(x1-1,y2);
    }
};


void solve(){   
    

    int n;
    cin >> n;
    Fenwick2 f(n,n);
    vector<vector<int>> v(n + 1,vector<int> (n + 1));
    string s;
    while(1){
        cin >> s;
        // cout << s;ln;
        if(s == "END")break;
        if(s == "SET"){
            ll x,y,num;
            cin >> x >> y >> num;
            swap(x,y);
            ++x;++y;
            f.add(num - v[x][y],x,y);
            v[x][y] = num;
        }
        else{
            int x1,y1,x2,y2;
            cin >> x1 >> y1 >> x2 >> y2;
            swap(x1,y1);swap(x2,y2);
            ++x1;++y1;++x2;++y2;
            cout << f.query(x1,y1,x2,y2);ln;
        }
    }
	
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