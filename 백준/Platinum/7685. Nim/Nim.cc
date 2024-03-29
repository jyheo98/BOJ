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
	while(1) {
		int n; cin >> n;
		if(!n) return 0;
		vector<ll> a(n);
		int x = 0;
		for(int i=0 ; i<n ; i++) {
			cin >> a[i];
			x ^= a[i];
		}
		int ans = 0;
		for(int i=0 ; i<n ; i++) {
			ll cur = (x^a[i]);
			ll m = 0;
			for(int j=0 ; j<40 ; j++) {
				if(cur & (1LL<<j)) {
					m ^= (1LL<<j);
				}
			}
			if(m < a[i]) ans++;
		}
		cout << ans << '\n';
	}
}