#include<bits/stdc++.h>
#include<unordered_map>
#define ll long long
#define ull unsigned long long
#define ln cout<<"\n"
#define dbg(x) cout<<#x<<" = "<<x<<" "
#define rep(i,s,n) for(ll i = (s);i<(n);++i)
#define DEBUG(x) do { std::cerr << #x << ": " << x << std::endl; } while (0)
using namespace std;
void solve(){
    int n,q;char ch;
    cin >> n >> q;
    vector<vector<int>> v(n+1, vector<int> (n+1));
    rep(i,1,n+1){
        rep(j,1,n+1){
            cin >> ch;
            v[i][j] = (ch == '.')?0:1;
        }
    }
    // rep(i,1,n+1){
    //     rep(j,1,n+1){
    //         cout<<v[i][j]<<" ";
    //     }
    //     ln;
    // }

    rep(i,1,n+1){
        rep(j,1,n+1){
            v[i][j]+=v[i-1][j] + v[i][j-1] - v[i-1][j-1];
        }
    }
    // rep(i,1,n+1){
    //     rep(j,1,n+1){
    //         cout<<v[i][j]<<" ";
    //     }
    //     ln;
    // }
    int y1,x1,y2,x2;
    rep(i,0,q){
        cin >> y1 >> x1 >> y2 >> x2;
        cout << v[y2][x2] - v[y1-1][x2] - v[y2][x1-1] + v[y1-1][x1-1];ln;
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

// #include<bits/stdc++.h> 
// #include<string>
// #include<vector>
// #define ll long long
// #define ln "\n"
// #define dbg(x) cout<<#x<<" = "<<x<<ln
// using namespace std;
// void solve(){
//     int n,q;
//     cin >> n >> q;
//     vector<vector<int>> a(n ,vector<int> (n));
//    //vector<int,int>a(n)(n);
//    vector<vector<int>> sum(n+3 , vector<int> (n+3));
//    //vector<int,int>sum(n+3)(n+3);
//    char ch;
//    for(int i=0;i<n;i++)
//    {
//        for(int j=0;j<n;j++){        
//            cin>>ch;
//            a[i][j] = (ch == '.')?0:1;
//        }
//    }
//    for(int i=1;i<=n;i++)
//    {
//        for(int j=1;j<=n;j++)
//        {
//             sum[i][j]=a[i-1][j-1]+sum[i][j-1]+sum[i-1][j]-sum[i-1][j-1];
//        }
//    }
//    int i1,j1,i2,j2;
//    for(int k=0;k<q;k++)
//    {
//        cin>>i1>>j1>>i2>>j2;
//        int ans=sum[i2][j2] - sum[i1-1][j2] - sum[i2][j1 - 1] + sum[i1 - 1][j1 - 1];;
//         cout<<ans<<ln;
//    }
    
// }
// int main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     cout.tie(NULL); 
//     ll t = 1;
//     cin>>t;
//     while(t--)solve();       
     
// }

// // 