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

void solve() {
	int n; cin >> n;
	vector<pii> a(n);
	vector<int> xs, ys;
	for(int i=0 ; i<n ; i++) {
		cin >> a[i].ff >> a[i].ss;
		xs.push_back(a[i].ff);
		ys.push_back(a[i].ss);
	}
	uniq(xs);
	uniq(ys);
	vector<vector<int>> x(sz(xs)), y(sz(ys));
	for(int i=0 ; i<n ; i++) {
		a[i].ff = lower_bound(all(xs), a[i].ff) - xs.begin();
		a[i].ss = lower_bound(all(ys), a[i].ss) - ys.begin();
		x[a[i].ff].push_back(a[i].ss);
		y[a[i].ss].push_back(a[i].ff);
	}
	for(int i=0 ; i<sz(x) ; i++) {
		sort(all(x[i]));
		if(sz(x[i])%2==1) {
			cout << "NO\n";
			return;
		}
	}
	for(int i=0 ; i<sz(y) ; i++) {
		sort(all(y[i]));
		if(sz(y[i])%2==1) {
			cout << "NO\n";
			return;
		}
	}
	bool hor = 0;
	int cnt = 0;
	pii cur = a[0];
	set<pii> vis; vis.insert(cur);
	while(1) {
		if(hor == 0) {
			int id = lower_bound(all(x[cur.ff]), cur.ss) - x[cur.ff].begin();
			if(id % 2 == 0) {
				int newy = x[cur.ff][id+1];
				cur.ss = newy;
				
				if(vis.count(cur)) {
					break;
				} vis.insert(cur);
			} else {
				int newy = x[cur.ff][id-1];
				cur.ss = newy;
				
				if(vis.count(cur)) {
					break;
				} vis.insert(cur);
			}
		} else {
			int id = lower_bound(all(y[cur.ss]), cur.ff) - y[cur.ss].begin();
			if(id % 2 == 0) {
				int newx = y[cur.ss][id+1];
				cur.ff = newx;
				
				if(vis.count(cur)) {
					break;
				} vis.insert(cur);
			} else {
				int newx = y[cur.ss][id-1];
				cur.ff = newx;
				
				if(vis.count(cur)) {
					break;
				} vis.insert(cur);
			}	 
		}
		hor ^= 1;
	}
	if(sz(vis) != n) {
		cout << "NO\n";
		return;
	}
	vector<pair<int, pii>> xx;
	for(int i=0 ; i<sz(x) ; i++) {
		for(int j=0 ; j<sz(x[i]) ; j+=2) {
			xx.push_back({i,{x[i][j], x[i][j+1]}});
		}
	}
	vector<pair<int, pii>> yy;
	for(int i=0 ; i<sz(y) ; i++) {
		for(int j=0 ; j<sz(y[i]) ; j+=2) {
			yy.push_back({i,{y[i][j], y[i][j+1]}});
		}
	}
	int ans = 0;
	for(int i=0 ; i<sz(xx) ; i++) {
		int curx = xx[i].ff;
		int curL = xx[i].ss.ff, curR = xx[i].ss.ss;
		for(int j=0 ; j<sz(yy) ; j++) {
			if(curL <= yy[j].ff && yy[j].ff <= curR) {
				if(yy[j].ss.ff <= curx && curx <= yy[j].ss.ss) {
					ans++;
				}
			}
		}
	}
	for(int i=0 ; i<sz(yy) ; i++) {
		int curx =yy[i].ff;
		int curL = yy[i].ss.ff, curR = yy[i].ss.ss;
		for(int j=0 ; j<sz(xx) ; j++) {
			if(curL <= xx[j].ff && xx[j].ff <= curR) {
				if(xx[j].ss.ff <= curx && curx <= xx[j].ss.ss) {
					ans++;
				}
			}
		}
	}
	if(ans != n * 2) {
		cout << "NO\n";
	} else {
		cout << "YES\n";
	}
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int t = 1; cin >> t;
	while(t--)
		solve();
}