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
bool good[13][13];
ll dp[16][13];

ll dfs(int idx, int spec) {
	if(idx==n) return 1;
	ll& ret = dp[idx][spec];
	if(ret != -1) return ret;
	ret = 0;
	for(int nxt = 1 ; nxt <= k ; nxt++) if(!good[spec][nxt] && nxt != spec) {
		ret += dfs(idx+1, nxt);
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n >> k >> m;
	while(m--) {
		string s; cin >> s;
		for(int i=0 ; i<sz(s) ; i++) {
			for(int j=i+1 ; j<sz(s) ; j++) {
				good[s[i]-'A'+1][s[j]-'A'+1] = 1;
				good[s[j]-'A'+1][s[i]-'A'+1] = 1;
			}
		}
	}
	for(int i=0 ; i<16 ; i++) for(int j=0 ; j<13 ; j++) {
		dp[i][j] = -1;
	}
	cout << dfs(0,0) << '\n';
}