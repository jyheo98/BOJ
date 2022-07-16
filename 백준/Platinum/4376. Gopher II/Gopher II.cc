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
	int n, m; 
	ld s, v;
	while(cin >> n >> m >> s >> v) {
		vector<pair<ld, ld>> a(n), b(m);
		for(int i=0 ; i<n ; i++) {
			cin >> a[i].ff >> a[i].ss;
		}
		for(int i=0 ; i<m ; i++) {
			cin >> b[i].ff >> b[i].ss;
		}
		vector<vector<int>> g(n);
		for(int i=0 ; i<n ; i++) {
			for(int j=0 ; j<m ; j++) {
				if((a[i].ff-b[j].ff)*(a[i].ff-b[j].ff)+(a[i].ss-b[j].ss)*(a[i].ss-b[j].ss)<=v*s*v*s) {
					g[i].push_back(j);
				}
			}
		}
		int match = 0;
		vector<bool> vis;
		vector<int> mat(m, -1);
		function<bool(int)> dfs = [&](int v) -> bool {
			if(vis[v]) return false;
			vis[v] = 1;
			for(int nxt : g[v]) {
				if(mat[nxt] == -1 || dfs(mat[nxt])) {
					mat[nxt] = v;
					return true;
				}
			}
			return false;
		};
		for(int i=0 ; i<n ; i++) {
			vis = vector<bool>(n);
			if(dfs(i)) {
				match++;
			}
		}
		cout << n-match << '\n';
		debug(match);
	}
}