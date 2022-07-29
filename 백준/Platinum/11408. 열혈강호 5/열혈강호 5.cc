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

struct edge {
	int u, v;
	ll cap;
	ll cost;
	ll flow;
};

int N = 800;
int S = N+1;
int T = N+2;

vector<edge> e;
vector<vector<int>> g(N+5);
int n, m, eno = 0; 

pair<ll, ll> flow() {
	ll ret = 0;
	ll cst = 0;
	while(1) {
		vector<int> prev(N+5, -1);
		vector<ll> dis(N+5, INF);
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
		ll flow = LLONG_MAX;
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
	return {ret,cst};
}

void add_edge(int u, int v, ll cap, ll cost) {
	e.push_back({u,v,cap,cost,0});
	e.push_back({v,u,0,-cost,0});
	g[u].push_back(eno++);
	g[v].push_back(eno++);
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n >> m;
	for(int i=0 ; i<n ; i++) {
		add_edge(S,i,1,0);
	}
	for(int i=0 ; i<m ; i++) {
		add_edge(n+i,T,1,0);
	}
	for(int i=0 ; i<n ; i++) {
		int k; cin >> k;
		while(k--) {
			int u; cin >> u; u--;
			ll val; cin >> val;
			add_edge(i,n+u,1,val);
		}
	}
	pair<ll, ll> ans = flow();
	cout << ans.ff << ' ' << ans.ss << '\n';
}