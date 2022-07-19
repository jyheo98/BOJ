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
	int n; cin >> n;
	vector<int> a(n);
	int tot = 0;
	for(int i=0 ; i<n ; i++) {
		int x; cin >> x; x--;
		a[i] = (1<<x);
		tot |= (1<<x);
	}
	vector<vector<int>> G(n);
	for(int i=0 ; i<n-1 ; i++) {
		int u, v; cin >> u >> v; u--, v--;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	vector<vector<int>> par(n, vector<int>(21));
	vector<vector<int>> val(n, vector<int>(21));
	vector<int> dep(n);
	function<void(int, int, int)> dfs = [&](int v, int d, int p) {
		par[v][0] = p;
		val[v][0] = a[v];
		dep[v] = d;
		for(int nxt : G[v]) {
			if(nxt == p) continue;
			dfs(nxt, d+1, v);
		}
	};
	dfs(0,0,0);
	for(int x=1 ; x<21 ; x++) {
		for(int v=0 ; v<n ; v++) {
			par[v][x] = par[par[v][x-1]][x-1];
			val[v][x] = (val[v][x-1] | val[par[v][x-1]][x-1]);
		}
	}
	function<int(int, int)> LCA = [&](int x, int y) {
		int vv = 0;
		if(dep[x] > dep[y]) 
			swap(x,y);
		for(int i=20 ; i>=0 ; i--) {
			if(dep[y]-dep[x] >= pw(i)) {
				vv |= val[y][i];
				y = par[y][i];
			}
		}
		if(x==y)
			return (vv | a[x]);
		for(int i=20 ; i>=0 ; i--) {
			if(par[x][i] != par[y][i]) {
				vv |= val[x][i];
				x = par[x][i];
				vv |= val[y][i];
				y = par[y][i];
			}
		}
		vv |= a[x];
		vv |= a[y];
		vv |= a[par[x][0]];
		return vv;
	};
	int q; cin >> q;
	bool fi = true;
	int prevst = -1;
	while(q--) {
		int u, v; cin >> u >> v; u--, v--;
		if(fi) {
			if(tot & (1<<v)) {
				cout << "PLAY\n";
			} else {
				cout << "CRY\n";
			}
			fi = false;
			prevst = u;
		} else {
			if(LCA(prevst, u) & (1<<v)) {
				cout << "PLAY\n";
			} else {
				cout << "CRY\n";
			}
			prevst = u;
		}
	}
}