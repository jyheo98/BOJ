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
	int n; cin >> n;
	vector<ll> a(n+1), b(n+1);
	for(int i=1 ; i<=n ; i++) {
		cin >> a[i] >> b[i];
	}
	sort(all(a));
	sort(all(b));
	vector<ll> dp(n+1, LLINF);
	dp[0] = 0;
	for(int i=1 ; i<=n ; i++) {
		ll ret1 = dp[i-1] + abs(a[i] - b[i]);
		if(a[i] == b[i]) ret1 = LLINF;
		ll ret2 = LLINF;
		if(i>=2) {
			ret2 = dp[i-2] + abs(a[i] - b[i-1]) + abs(a[i-1] - b[i]);
			if(a[i] == b[i-1] || a[i-1] == b[i]) ret2 = LLINF;  
		}
		ll ret3 = LLINF;
		if(i>=3) {
			vector<int> p = {0, 1, 2};
			ll base = LLINF;
			do {
				bool fail = false;
				ll sum = 0;
				for(int j=0 ; j<3 ; j++) {
					if(a[i-j] == b[i-p[j]]) fail = true;
					sum += abs(a[i-j]-b[i-p[j]]);
				}
				if(fail) continue;
				base = min(base, sum);
			} while(next_permutation(all(p)));
			ret3 = min(ret3, base + dp[i-3]);
		}
		dp[i] = min(ret1, min(ret2, ret3));
	}
	cout << dp[n] << '\n';
}