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

int p[400004];

int find(int x) {
	if(x == p[x]) return x;
	return p[x] = find(p[x]);
}
void unite(int x, int y) {
	x = find(x), y = find(y);
	p[x] = y;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int n, m, q; cin >> n >> m >> q;
	for(int i=0 ; i<n+m ; i++) p[i] = i;
	for(int i=0 ; i<q ; i++) {
		int x, y; cin >> x >> y; x--, y--;
		unite(x, y+n);
	}
	int ans = 0;
	for(int i=0 ; i<n+m ; i++) {
		ans += (find(i) == i);
	}
	cout << ans-1 << '\n';
}