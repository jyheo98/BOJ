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

class SegmentTree {
public:
  vector<ll> seg;
  int n;
  SegmentTree(int n) {
    seg.resize(4 * n + 5);
    this->n = n;
  }
  ll upd_(int idx, int l, int r, int pos, ll val) {
    if (pos < l || pos > r) return seg[idx];
    if (pos == l && pos == r) return seg[idx] = val;
    int mid = (l + r) / 2;
    return seg[idx] = min(
      upd_(idx * 2, l, mid, pos, val),
      upd_(idx * 2 + 1, mid + 1, r, pos, val)
      );
  }
  ll calc_(int idx, int l, int r, int tl, int tr) {
    if (tl > tr) return LLINF;
    if (tl == l && tr == r) return seg[idx];
    int mid = (l + r) / 2;
    return min(
      calc_(idx * 2, l, mid, tl, min(tr, mid)),
      calc_(idx * 2 + 1, mid + 1, r, max(mid + 1, tl), tr)
      );
  }
  void upd(int pos, ll val) {
    upd_(1, 0, n - 1, pos, val);
  }
  ll calc(int l, int r) {
    return calc_(1, 0, n - 1, l, r);
  }
};

class SegmentTree2 {
public:
  vector<ll> seg;
  int n;
  SegmentTree2(int n) {
    seg.resize(4 * n + 5);
    this->n = n;
  }
  ll upd_(int idx, int l, int r, int pos, ll val) {
    if (pos < l || pos > r) return seg[idx];
    if (pos == l && pos == r) return seg[idx] = val;
    int mid = (l + r) / 2;
    return seg[idx] = max(
      upd_(idx * 2, l, mid, pos, val),
      upd_(idx * 2 + 1, mid + 1, r, pos, val)
      );
  }
  ll calc_(int idx, int l, int r, int tl, int tr) {
    if (tl > tr) return -LLINF;
    if (tl == l && tr == r) return seg[idx];
    int mid = (l + r) / 2;
    return max(
      calc_(idx * 2, l, mid, tl, min(tr, mid)),
      calc_(idx * 2 + 1, mid + 1, r, max(mid + 1, tl), tr)
      );
  }
  void upd(int pos, ll val) {
    upd_(1, 0, n - 1, pos, val);
  }
  ll calc(int l, int r) {
    return calc_(1, 0, n - 1, l, r);
  }
};

void solve() {
  int n; cin >> n;
  vector<ll> a(n);
  for(int i=0 ; i<n ; i++) {
    cin >> a[i];
  }
  vector<vector<int>> sparse_table(n, vector<int>(25));
  for(int i=0 ; i<n ; i++) {
    sparse_table[i][0] = a[i];
  }
  for(int pw=1 ; pw<25 ; pw++) {
    for(int i=0 ; i+(1LL<<(pw-1))<n ; i++) {
      sparse_table[i][pw] = min(sparse_table[i][pw-1], sparse_table[i+(1LL<<(pw-1))][pw-1]);
    }
  }
  vector<int> log(n+1);
  log[1] = 0;
  for(int i=2 ; i<=n ; i++)
    log[i] = log[i/2] + 1;
  auto min_query = [&](int s, int e) {
    int lg = log[e-s+1];
    return min(sparse_table[s][lg],sparse_table[e-(1<<lg)+1][lg]);
  };
  vector<vector<int>> sparse_table2(n, vector<int>(25));
  for(int i=0 ; i<n ; i++) {
    sparse_table2[i][0] = a[i];
  }
  for(int pw=1 ; pw<25 ; pw++) {
    for(int i=0 ; i+(1LL<<(pw-1))<n ; i++) {
      sparse_table2[i][pw] = max(sparse_table2[i][pw-1], sparse_table2[i+(1LL<<(pw-1))][pw-1]);
    }
  }
  auto max_query = [&](int s, int e) -> ll{
    int lg = log[e-s+1];
    return max(sparse_table2[s][lg],sparse_table2[e-(1<<lg)+1][lg]);
  };
  bool good = false;

  set<int> st;
  for(int i=1 ; i<n ; i++) {
    st.insert(a[i-1]);
    if(sz(st)==0) continue;
    for(int j=i+2 ; j<n ; j++) if(a[i] < a[j]) {
      ll x = max_query(i+1,j-1);
      if(x > a[j]) {
        auto id = st.lower_bound(a[j]);
        if(id!=st.end()&&(*id)<x) {
          debug((*id),a[i],x,a[j]);
          good = true;
        }
      } 
    }
  }
  reverse(all(a));
  st.clear();
  for(int i=0 ; i<n ; i++) {
    sparse_table[i][0] = a[i];
  }
  for(int pw=1 ; pw<25 ; pw++) {
    for(int i=0 ; i+(1LL<<(pw-1))<n ; i++) {
      sparse_table[i][pw] = min(sparse_table[i][pw-1], sparse_table[i+(1LL<<(pw-1))][pw-1]);
    }
  }
  for(int i=0 ; i<n ; i++) {
    sparse_table2[i][0] = a[i];
  }
  for(int pw=1 ; pw<25 ; pw++) {
    for(int i=0 ; i+(1LL<<(pw-1))<n ; i++) {
      sparse_table2[i][pw] = max(sparse_table2[i][pw-1], sparse_table2[i+(1LL<<(pw-1))][pw-1]);
    }
  }
  for(int i=1 ; i<n ; i++) {
    st.insert(a[i-1]);
   // debug(st);
    for(int j=i+2 ; j<n ; j++) if(a[i] < a[j]) {
      ll x = max_query(i+1,j-1);
    //  debug(x);
      if(x > a[j]) {
        auto id = st.lower_bound(a[j]);
        if(id!=st.end()&&(*id)<x) {
          good = true;
        }
      } 
    }
  }
  if(good) cout<<"Yes\n";
  else cout << "No\n";
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  int t = 1; cin >> t;
  while(t--)
    solve();
}