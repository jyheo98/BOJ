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
	int state = 0;
	for(int i=0 ; i<n ; i++) {
		int x; cin >> x;
		state += x*(1<<i);
	}
	vector<bool> vis(1<<20);
	vector<int> dis(1<<20, -1);
	vis[state] = 1;
	dis[state] = 0;
	vector<int> op(n);
	for(int i=0 ; i<n ; i++) {
		int k; cin >> k;
		op[i] |= (1<<i);
		for(int j=0 ; j<k ; j++) {
			int x; cin >> x; x--;
			op[i] |= (1<<x);
		}
	}
	queue<int> q; q.push(state);
	while(sz(q)) {
		int cur = q.front(); q.pop();
		for(int i=0 ; i<n ; i++) if(!(cur & (1<<i))) {
			if(vis[cur ^ op[i]] == 0) {
				vis[cur ^ op[i]] = 1;
				dis[cur ^ op[i]] = dis[cur] + 1;
				q.push(cur ^ op[i]);
			}
		}
	}
	cout << dis[(1<<n)-1] << '\n';
}