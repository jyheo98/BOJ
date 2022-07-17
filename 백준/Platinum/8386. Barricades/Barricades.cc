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

int n;
vector<vector<int>> g;
vector<vector<int>> dp;
vector<int> siz;

void dfs1(int v, int p) {
	siz[v] = 1;
	for(int nxt : g[v]) if(nxt != p) {
		dfs1(nxt, v);
		siz[v] += siz[nxt];
	}
}

void dfs(int v, int p) {
	for(int nxt : g[v]) if(nxt != p) {
		dfs(nxt, v);
	} 
	int cursz = 0;
	vector<int> dp2(n+1), dp3(n+1,INF);
	for(int nxt : g[v]) if(nxt != p) {
		for(int nxtsiz=0 ; nxtsiz<=siz[v] ; nxtsiz++) {
			int cost = 1;
			if(nxtsiz) cost = dp[nxt][nxtsiz];
			for(int cursiz=0 ; cursiz<=cursz ; cursiz++) {
				dp3[cursiz+nxtsiz]=min(dp3[cursiz+nxtsiz], dp2[cursiz]+cost);
			}
		}
		cursz+=siz[nxt];
		for(int i=0 ; i<=cursz ; i++) dp2[i]=dp3[i], dp3[i]=INF;
	} 
	for(int i=0 ; i<=cursz ; i++) dp[v][i+1]=dp2[i];
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n;
	g = vector<vector<int>>(n);
	siz = vector<int>(n);
	dp = vector<vector<int>>(n, vector<int>(n+1, INF));
	for(int i=0 ; i<n-1 ; i++) {
		int u, v; cin >> u >> v; u--, v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs1(0, -1);
	dfs(0, -1);
	vector<int> ans(n+1, INF);
	for(int i=1 ; i<=n ; i++) {
		for(int j=0 ; j<n ; j++) {
			ans[i] = min(ans[i], dp[j][i] + (j!=0));
		}
	}
	int q; cin >> q;
	while(q--) {
		int u; cin >> u; 
		cout << ans[u] << '\n';
	}
}