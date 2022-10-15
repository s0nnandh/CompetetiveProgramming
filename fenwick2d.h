#include<bits/stdc++.h>
struct Fenwick2d     // 1 - based indexing
{
    int r,c;
    std :: vector<std :: vector<long long>> bit;
    Fenwick2d(int row,int col){
        r = row;
        c = col;
        bit.assign(row + 1,std :: vector<long long> (col + 1));
    }
    void add(long long x,int row,int col){
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
    long long get(int row,int col){
        long long sum = 0;
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
    long long query(int x1,int y1,int x2,int y2){
        return get(x2,y2) + get(x1-1,y1-1) - get(x2,y1-1) - get(x1-1,y2);
    }
};