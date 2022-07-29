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

ll n;
int dp[63][2];
int dfs(int d, int up) {
	if(n<(1LL<<d)&&up) return -INF;
	if(n<(1LL<<d)) return 0;
	int& ret = dp[d][up];
	if(ret!=-1) return ret;
	int curDig = !!((1LL<<d)&n);
	ret = 0;
	if(curDig == up) {
		ret = max(ret, dfs(d+1,1)+2);
		ret = max(ret, dfs(d+1,0));
	} else if(curDig == 0 && up == 1) {
		ret = dfs(d+1,1)+1;
	} else if(curDig == 1 && up == 0) {
		ret = dfs(d+1,0)+1;
	} else assert(false);
	return ret;
}

void solve() {
	cin >> n;
	for(int i=0 ; i<63 ; i++) for(int j=0 ; j<2 ; j++) dp[i][j] = -1;
	cout << dfs(0,0) << '\n';
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int t = 1; cin >> t;
	for(int i=1 ; i<=t ; i++) {
		cout << "Case #" << i << ": ";
		solve();
	}
}