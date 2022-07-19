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
	vector<pii> a(m);
	for(int i=0 ; i<m ; i++) {
		cin >> a[i].ff >> a[i].ss;
	}
	int s, e; cin >> s >> e;
	queue<int> q;
	vector<int> vis(m), dis(m, INF);
	vector<bool> en(m);
	for(int i=0 ; i<m ; i++) {
		int cur = a[i].ff;
		while(1) {
			if(cur == s) {
				q.push(i);
				vis[i] = 1;
				dis[i] = 1;
			} else if(cur == e) {
				en[i] = 1;
			} else if(cur > n) break;
			cur += a[i].ss;
		}
	}
	vector<vector<int>> g(m);
	for(int i=0 ; i<m ; i++) {
		for(int j=i+1 ; j<m ; j++) {
			int cl = a[i].ff;
			int cr = a[j].ff;
			int dl = a[i].ss;
			int dr = a[j].ss;
			bool good = false;
			while(1) {
				if(cl == cr) {
					good = true;
					break;
				}
				if(cl < cr) cl += dl;
				else cr += dr;
				if(cl > n || cr > n) break;
			}
			if(good) {
				g[i].push_back(j);
				g[j].push_back(i);
			}
		}
	}
	vector<int> prev(m, -1);
	while(sz(q)) {
		int cur = q.front(); q.pop();
		for(int nxt : g[cur]) if(vis[nxt] == 0) {
			vis[nxt] = 1;
			dis[nxt] = dis[cur] + 1;
			prev[nxt] = cur;
			q.push(nxt); 
		}
	}
	int ans = INF, ansid = -1;
	for(int i=0 ; i<m ; i++) if(en[i]) {
		if(ans > dis[i]) {
			ans = dis[i];
			ansid = i;
		}
	}
	if(ans == INF) {
		cout << -1 << '\n';
		return 0;
	}
	cout << ans << '\n';
	vector<int> ansids;
	while(1) {
		if(ansid == -1) break;
		ansids.push_back(ansid);
		ansid = prev[ansid];
	}
	reverse(all(ansids));
	for(auto x : ansids) {
		cout << x + 1 << '\n';
	}

}