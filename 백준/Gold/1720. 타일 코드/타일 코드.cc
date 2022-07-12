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
  int n; cin >> n;
  vector<ll> dp(n+1), realdp(n+1);
  dp[0] = 1; dp[1] = 1;
  for(int i=2 ; i<=n ; i++) {
    dp[i] = dp[i-1] + dp[i-2] * 2; 
  }
  if(n&1) cout << (dp[n] + dp[(n-1)/2]) / 2 << '\n';
  else cout << (dp[n] + dp[n/2] + 2*dp[(n-2)/2]) / 2 << '\n';
}