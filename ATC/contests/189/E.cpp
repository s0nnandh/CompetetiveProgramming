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

struct P
{
    int x,y;
};
vector<ll> mul(ll a[3][3],vector<ll> p){
    vector<ll> r(3);
    rep(i,0,3){
        ll t = 0;
        rep(j,0,3){
            t += a[i][j] * p[j];
        }
        r[i] = t;
    }
    return r;
}
struct  Matrix
{
	ll a[3][3];
	Matrix(){
		rep(i,0,3){
            rep(j,0,3)a[i][j] = 0;
        }
	}
    Matrix(int x){
        rep(i,0,3){
            rep(j,0,3){
                a[i][j] = 0;
                //if(i == j)a[i][j] = 1;
            }
        }
        if(x == 1){
            a[1][0] = -1;
            a[0][1] = 1;
        }
        else {
            a[1][0] = 1;
            a[0][1] = -1;
        }
        a[2][2] = 1;
    }
    Matrix(int x,int p){
        rep(i,0,3){
            rep(j,0,3){
                a[i][j] = 0;
                if(i == j)a[i][j] = 1;
            }
        }
        if(x == 1){
            a[1][1] = -1;
            a[1][2] = 2*p;
        }\
        else {
            a[0][0] = -1;
            a[0][2] = 2*p;
        }
    }
	Matrix operator *(Matrix &other){
		Matrix product;
		rep(i,0,3){
			rep(j,0, 3){
				rep(k,0,3){
					product.a[i][k] += a[i][j] * other.a[j][k];
				}
			}
		}
		return product;
	}
    void show(){
        cout << "-------------";ln;
        rep(i,0,3){
            rep(j,0,3){
                cout << a[i][j] << " ";
            }
            ln;
        }
        cout << "--------------";ln;
    }	
};
void solve(){
    int n;
    cin >> n;
    vector<P> points(n);
    for(P& p : points)cin >> p.x >> p.y;
    int m;
    cin >> m;
    vector<Matrix> M(m+1);
    Matrix mat;
    rep(i,0,3)mat.a[i][i] = 1;
    M[0] = mat;
    rep(i,1,m+1){
        int a,b = -1e9+2;
        cin >> a;
        if(a > 2){
            cin >> b;
        }
        if(b == -1e9+2){
            if(a == 1){
                Matrix ma(1);
                M[i] = ma * M[i-1];
            }
            else{
                Matrix ma(-1);
                M[i] = ma * M[i-1];
            }
        }
        else{
            if(a == 3){
                Matrix ma(-1,b);
                //ma.show();
                //dbg(m);
                M[i] = ma * M[i-1];
            }
            else{
                Matrix ma(1,b);
                //ma.show();
                M[i] = ma * M[i-1];
            }
        }
    }
    int q;
    cin >> q;
    rep(i,0,q){
        int a,b;
        cin >> a >> b;
        P p = points[b-1];
        vector<ll> v{p.x,p.y,1};
        vector<ll> ans = mul(M[a].a,v);
        cout << ans[0] << " " << ans[1];ln;
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);    
    int test=1;
    //cin>>test;   
    while(test--)
        solve();
    return 0;
}

