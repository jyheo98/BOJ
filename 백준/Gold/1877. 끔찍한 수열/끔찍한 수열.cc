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

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  int N; cin >> N;
  if(N % 3 == 0) {
    cout << N/3 << ' ' << N/3 << ' ';
  } else {
    if(N == 1) {
      cout << 1 << ' ' << 1 << ' ';
    } else {
      int noOf3 = (N-2)/3;
      int noOf2 = (N - noOf3 * 3) / 2;
      cout << noOf2 + noOf3 << ' ' << noOf3 + (noOf2+1) / 2 << ' ';
    }
  }

  if(N == 1) {
    cout << 1 << ' ' << 1 << '\n';
    return 0;
  }
  int ans = 0;
  int twos = 0;
  for(int i=2 ; i*i<=N ; i++) {
    while(N%i==0) {
      N/=i;
      ans++;
      if(i==2) twos++;
    }
  }
  if(N!=1) ans++;
  if(N==2) twos++;
  cout << ans << ' ' << ans - twos/2 << '\n';
}