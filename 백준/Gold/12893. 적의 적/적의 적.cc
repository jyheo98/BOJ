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

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int n, m; cin >> n >> m;
	vector<vector<int>> g(n);
	for(int i=0 ; i<m ; i++) {
		int u, v; cin >> u >> v; u--, v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	bool good = 1;
	vector<int> vis(n, -1);
	for(int i=0 ; i<n ; i++) {
		if(vis[i] == -1) {
			vis[i] = 0;
			queue<int> q; q.push(i);
			while(sz(q)) {
				int cur = q.front(); q.pop();
				for(int nxt : g[cur]) {
					if(vis[nxt] == -1) {
						vis[nxt] = (vis[cur] ^ 1);
						q.push(nxt);
					} else if(vis[nxt] == vis[cur]) {
						good = 0;
					}
				}
			}
		} 
	}
	cout<<(int)good<<'\n';
}