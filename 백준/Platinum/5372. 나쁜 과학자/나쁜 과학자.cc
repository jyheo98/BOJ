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

int n, k, m;
vector<pii> a;
vector<int> dead;
int dcnt = 0;
int ans=INF;

void dfs(int id) {
	if(id == m) {
		ans=min(ans,dcnt);
		return;
	}
	int fi = a[id].ff;
	int se = a[id].ss;
	if(dead[fi] || dead[se]) {
		dfs(id+1);
	} else {
		if(dcnt==k) return;
		dead[fi] = 1;
		dcnt++;
		dfs(id+1);
		dead[fi]=0;
		dead[se]=1;
		dfs(id+1);
		dead[se]=0;
		dcnt--;
	}
}

void solve() {
	cin >> n >> k;
	cin >> m;
	dead = vector<int>(n);
	dcnt = 0;
	ans=INF;
	a = vector<pii>(m);
	for(int i=0 ; i<m ; i++) {
		int u, v; cin >> u >> v; u--, v--;
		a[i] = {u, v};
	}
	dfs(0);
	if(ans==INF) cout<<"IMPOSSIBLE\n";
	else cout<<ans<<'\n';
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int T; cin >> T;
	while(T--) {
		solve();
	}
}