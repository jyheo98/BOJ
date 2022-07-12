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
  ll op(ll a, ll b) {
    return a + b;
  }
  ll upd_(int idx, int l, int r, int pos, ll val) {
    if (pos < l || pos > r) return seg[idx];
    if (pos == l && pos == r) return seg[idx] += val;
    int mid = (l + r) / 2;
    return seg[idx] = op(upd_(idx * 2, l, mid, pos, val),
        upd_(idx * 2 + 1, mid + 1, r, pos, val));
  }
  ll calc_(int idx, int l, int r, int tl, int tr) {
    if (tl > tr) return 0;
    if (tl == l && tr == r) return seg[idx];
    int mid = (l + r) / 2;
    return op(calc_(idx * 2, l, mid, tl, min(tr, mid)),
      calc_(idx * 2 + 1, mid + 1, r, max(mid + 1, tl), tr));
  }
  ll find_(int idx, int l, int r, ll rank) {
    if(l==r) return l;
    int mid = (l+r)/2;
    if(seg[idx*2]>=rank) return find_(idx*2,l,mid,rank);
    else return find_(idx*2+1,mid+1,r,rank-seg[idx*2]); 
  }
  void upd(int pos, ll val) {
    upd_(1, 0, n - 1, pos, val);
  }
  ll calc(int l, int r) {
    return calc_(1, 0, n - 1, l, r);
  } 
  ll find(ll rank) {
    return find_(1, 0, n-1, rank);
  }
};

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  int n; cin >> n;
  ll atk, hp; cin >> atk >> hp;
  SegmentTree st(n);
  vector<ll> a(n);
  for(int i=0 ; i<n ; i++) {
    ll x; cin >> x; st.upd(i, x);
    a[i]=x;
  }
  ll ans = 0;
  for(int i=0 ; i<n ; i++) {
    for(int j=i ; j<n ; j++) {
      ll meatk = st.calc(i,j);
      vector<int> b; 
      for(int k=0 ; k<i ; k++) b.push_back(a[k]);
      for(int k=j+1 ; k<n ; k++) b.push_back(a[k]);
      ll mehp = 0;
      for(int l=0,r=0 ; r<sz(b) ; r++) {
        mehp += b[r];
        while(1) {
          ll medieturn = (mehp + atk - 1) / atk;
          ll enedieturn = (hp + meatk - 1) / meatk;
          if(medieturn>enedieturn) {
            mehp-=b[l++];
          } else {
            ans+=l;
            break;
          }
        }
      }
      debug(i,j,ans);
    }
  }
  if(ans==0) puts("IMPOSSIBLE");
  else cout<<ans<<'\n';
}