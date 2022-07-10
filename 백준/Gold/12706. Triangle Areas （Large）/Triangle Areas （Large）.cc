#include <bits/stdc++.h>
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
const ll MOD = 1e9 + 7;
const long double PI = acos(-1.0);

void solve() {
  ll n, m, a; cin >> n >> m >> a;
  if(n*m < a) {
    cout << "IMPOSSIBLE\n";
    return;
  } else if(a%n == 0) {
    cout << "0 0 " << n << " " << "1 " << 0 << " " << a/n << '\n'; 
  } else if(a%m == 0) {
    cout << "0 0 1 " << m << " " << a/m << " " << 0 << '\n';
  } else {
    cout << "0 0 1 " << m << " " << a/m+1 << " " << (a/m+1)*m-a << '\n';
  }
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  int T; cin >> T;
  for(int tc=1 ; tc<=T ; tc++) {
    cout << "Case #" << tc << ": ";
    solve();
  }
}