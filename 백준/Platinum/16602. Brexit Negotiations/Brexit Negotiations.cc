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

struct cmp {
	bool operator() (pii a, pii b) {
		return a.ss > b.ss;
	}
};

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int n; cin >> n;
	vector<ll> a(n);
	vector<vector<int>> g(n);
	vector<int> deg(n);
	for(int i=0 ; i<n ; i++) {
		cin >> a[i];
		int k; cin >> k;
		while(k--) {
			int v; cin >> v; v--;
			g[i].push_back(v);
			deg[v]++;
		}
	}
	priority_queue<pii, vector<pii>, cmp> pq;
	for(int i=0 ; i<n ; i++) {
		if(deg[i] == 0) pq.push({i, a[i]});
	}
	int pts = n-1;
	ll ans = 0;
	while(sz(pq)) {
		int cur = pq.top().ff; pq.pop();
		ans = max(ans, a[cur] + pts);
		pts--;
		for(int nxt : g[cur]) {
			deg[nxt]--;
			if(deg[nxt] == 0) pq.push({nxt, a[nxt]});
		}
	}
	cout << ans << '\n';
}