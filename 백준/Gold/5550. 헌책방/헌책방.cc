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

int n, k;
ll dp[2005][2005];
vector<vector<ll>> a(10);

ll dfs(int curBook, int curPicked) {
	if(curBook == 10) {
		return (curPicked == k) ? 0 : -INF;
	}
	ll& ret = dp[curBook][curPicked];
	if(ret != -1) return ret;
	ret = dfs(curBook+1, curPicked);
	for(ll i=0 ; i<sz(a[curBook]) ; i++) if(curPicked+i+1 <= k) {
		ret = max(ret, a[curBook][i] + dfs(curBook+1, curPicked+i+1) + i*(i+1));
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);\
	for(int i=0 ; i<2005 ; i++) {
		for(int j=0 ; j<2005 ; j++) {
			dp[i][j] = -1;
		}
	}
	cin >> n >> k;
	for(int i=0 ; i<n ; i++) {
		ll price; int id;
		cin >> price >> id; id--;
		a[id].push_back(price);
	}
	for(int i=0 ; i<10 ; i++) {
		sort(a[i].rbegin(),a[i].rend());
		for(int j=1 ; j<sz(a[i]) ; j++) {
			a[i][j] += a[i][j-1]; 
		}
	}
	cout << dfs(0, 0) << '\n'; 
}