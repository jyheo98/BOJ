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

int ccw(pair<ll, ll> p1, pair<ll, ll> p2, pair<ll, ll> p3) {
  // p1p2 -> p2p3 
  // returns 1 if CCW, 0 if straight, -1 if CW 
  ll CCW = p1.ff * p2.ss + p2.ff * p3.ss + p3.ff * p1.ss - p1.ss * p2.ff - p2.ss * p3.ff - p3.ss * p1.ff;
  if(CCW > 0)
    return 1;
  else if(CCW == 0)
    return 0;
  else if(CCW < 0)
    return -1;
}

int isIntersect(pair<pair<ll, ll>, pair<ll, ll>> x, pair<pair<ll, ll>, pair<ll, ll>> y) {
  pair<ll, ll> a = x.ff;
  pair<ll, ll> b = x.ss;
  pair<ll, ll> c = y.ff;
  pair<ll, ll> d = y.ss;
  int ab = ccw(a,b,c)*ccw(a,b,d);
  int cd = ccw(c,d,a)*ccw(c,d,b);
  if(ab==0 && cd == 0) {
    if(a>b) swap(a, b);
    if(c>d) swap(c,d);
    return c<=b&&a<=d;
  } else {
    return ab<=0&&cd<=0;
  }
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  int n; cin >> n;
  vector<pair<ll, ll>> a(n), b(n);
  for(int i=0 ; i<n ; i++) {
    cin >> a[i].ff >> a[i].ss;
  }
  for(int i=0 ; i<n ; i++) {
    cin >> b[i].ff >> b[i].ss;
  }
  vector<int> p;
  for(int i=0 ; i<n ; i++) p.push_back(i);
  do {
    bool intersect = 0;
    for(int i=0 ; i<n ; i++) {
      for(int j=i+1 ; j<n ; j++) {
        intersect |= isIntersect({a[i],b[p[i]]},{a[j],b[p[j]]});
        if(intersect) break;
      }
      if(intersect) break;
    }
    if(intersect == false) {
      for(auto x : p) {
        cout << x+1 << '\n';
      }
      return 0;
    } 
  } while(next_permutation(all(p)));
}