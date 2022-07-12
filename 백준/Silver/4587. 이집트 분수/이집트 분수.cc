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

ll gcd(ll a, ll b) {
  if(b == 0) return a;
  return gcd(b, a%b);
}

ll lcm(ll a, ll b) {
  return a / gcd(a, b) * b;
}

bool cl = 0;
vector<ll> p;

void solve(ll a, ll b) {
  if(b>=1000000) return;
  if(a==1&&b<1000000) {
    cl=1;
    p.push_back(b);
    return;
  }
  for(int i=2 ; i<=1000000 ; i++) {
    // a/b - 1/i
    ll ta = a, tb = b, tc = 1, td = i;
    ll L = lcm(b, i);
    ll tax = L / b; ll tac = L / i;
    ta *= tax; tc *= tac;
    ta -= tc;
    if(ta > 0) {
      ll g = gcd(ta, L);
      ta /= g;
      L /= g;
      p.push_back(i);
      solve(ta, L);
      if(cl) return;
      p.pop_back();
    }
  }
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  while(1) {
    p.clear();
    cl = 0;
    ll n, m; cin >> n >> m;
    if(n == 0 && m == 0) return 0;
    solve(n, m);
    for(auto x : p) cout << x << ' ';
    cout << '\n';
  }
} 