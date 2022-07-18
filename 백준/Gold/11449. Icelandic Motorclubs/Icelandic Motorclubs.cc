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

void solve() {
	int n; cin >> n;
	ll score = 0;
	ll mn = 0, mnIdx = 0;
	for(int i=0 ; i<n ; i++) {
		if(score < mn) {
			mn = score;
			mnIdx = i;
		}
		ll g, d; cin >> g >> d;
		score += g - d;
	}
	if(score < 0) {
		cout << "IMPOSSIBLE\n";
	} else {
		cout << mnIdx + 1 << '\n';
	}
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int T; cin >> T;
	while(T--) {
		solve();
	}
}