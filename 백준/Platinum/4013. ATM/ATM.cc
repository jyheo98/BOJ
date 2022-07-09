#include <bits/stdc++.h>
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
const ll MOD = 1e9 + 7;
const long double PI = acos(-1.0);

#define int ll

int32_t main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int n, m; cin >> n >> m;
	vector<vector<int>> G(n);
	vector<vector<int>> rG(n);
	for(int i=0 ; i<m ; i++) {
		int u, v; cin >> u >> v; u--, v--;
		G[u].push_back(v);
		rG[v].push_back(u);
	}
	vector<bool> vis(n);
	stack<int> st;
	function<void(int, int)> dfs = [&](int v, int p) {
		vis[v] = 1;
		for(int nxt : G[v]) {
			if(nxt == p || vis[nxt])
				continue;
			dfs(nxt, v);
		}
		st.push(v);
	};	
	
	for(int i=0 ; i<n ; i++) {
		if(vis[i])
			continue;
		dfs(i,-1);	
	}
	
	vis = vector<bool>(n);
	vector<vector<int>> scc;	
	int cnt = 0;
	vector<int> num(n);
	function<void(int, int)> dfs2 = [&](int v, int p) {
		vis[v] = 1;
		num[v] = cnt;
		scc[cnt].push_back(v);
		for(int nxt : rG[v]) {
			if(nxt == p || vis[nxt])
				continue;
			dfs2(nxt, v);
		}
	};
	
	for(int i=0 ; i<n ; i++) {
		int cur = st.top(); st.pop();
		if(vis[cur]) 
			continue;
		scc.push_back(vector<int>{});
		dfs2(cur, -1);
		cnt ++;
	}

	vector<ll> val(n);
	for(int i=0 ; i<n ; i++) {
		cin >> val[i];
	}
	vector<ll> sccval(cnt);
	vector<bool> good(cnt);
	vector<vector<int>> sccg(cnt);
	for(int i=0 ; i<n ; i++) {
		sccval[num[i]] += val[i];
		for(int nxt : G[i]) {
			if(num[nxt] != num[i]) {
				sccg[num[i]].push_back(num[nxt]);
			}
		}
	}
	int s; cin >> s; s--; s = num[s];
	vector<int> deg(cnt);
	for(int i=0 ; i<cnt ; i++) {
		uniq(sccg[i]);
	}
	vector<ll> dp(cnt);
	queue<int> q;
	dp[s] = sccval[s];
	q.push(s);
	ll mx = 0;
	while(sz(q)) {
		int cur = q.front(); q.pop();
		for(int nxt : sccg[cur]) {
			if(dp[nxt] < dp[cur] + sccval[nxt]) {
				dp[nxt] = dp[cur] + sccval[nxt];
				q.push(nxt);
			}
		}
	}
	int qq; cin >> qq;
	while(qq--) {
		int x; cin >> x; x--; x = num[x];
		good[x] = 1;
	}
	for(int i=0 ; i<cnt ; i++) {
		if(good[i]) mx = max(mx, dp[i]);
	}
	cout << mx << '\n';
}