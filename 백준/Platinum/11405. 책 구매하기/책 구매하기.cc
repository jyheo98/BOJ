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

class MCMF {
public:
	struct edge {
		int u, v;
		ll cap, cost, flow;
		edge(int u, int v, ll cap, ll cost, ll flow) : u(u), v(v), cap(cap), cost(cost), flow(flow) {}
	};

	int N, S, T, eno; 

	vector<edge> e;
	vector<vector<int>> g;
	MCMF(int n) {
		g.resize(n+5);
		N = n;
		S = n+1;
		T = n+2;
		eno = 0;
	}

	void flow() {
		ll ret = 0;
		ll cst = 0;
		while(1) {
			vector<int> prev(N+5, -1);
			vector<ll> dis(N+5, LLINF);
			queue<int> q; q.push(S); dis[S] = 0;
			vector<bool> inQ(N+5); inQ[S] = 1;
			while(q.size()) {
				int cur = q.front(); q.pop(); inQ[cur] = false;
				for(int id : g[cur]) {
					int nxt = e[id].u+e[id].v-cur;
					if(dis[nxt] > dis[cur] + e[id].cost && e[id].cap-e[id].flow>0) {
						dis[nxt] = dis[cur] + e[id].cost;
						prev[nxt] = id;
						if(inQ[nxt] == 0) {
							inQ[nxt] = 1;
							q.push(nxt);
						}
					}
				}
			}
			if(prev[T] == -1) break;
			ll flow = LLINF;
			for(int cur = T ; cur != S ; cur = e[prev[cur]].u+e[prev[cur]].v-cur) {
				int id = prev[cur];
				flow = min(flow, e[id].cap - e[id].flow);
			}
			for(int cur = T ; cur != S ; cur = e[prev[cur]].u+e[prev[cur]].v-cur) {
				int id = prev[cur];
				e[id].flow += flow;
				e[id^1].flow -= flow;
				cst += e[id].cost * flow;
			}
			ret += flow;
		}
		// ret = FLOW
		cout << cst << '\n';
	}

	void add_edge(int u, int v, ll cap, ll cost) {
		e.emplace_back(u,v,cap,cost,0);
		e.emplace_back(v,u,0,-cost,0);
		g[u].push_back(eno++);
		g[v].push_back(eno++);
	}
};

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int n, m; cin >> n >> m;
	MCMF g(n+m);
	vector<int> a(n);
	vector<int> b(m);
	for(int i=0 ; i<n ; i++) cin >> a[i];
	for(int i=0 ; i<m ; i++) cin >> b[i];
	for(int i=0 ; i<m ; i++) {
		g.add_edge(g.S, i, b[i], 0);
	}
	for(int i=0 ; i<n ; i++) {
		g.add_edge(m+i, g.T, a[i], 0);
	}
	for(int i=0 ; i<m ; i++) {
		for(int j=0 ; j<n ; j++) {
			ll x; cin >> x;
			g.add_edge(i,m+j,LLINF,x);
		}
	}
	g.flow();
}