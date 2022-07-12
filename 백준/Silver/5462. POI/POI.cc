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

bool cmp(pair<pii, int> a, pair<pii, int> b) {
  if(a.ff == b.ff) return a.ss < b.ss;
  if(a.ff.ff == b.ff.ff) return a.ff.ss > b.ff.ss;
  return a.ff.ff > b.ff.ff;
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  int n, t, p; cin >> n >> t >> p; p--;
  vector<vector<int>> a(n, vector<int>(t));
  vector<int> b(t);
  for(int i=0 ; i<n ; i++) {
    for(int j=0 ; j<t ; j++) {
      int x; cin >> x;
      a[i][j] = x;
      b[j] += 1 - x;
    }
  }
  vector<pair<pii, int>> c(n);
  for(int i=0 ; i<n ; i++) {
    c[i].ss = i;
  }
  for(int i=0 ; i<n ; i++) {
    for(int j=0 ; j<t ; j++) {
      c[i].ff.ff += a[i][j] * b[j];
      c[i].ff.ss += a[i][j];
    }
  }
  sort(all(c), cmp);
  for(int i=0 ; i<n ; i++) {
    if(p == c[i].ss) {
      cout << c[i].ff.ff << ' ' << i+1 << '\n';
    }
  }
}