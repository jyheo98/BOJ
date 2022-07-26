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

const int N = 505;
int n, m;
vector<pair<int, ll>> g[N];
bool inQ[N];
int cnt[N];

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n >> m;
	vector<ll> dis(n, LLINF);
	for(int i=0 ; i<m ; i++) {
		int u, v; cin >> u >> v; u--, v--;
		ll val; cin >> val;
		g[u].push_back({v, val});
	}
	queue<int> q; q.push(0);
	dis[0] = 0; cnt[0]++;
	while(sz(q)) {
		int cur = q.front(); q.pop(); inQ[cur] = 0;
		for(pair<int, ll> nxt : g[cur]) {
			if(dis[cur] + nxt.ss < dis[nxt.ff]) {
				dis[nxt.ff] = dis[cur] + nxt.ss;
				if(!inQ[nxt.ff]) {
					cnt[nxt.ff]++;
					if(cnt[nxt.ff] == n) {
						cout << -1 << '\n';
						return 0;
					}
					inQ[nxt.ff] = 1;
					q.push(nxt.ff);
				}
			}
		}
	}
	for(int i=1 ; i<n ; i++) {
		if(dis[i] == LLINF) dis[i] = -1;
		cout << dis[i] << '\n';
	}
}