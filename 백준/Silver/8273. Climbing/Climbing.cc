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
	vector<ll> a(n);
	for(int i=0 ; i<n ; i++) {
		ll x, y; cin >> x >> y;
		a[i] = x+y;
	}
	ll ans = 0;
	int l=0, r=a[0];
	for(int i=1 ; i<n ; i++) {
		ll x = max(0LL, a[i]-r);
		ll y = a[i]-l;
		if(x<=y) ans++,l=x,r=y;
		else l=0,r=a[i];
	}
	cout << ans << '\n';
}