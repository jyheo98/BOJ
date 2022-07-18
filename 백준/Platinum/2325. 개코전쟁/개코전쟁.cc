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

int n, m;
vector<vector<pair<int, ll>>> g;
vector<ll> dis;
priority_queue<pair<int, ll>, vector<pair<int, ll>>, cmp> pq;
vector<int> prv;

ll dijkstra(int ban1, int ban2, int cprev) {
	for(int i=1 ; i<n ; i++) {
		dis[i] = LLINF;
	}
	pq.push({0,0});
	while(sz(pq)) {
		int cur = pq.top().ff; ll curdis = pq.top().ss; pq.pop();
		if(dis[cur] < curdis) continue;
		for(pair<int, ll> nxt : g[cur]) {
			if(cur == ban1 && nxt.ff == ban2) continue;
			if(cur == ban2 && nxt.ff == ban1) continue;
			if(dis[nxt.ff] > dis[cur] + nxt.ss) {
				dis[nxt.ff] = dis[cur] + nxt.ss;
				if(cprev) prv[nxt.ff] = cur;
				pq.push({nxt.ff, dis[nxt.ff]});
			}
		}
	}
	return dis[n-1];
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n >> m;
	prv = vector<int>(n,-1);
	g = vector<vector<pair<int, ll>>>(n);
	dis = vector<ll>(n);
	for(int i=0 ; i<m ; i++) {
		int u, v; ll val; cin >> u >> v >> val; u--, v--;
		g[u].push_back({v,val});
		g[v].push_back({u,val});
	}
	dijkstra(-1,-1,1);
	int cur = n-1;
	ll ans = 0;
	while(prv[cur]!=-1) {
		ans=max(ans,dijkstra(prv[cur],cur,0));
		cur=prv[cur];
	}
	cout<<ans<<'\n';
}