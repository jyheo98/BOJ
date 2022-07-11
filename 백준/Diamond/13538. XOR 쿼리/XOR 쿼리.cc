#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
  #include "headers/debug.h"
#else
  #define debug(...) 42
#endif

using namespace std;

#define all(x) x.begin(), x.end()
#define ff first
#define ss second
#define LLINF 0x3f3f3f3f3f3f3f3f
#define INF 0x3f3f3f3f
#define uniq(x) sort(all(x)); x.resize(unique(all(x))-x.begin());
#define sz(x) (int)x.size()
#define pw(x) (1LL<<x)

using pii = pair<int, int>;
using ll = long long;
using ld = long double;
const ll MOD = 1e9 + 7;
const long double PI = acos(-1.0);

struct Node {
  int l, r;
  ll sum;
  Node() {
    l = -1, r = -1;
    sum = 0;
  }
};

vector<Node> seg(530000);

void build(int idx, int l, int r) {
  if(l == r) {
    return;
  }
  seg[idx].l = sz(seg); seg.emplace_back(Node());
  seg[idx].r = sz(seg); seg.emplace_back(Node());
  int mid = (l+r) / 2;
  build(seg[idx].l, l, mid);
  build(seg[idx].r, mid+1, r);
}

void update(int old, int cur, int l, int r, int idx) {
  seg[cur] = seg[old];
  if(l == r) {
    seg[cur].sum = seg[old].sum + 1;
    return;
  } 
  int mid = (l+r) / 2;
  if(idx <= mid) {
    seg[cur].l = sz(seg); seg.emplace_back(Node());
    update(seg[old].l, seg[cur].l, l, mid, idx);
  } else {
    seg[cur].r = sz(seg); seg.emplace_back(Node());
    update(seg[old].r, seg[cur].r, mid+1, r, idx);
  }
  seg[cur].sum = seg[seg[cur].l].sum + seg[seg[cur].r].sum;
}

int calc(int id, int l, int r, int tl, int tr) {
  if(tl <= l && r <= tr) {
    return seg[id].sum;
  } else if(tl > r || tr < l) {
    return 0;
  } 
  int mid = (l+r) / 2;
  return calc(seg[id].l, l, mid, tl, tr) + calc(seg[id].r, mid+1, r, tl, tr);
}

int find(int id1, int id2, int rank, int l, int r) {
  if(l == r) return l;
  int l1 = seg[id1].l;
  int l2 = seg[id2].l;
  int r1 = seg[id1].r;
  int r2 = seg[id2].r;
  int mid = (l+r) / 2;
  if(seg[l2].sum - seg[l1].sum >= rank) {
    return find(l1, l2, rank, l, mid);
  } else {    
    return find(r1, r2, rank - seg[l2].sum + seg[l1].sum, mid+1, r);
  }
}

int calc2(int id1, int id2, int tar, int num) {
  if(num == 0) return 0;
  int l1 = seg[id1].l;
  int l2 = seg[id2].l;
  int r1 = seg[id1].r;
  int r2 = seg[id2].r;
  if(tar & num) {
    if(seg[l2].sum - seg[l1].sum > 0) {
      return calc2(l1, l2, tar, num / 2);
    } else {
      return num + calc2(r1, r2, tar, num / 2);
    }
  } else {
    if(seg[r2].sum - seg[r1].sum > 0) {
      return num + calc2(r1, r2, tar, num / 2);
    } else {
      return calc2(l1, l2, tar, num / 2);
    }
  }
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  int q; cin >> q;
  int curId = 1;
  int maxN = (1<<19)-1;
  build(0, 0, maxN);
  while(q--) {
    int op; cin >> op;
    if(op == 1) {
      int x; cin >> x;
      update(curId-1, curId, 0, maxN, x);
      curId++;
    } else if(op == 2) {
      int l, r, x; cin >> l >> r >> x;
      cout << calc2(l-1, r, x, 1<<18) << '\n';
    } else if(op == 3) {
      int k; cin >> k;
      curId -= k;
    } else if(op == 4) {
      int l, r; cin >> l >> r; 
      int x; cin >> x;
      cout << calc(r, 0, maxN, 0, x) - calc(l-1, 0, maxN, 0, x) << '\n';
    } else {
      int l, r; cin >> l >> r;
      int k; cin >> k;
      cout << find(l-1, r, k, 0, maxN) << '\n';
    }
  }
}