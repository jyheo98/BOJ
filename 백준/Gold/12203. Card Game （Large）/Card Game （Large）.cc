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
	int n, k; cin >> n >> k;
	vector<int> a(n);
	for(int i=0 ; i<n ; i++) {
		cin >> a[i];
	}
	vector<vector<int>> dp(n, vector<int>(n, -1));
	function<int(int,int)> dfs = [&](int l, int r) -> int {
		if(l>r) return 0;
		int& ret = dp[l][r];
		if(ret != -1) return ret;
		if(r-l+1 <= 2) return ret = r-l+1;
		ret = INF;
		if(a[l]+k==a[l+1]&&a[l+1]+k==a[l+2]) {
			ret=min(ret,dfs(l+3,r));
		}
		if(a[r]-k==a[r-1]&&a[r-1]-k==a[r-2]) {
			ret=min(ret,dfs(l,r-3));
		}
		ret=min(ret,1+dfs(l+1,r));
		ret=min(ret,1+dfs(l,r-1));
		for(int i=l+1 ; i<=r-1 ; i++) {
			if(a[i]==a[l]+k&&a[r]==a[i]+k&&dfs(l+1,i-1)==0&&dfs(i+1,r-1)==0) {
				ret=0;
			}
		}
		for(int i=l ; i<=r-1 ; i++) {
			ret=min(ret,dfs(l,i)+dfs(i+1,r));
		}
		return ret;
	};
	cout << dfs(0, n-1) << '\n';
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int t = 1; cin >> t;
	for(int i=1 ; i<=t ; i++) {
		cout << "Case #" << i << ": ";
		solve();
	}
}