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

#define int ll

int n;
vector<int> a;
ll cur = 0, ans = 0;
vector<int> vis(11);

void dfs(int x) {
  if(x == n-2) {
    ans = max(ans, cur);
    return;
  }
  vector<pii> b;
  for(int i=0 ; i<n ; i++) {
    if(vis[i] == 0) {
      b.push_back({a[i],i});
    }
  }
  for(int i=1 ; i<sz(b)-1 ; i++) {
    cur += b[i-1].ff * b[i+1].ff;
    vis[b[i].ss] = 1;
    dfs(x+1);
    vis[b[i].ss] = 0;
    cur -= b[i-1].ff * b[i+1].ff;
  }
}

int32_t main() {
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> n;
  a = vector<int>(n);
  for(int i=0 ; i<n ; i++) cin >> a[i];
  dfs(0);
  cout << ans << '\n';
}