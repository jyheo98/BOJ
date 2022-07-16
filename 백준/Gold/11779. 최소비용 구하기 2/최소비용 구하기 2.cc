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
	bool operator() (pair<int, ll> a, pair<int, ll> b) {
		return a.ss > b.ss;
	}
};

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int n, m; cin >> n >> m;
	vector<vector<pair<int, ll>>> g(n), rg(n);
	for(int i=0 ; i<m ; i++) {
		int u, v; ll val; cin >> u >> v >> val;
		u--, v--;
		g[u].push_back({v,val});
		rg[u].push_back({v,val});
	}
	int s, e; cin >> s >> e; s--, e--;
	priority_queue<pair<int, ll>, vector<pair<int, ll>>, cmp> pq;
	pq.push({s,0});
	vector<ll> dis(n, LLINF);
	dis[s] = 0;
	vector<int> prev(n, -1);
	while(sz(pq)) {
		int cur = pq.top().ff;
		ll curDis = pq.top().ss; pq.pop();
		if(dis[cur] < curDis) {
			continue;
		}
		for(pair<int, ll> nxt : g[cur]) {
			if(dis[nxt.ff] > curDis + nxt.ss) {
				prev[nxt.ff] = cur;
				dis[nxt.ff] = curDis + nxt.ss;
				pq.push({nxt.ff, dis[nxt.ff]});
			}
		}
	}
	cout << dis[e] << '\n';
	int cur = e;
	vector<int> ans;
	while(prev[cur]!=-1) {
		ans.push_back(cur);
		cur=prev[cur];
	}
	ans.push_back(cur);
	reverse(all(ans));
	cout<<sz(ans)<<'\n';
	for(auto x : ans) cout << x+1 << ' ';
}