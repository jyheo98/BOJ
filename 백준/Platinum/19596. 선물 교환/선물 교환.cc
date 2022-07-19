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

int n, m;
vector<vector<int>> g;
vector<int> deg;
struct edge {
	int u, v;
	bool visit;
	int id;
};
vector<edge> a;
vector<int> ans;

void dfs(int v) {
	while(sz(g[v])) {
		int nxt = g[v].back();
		if(a[nxt].visit == 0) {
			if(a[nxt].u == v) {
				if(a[nxt].id != -1) {
					ans[a[nxt].id] = 1;
				}
			}
			a[nxt].visit = 1;
			dfs(a[nxt].u+a[nxt].v-v);
		} else {
			g[v].pop_back();
		}
	} 
}

void solve() {
	cin >> n >> m;
	g = vector<vector<int>>(n);
	a = vector<edge>(m);
	ans = vector<int>(m);
	deg = vector<int>(n);
	for(int i=0 ; i<m ; i++) {
		int u, v; cin >> u >> v; u--, v--;
		a[i] = {u,v,0,i};
		g[u].push_back(i);
		g[v].push_back(i);
		deg[u]++;
		deg[v]++;
	}
	vector<int> hol;
	for(int i=0 ; i<n ; i++) {
		if(deg[i]&1) hol.push_back(i);
	}
	for(int i=0 ; i<sz(hol) ; i+=2) {
		a.push_back({hol[i],hol[i+1],0,-1});
		g[hol[i]].push_back(sz(a)-1);
		g[hol[i+1]].push_back(sz(a)-1);
	}
	for(int i=0 ; i<n ; i++) {
		dfs(i);
	}
	for(auto x : ans){
		cout << x;
	}
	cout << '\n';
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int t = 1; cin >> t;
	while(t--)
		solve();
}