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

ll dp[55][55];
ll n, k; 
ll dfs(int id, int many) {
	ll& ret = dp[id][many];
	if(id == n) return (many == 0);
	if(ret != -1) return ret;
	ret = 0;
	if(many) ret = dfs(id+1, many-1) + dfs(id+1, many+1);
	else ret = dfs(id+1, many+1);
	return ret;
}

void construct(int id, int many, ll rank) {
	if(id == n) return;
	if(many) {
		if(dfs(id+1, many+1) >= rank) {
			cout << "(";
			construct(id+1, many+1, rank);
		} else {
			cout << ")";
			construct(id+1, many-1, rank-dfs(id+1, many+1));
		}
	} else {
		cout << "(";
		construct(id+1, many+1, rank);
	}
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n >> k;
	for(int i=0 ; i<55 ; i++) for(int j=0 ; j<55 ; j++) {
		dp[i][j] = -1;
	}
	k++;
	ll x = dfs(0,0);

	if(x < k) {
		cout << -1 << '\n';
		return 0;
	}
	construct(0,0,k);
}