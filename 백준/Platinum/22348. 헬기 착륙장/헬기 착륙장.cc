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

ll dp[505][50505];

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	dp[0][0] = 1;
	for(int r = 0 ; r <= 500 ; r++) {
		for(int red=0 ; red <= 50000 ; red++) if(dp[r][red]) {
			dp[r+1][red+r+1] += dp[r][red];
			dp[r+1][red+r+1] %= MOD;
			dp[r+1][red] += dp[r][red];
			dp[r+1][red] %= MOD;
		}
		for(int red=1 ; red<=50000 ; red++) {
			dp[r][red] += dp[r][red-1];
			dp[r][red] %= MOD;
		}
	}
	int T; cin >> T;
	while(T--) {
		ll a, b; cin >> a >> b;
		ll ans = 0;
		for(int r=1 ; r<=500 ; r++) if(a+b>=r*(r+1)/2) {
			ans += dp[r][a];
			if(r*(r+1)/2-b-1>=0)
				ans -= dp[r][r*(r+1)/2-b-1];
			ans %= MOD; ans += MOD; ans %= MOD;
		}
		cout << ans << '\n';
	}
}