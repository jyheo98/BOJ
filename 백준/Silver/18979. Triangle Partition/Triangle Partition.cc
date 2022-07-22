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
	vector<pair<pii, int>> a(n*3);
	for(int i=0 ; i<n*3 ; i++) {
		cin >> a[i].ff.ff >> a[i].ff.ss;
		a[i].ss = i+1;
	}
	sort(all(a));
	for(int i=0 ; i<n*3 ; i++) {
		cout << a[i].ss << ' ';
	}
	cout << '\n';
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int t = 1; cin >> t;
	while(t--)
		solve();
}