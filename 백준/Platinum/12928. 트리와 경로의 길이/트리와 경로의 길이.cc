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

int n, s, vis[55][1005];
bool good = false;

void dfs(int leftNode, int cur) {
	if(vis[leftNode][cur]) return;
	vis[leftNode][cur] = 1;
	if(cur > s) return;
	if(leftNode == 0) {
		if(cur == s) good = true;
		return;
	}
	for(int i=1 ; i<=leftNode ; i++) {
		dfs(leftNode - i, cur + i*(i+1)/2);
	}
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n >> s;
	dfs(n-2, 0);
	cout << good << '\n';
}