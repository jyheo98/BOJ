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

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  int n, m; cin >> n >> m;
  vector<set<int>> g(n);
  for(int i=0 ; i<m ; i++) {
    int u, v; cin >> u >> v; u--, v--;
    g[u].insert(v);
    g[v].insert(u);
  }
  vector<int> ans;
  vector<set<int>> newg(n);
  for(int day=0 ; ; day++) {
    for(int i=0 ; i<n ; i++) {
      for(int x : g[i]) {
        for(int y : g[x]) {
          newg[i].insert(y);
        }
      }
    }
    int change = 0;
    for(int i=0 ; i<n ; i++) {
      for(auto x : newg[i]) if(x != i) {
        if(!g[i].count(x)) g[i].insert(x), change++;
      }
    }
    if(change) {
      ans.push_back(change/2);
    } else {
      cout << sz(ans) << '\n';
      for(auto x : ans) {
        cout << x << '\n';
      }
      return 0;
    }
  }
}