#include<iostream>
#include<iomanip>
#include<vector>
#include<queue>
#include<set>
#include<algorithm>
#include<string>
#include<map>
#include<functional>
#include<numeric>
#include <stdio.h>
#include <assert.h>
#include <cmath>
#include <bitset>

using namespace std;

int N;

struct Value {
    int cur; 
	int val;
    int pos;
};
Value identity_value() { return { -1, 0, 0 }; }
Value combine(Value &a, Value &b) { 
    Value v;
    v.val = max(a.val, b.val);
    v.pos = a.val > b.val ? a.pos : b.pos;
    v.cur = -1;
    return v;
}

struct Update { 
	int add;
};
Update identity_update() { return { 0 }; }
Value apply_update(Update a, Value x) {
    if(x.cur != -1) { 
	    x.val = (x.val + a.add) % N;
    }
    return x;
 }
Update combine_updates(Update a, Update b) { return {a.add + b.add}; }

// shorter implementation using std::__lg which computes the logarithm in base 2
int next_power_of_two(unsigned x) { return 1<<(32 - __builtin_clz(x)); }

struct SegmentTree {
  int n;
  vector<Value> tree;
  vector<Update> lazy;

  // build segtree of size at least min_n
  SegmentTree(int min_n)
    : n(next_power_of_two(min_n)),
      tree(2*n, identity_value()),
      lazy(2*n, identity_update()) {}

  // build segtree on an array of initial values
  SegmentTree(vector<Value> const& base)
    : n(next_power_of_two(base.size())),
      tree(2*n, identity_value()),
      lazy(2*n, identity_update()) {
    for (int i=0; i<(int)base.size(); ++i)
      tree[n+i] = base[i];
    build(1, 0, n);
  }

    void print_state() {
        for(int i = n;i < n + N;++i)
            cout << tree[i].val << " ";
        cout << '\n';
    }

  // combines all values in range [l, r)
  Value query(int l, int r) {
    assert(0 <= l && l < r && r <= n);
    return query_(l, r, 1, 0, n);
  }

  // updates all values in range [l, r)
  void update(int l, int r, Update a) {
    assert(0 <= l && l < r && r <= n);
    return update_(a, l, r, 1, 0, n);
  }

private:
  // applies the update to the current node
  void apply(int pos, Update a) {
    tree[pos] = apply_update(a, tree[pos]);
    lazy[pos] = combine_updates(a, lazy[pos]);
  }

  // recomputes the value of position "pos", assuming lazy[pos]==identity_update()
  void recompute(int pos) {
    tree[pos] = combine(tree[2*pos], tree[2*pos+1]);
  }

  // pushes lazy values down the tree
  void propagate(int pos) {
    apply(2*pos, lazy[pos]);
    apply(2*pos+1, lazy[pos]);
    lazy[pos] = identity_update();
  }

  // build segtree assuming only leaf nodes are correct
  void build(int pos, int l, int r){
    if (r - l == 1) // leaf: do nothing
      return;
    int m = (l+r)/2;
    build(2*pos, l, m);
    build(2*pos+1, m, r);
    recompute(pos);
  }

  Value query_(int ql, int qr, int pos, int l, int r) {
    // completely contained: return value
    if (ql <= l && r <= qr) { return tree[pos]; }
    // not overlapping: return nothing
    if (qr <= l || r <= ql) { return identity_value(); }
    // otherwise: recurse
    propagate(pos);
    int m = (l+r)/2;
    Value ans_l = query_(ql, qr, 2*pos, l, m);
    Value ans_r = query_(ql, qr, 2*pos+1, m, r);
    return combine(ans_l, ans_r);
  }

  void update_(Update a, int ql, int qr, int pos, int l, int r) {
    // completely contained: update lazy
    if (ql <= l && r <= qr) { apply(pos, a); return; }
    // not overlapping: do nothing
    if (qr <= l || r <= ql) { return; }
    // otherwise: recurse
    propagate(pos);
    int m = (l+r)/2;
    update_(a, ql, qr, 2*pos, l, m);
    update_(a, ql, qr, 2*pos+1, m, r);
    recompute(pos);
  }
};