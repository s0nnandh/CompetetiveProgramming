#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct Fenwick{   // 1 - indexed Fenwick tree
    int n;
    vector<ll> bit;  

    Fenwick(int nn){
        this -> n = nn;
        bit.resize(nn + 1);
    }
    void add(ll x,int i){
        while(i <= n){
            bit[i] += x;
            i += i & (-i);
        }
    }
    ll get(int i){
        ll sum = 0;
        while(i > 0){
            sum += bit[i];
            i -= i & (-i);
        }  
        return sum; 
    }
    ll query(int l,int r){
        return get(r) - get(l-1);
    }
};