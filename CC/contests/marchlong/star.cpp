#pragma GCC optimize ("Ofast")
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

ll answer(ll left,ll right,vector<ll> &a){
    ll l = left,r = right,crct_upto = 1;
    ll ans = 1;
    while(r <= right){
        //dbg(l,r);
        bool maybe = 1;//int bre = -1;
        rep(k,crct_upto+1,r){
            if(a[k] < min(a[crct_upto+1],a[r]))continue;
            if(((a[r]*(l-r))+((a[l]-a[r])*(k-r))) > a[k]*(l-r)){
                    //bre = k;
                    //dbg(k);
                    maybe = 0;
                    break;
            }
            crct_upto = k;
        }
        if(maybe){
            ans = max(ans,r-l);
            //dbg(l,r);
            ++r;
            if(r == right+1)break;
            else{
                l++;
                r = right;
                crct_upto = l;
            }
        }
        else{
            // int prer = a[r];
            // while(r > crct_upto+1 && a[r] <= prer){
            //     r--;
            // } 
            r--;           
            //bool b = 0;
            if(r-l <= ans){        
                //l++;
                int pre = a[l];
                bool brok = 0;
                while(l <= crct_upto){
                    //dbg(l,r,crct_upto); 
                    if(a[l] > pre){
                        brok = 1;
                        break;
                    }
                    ++l;
                }                
                r = right;
                if(!brok)crct_upto = l;
            }
            if(r-l <= ans)break; 
        }        
    }
    return ans;
}


void solve(){    
    ll n;
    cin >> n;
    vector<ll> a(n+1);
    ll maxima = 0;
    rep(i,1,n+1){
        cin >> a[i]; 
        maxima = max(maxima,a[i]);
    }    
    int cnt = 0 ,first = -1,last = -1;
    rep(i,1,n+1){
        if(a[i] == maxima){
            if(first == -1)first = i;
            last = i;
        }
    }
    if(last-first >= (n+1)/2){
        cout << last - first;ln;
        return;
    }
    if(cnt == 1){
        ll k = -1;
        if(n-last >= first - 1){
            k = answer(last,n,a);
        }
        if(k < first - 1){
            k = max(k,answer(1,first,a));
        }
        cout << k;ln;
        return;
    }
    cout << answer(1,n,a);ln;

    //cout << ans;ln;
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
