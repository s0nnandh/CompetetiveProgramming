#include<bits/stdc++.h>
using namespace std;
#define ll long long 
struct Fenwick2d     // 1 - based indexing
{
    int r,c;
    vector<vector<ll>> bit;
    Fenwick2d(int row,int col){
        r = row;
        c = col;
        bit.assign(row + 1,vector<ll> (col + 1));
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