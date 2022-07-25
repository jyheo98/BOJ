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
	vector<string> a(n);
	for(int i=0 ; i<n ; i++) cin >> a[i];
	pii s = {-1,-1}, e = {-1,-1};
	for(int i=0 ; i<n ; i++) {
		for(int j=0 ; j<m ; j++) if(i==0||j==0||i==n-1||j==m-1){
			if(a[i][j] == '.' && s.ff == -1) s = {i,j};
			else if(a[i][j] == '.') e = {i,j}; 
		}
	}
	queue<pii> q; q.push(s);
	vector<vector<int>> dis(n, vector<int>(m, -1));
	dis[s.ff][s.ss]=0;
	while(sz(q)) {
		pii cur = q.front(); q.pop();
		vector<int> dx = {1, -1, 0, 0}, dy = {0, 0, -1, 1};
		auto valid = [&](int x, int y) {
			return x >= 0 && x < n && y >= 0 && y < m && a[x][y] == '.';
		};
		for(int i=0 ; i<4 ; i++) {
			int nxtx = cur.ff + dx[i];
			int nxty = cur.ss + dy[i];
			if(valid(nxtx,nxty) && dis[nxtx][nxty]==-1) {
				dis[nxtx][nxty] = dis[cur.ff][cur.ss] + 1;
				q.push({nxtx,nxty});
			}
		}
	}
	pii cur = e;
	while(dis[cur.ff][cur.ss]) {
		a[cur.ff][cur.ss] = '@';
		vector<int> dx = {1, -1, 0, 0}, dy = {0, 0, -1, 1};
		auto valid = [&](int x, int y) {
			return x >= 0 && x < n && y >= 0 && y < m;
		};
		for(int i=0 ; i<4 ; i++) {
			int nxtx = cur.ff + dx[i];
			int nxty = cur.ss + dy[i];
			if(valid(nxtx,nxty) && dis[nxtx][nxty]==dis[cur.ff][cur.ss]-1) {
				cur={nxtx,nxty};
				break;
			}
		}
	}
	a[cur.ff][cur.ss]='@';
	for(auto& x : a) {
		for(auto& y : x) {
			if(y=='@') y='.';
			else if(y=='.') y='@';
		}
		cout<<x<<'\n';
	} 
}