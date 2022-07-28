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

#define int ll

void solve() {
	int n, k; cin >> n >> k;
	vector<ll> a(n);
	for(int i=0 ; i<n ; i++) cin >> a[i];
	vector<int> dp(k+1, INF);
	dp[0] = 0;
	int ans = INF;
	for(int i=n-1 ; i>=0 ; i--) {
		int cur = 0;
		for(int j=i ; j>=0 ; j--) {
			cur += a[j];
			if(cur <= k) {
				int z = i-j+1+dp[k-cur];
				ans=min(ans,z);
			}
		}
		cur = 0;
		for(int j=i ; j<n ; j++) {
			cur += a[j];
			if(cur <= k) {
				int z = j-i+1;
				dp[cur] = min(dp[cur], z);
			}
		}
	} 
	if(ans>=INF) cout<<-1<<'\n';
	else cout<<ans<<'\n'; 
}

int32_t main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int T; cin >> T;
	for(int t=1 ; t<=T ; t++) {
		cout << "Case #" << t << ": ";
		solve();
	}
}