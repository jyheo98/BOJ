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
  int sum = 0;
  int a=0, b=0, c=0;
  while(n--) {
    string s; cin >> s;
    if(s == "1/4") a++;
    else if(s == "1/2") b++;
    else if(s == "3/4") c++;
  }
  int ans = 0;
  int z = min(a,c);
  a-=z; c-=z;
  ans += z;
  ans += c;
  ans += b/2;
  b %= 2;
  ans += a/4;
  a %= 4;
  if(b==1&&a<=2) {
    b-=1;
    a-=2;
    a=max(a,0);
    ans++;
  }
  if(a) ans++;
  cout << ans << '\n';
}