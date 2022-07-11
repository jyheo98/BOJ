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
  ll lsum, rsum;
  ll msum;
  Node() {
    l=INF, r=INF;
    sum = 0LL;
    lsum = rsum = msum = 0LL;
  }
};

int n, m, k;
vector<ll> a;
vector<Node> seg(300005);

void build(int idx, int l, int r) {
  if(l == r) {
    return;
  }
  seg[idx].l = sz(seg); seg.emplace_back(Node());
  seg[idx].r = sz(seg); seg.emplace_back(Node());
  int mid = (l + r) / 2;
  build(seg[idx].l, l, mid);
  build(seg[idx].r, mid+1, r);
}

Node op(Node l, Node r) {
  Node ret;
  if(l.l==-1) return r;
  if(r.r==-1) return l;
  ret.l = INF;
  ret.r = INF;
  ret.sum = l.sum + r.sum;
  ret.lsum = max({l.lsum, l.sum + r.lsum});
  ret.rsum = max({r.rsum, r.sum + l.rsum});
  ret.msum = max({l.msum, r.msum, l.rsum + r.lsum});
  return ret;
}

void update(int old, int cur, int l, int r, int idx, ll val) {
  seg[cur] = seg[old];
  if(l == r) {
    seg[cur].sum += val;
    seg[cur].rsum += val;
    seg[cur].lsum += val;
    seg[cur].msum += val;
    return;
  }
  int mid = (l+r) / 2;
  if(idx <= mid) {
    seg[cur].l = sz(seg); seg.emplace_back(Node());
    update(seg[old].l, seg[cur].l, l, mid, idx, val);
  } else {
    seg[cur].r = sz(seg); seg.emplace_back(Node());
    update(seg[old].r, seg[cur].r, mid+1, r, idx, val);
  }
  int lchild = seg[cur].l;
  int rchild = seg[cur].r;
  Node c = op(seg[lchild],seg[rchild]);
  seg[cur] = c;
  seg[cur].l = lchild;
  seg[cur].r = rchild;
}

Node calc(int cur, int l, int r, int tl, int tr) {
  //debug(seg[cur].l, seg[cur].r, l, r, tl, tr);
  if(l>tr || r<tl) {
    Node ret;
    ret.l=-1,ret.r=-1,ret.sum=-1,ret.lsum=-1,ret.rsum=-1,ret.msum=-1;
    return ret;
  }
  if(tl <= l && r <= tr) {
    return seg[cur]; 
  }
  int mid = (l+r) / 2;
  return op(calc(seg[cur].l,l,mid,tl,tr),calc(seg[cur].r,mid+1,r,tl,tr));
}

bool cmp(pair<pii, ll> a, pair<pii, ll> b) {
  return a.ff.ff < b.ff.ff;
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> n >> m >> k;
  build(0, 0, m-1);
  vector<pair<pii, ll>> q;
  for(int i=0 ; i<k ; i++) {
    int r, c; cin >> r >> c; r--, c--;
    ll val; cin >> val;
    q.push_back({{r,c},val});
  }
  sort(all(q),cmp);
  vector<int> lookup(n);
  int id=0;
  for(int i=0 ; i<n ; i++) {
    while(id<k&&q[id].ff.ff<=i) id++;
    lookup[i]=id;
  } 
  for(int i=0 ; i<k ; i++) {
    update(i,i+1,0,m-1,q[i].ff.ss,q[i].ss);
  }
  int qu; cin >> qu;
  ll p3=-1,p2=-1,p1=-1;
  while(qu--) {
    int h, x, y; cin >> h >> x >> y; 
    if(p3!=-1) h^=p3;
    if(p2!=-1) x^=p2;
    if(p1!=-1) y^=p1;
    x--,y--,h--;
    ll ans = max(0LL,calc(lookup[h], 0, m-1, x, y).msum);
    p3=p2;
    p2=p1;
    p1=ans;
    cout << ans << '\n';
  }
}