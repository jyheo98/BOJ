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
	bool operator() (pair<pii, ll> a, pair<pii, ll> b) {
		return a.ss > b.ss;
	} 
};

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int n, m, k; cin >> n >> m >> k;
	vector<vector<pair<int, ll>>> g(n);
	for(int i=0 ; i<m ; i++) {
		int u, v; cin >> u >> v; u--, v--;
		ll val; cin >> val;
		g[u].push_back({v, val});
		g[v].push_back({u, val}); 
	}
	vector<vector<ll>> dis(n, vector<ll>(k+1, LLINF));
	dis[0][0] = 0;
	priority_queue<pair<pii, ll>, vector<pair<pii, ll>>, cmp> pq;
	pq.push({{0,0},0});
	while(sz(pq)) {
		pii cur = pq.top().ff; ll curdis = pq.top().ss; pq.pop();
		if(curdis > dis[cur.ff][cur.ss]) continue;
		for(pair<int, ll> nxt : g[cur.ff]) {
			if(dis[nxt.ff][cur.ss] > dis[cur.ff][cur.ss] + nxt.ss) {
				dis[nxt.ff][cur.ss] = dis[cur.ff][cur.ss] + nxt.ss;
				pq.push({{nxt.ff,cur.ss},dis[nxt.ff][cur.ss]}); 
			} 
			if(cur.ss+1 <= k && dis[nxt.ff][cur.ss+1] > dis[cur.ff][cur.ss]) {
				dis[nxt.ff][cur.ss+1] = dis[cur.ff][cur.ss];
				pq.push({{nxt.ff,cur.ss+1},dis[nxt.ff][cur.ss+1]});
			}
		}
	}
	ll ans = LLINF;
	for(int i=0 ; i<=k ; i++) {
		ans = min(ans, dis[n-1][i]);
	}
	cout << ans << '\n';
}