#include<bits/stdc++.h>
#define ll long long
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
#define dbg(...) cerr << "" << endl
#endif

#define pi pair<int,int>
#define pl pair<ll,ll> 
#define fr first
#define sc second
#define pb push_back
#define gcd(a,b) __gcd(a,b)
#define sz(x) (int)x.size()
#define all(x) x.begin(),x.end()
#define vi vector<int>
#define vl vector<ll>

int n,m,k;

void prefix(vector<vector<int>> &pre){
    rep(i,1,n + 1){
        rep(j,1,m + 1){
            // pre[i][j] = (a[i][j] > mid ? 1 : 0);
            pre[i][j] += pre[i-1][j] + pre[i][j-1] - pre[i-1][j-1];
        }
     }
}

int check(vector<vector<int>> &pre,int I,int J,int M){
    int ans = 0;

    rep(i,I,I + k){
        rep(j,J,J + k){
            ans = max(ans,pre[i][j]);
            if(ans > M){
                return M;
            }
        }
    }

    return ans;

}

string f(vector<vector<int>> &pre,vector<vector<int>> &v){
    int M = 1e9;
    string ans = "Draw";    
    rep(i,1,n + 1){
        rep(j,1,m + 1){
            if(i + k - 1 <= n && j + k - 1 <= m){
                if(pre[i + k - 1][j + k - 1] - pre[i+k - 1][j - 1] - pre[i - 1][j + k - 1] + pre[i-1][j-1] == k*k){
                    int ask = check(v,i,j,M);
                    if(ask < M){
                        M = ask;
                        ans = "Alice";
                        if(M == (k*k) - 1)return ans;
                    }
                }
                else if(pre[i + k - 1][j + k - 1] - pre[i+k - 1][j - 1] - pre[i - 1][j + k - 1] + pre[i-1][j-1] == -(k*k)){
                    int ask = check(v,i,j,M);
                    if(ask < M){
                        M = ask;
                        ans = "Bob";
                        if(M == (k*k) - 1)return ans;
                    }
                }
            }       
        }
    }
    return ans;
}
void solve(){
    
    cin >> n >> m >> k;
    vector<vector<int>> pre(n + 1,vector<int> (m + 1));
    vector<vector<int>> v(n + 1,vector<int> (m + 1));
    // string ans = "Draw";
    // bool found = 0;
    rep(I,0,n * m){
        int a,b;
        cin >> a >> b;
        pre[a][b] = (I&1 ? -1 : 1);
        v[a][b] = I;
        // if(!found){
        //     pre = v;
        //     prefix(pre);
        //     int val = f(pre);
        //     if(val == -1){
        //         found = 1;
        //         ans = "Bob";
        //     }
        //     else if(val == 1){
        //         found = 1;
        //         ans = "Alice";
        //     }
        // }
    }
    prefix(pre);

    cout << f(pre,v);ln;

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL); 
    // gen_factorial(1e6);  	
    int test=1;
	cin>>test;   
    while(test--)
        solve();
    return 0;
}
