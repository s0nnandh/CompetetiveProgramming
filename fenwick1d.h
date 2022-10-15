#include<bits/stdc++.h>
/*
    This is a 1 - indexed Fenwick Tree or Binary Index Tree(BIT)

    add(x, i) => add x at position i - O(logn)

    get(i)    => get sum from [1,i]  - O(logn)

    query(l, r) => get sum from [l,r] - O(logn)

*/
template <typename T> 
struct Fenwick{   // 1 - indexed Fenwick tree
    int n;
    std :: vector<T> bit;  

    Fenwick(int nn){
        this -> n = nn;
        bit.resize(nn + 1);
    }
    void add(T x,int i){
        while(i <= n){
            bit[i] += x;
            i += i & (-i);
        }
    }
    T get(int i){
        T sum = 0;
        while(i > 0){
            sum += bit[i];
            i -= i & (-i);
        }  
        return sum;
    }
    T query(int l,int r){
        return get(r) - get(l-1);
    }
};