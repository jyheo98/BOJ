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
	ll C[500][500];
	for(int i=0 ; i<500 ; i++) {
		for(int j=0 ; j<=i ; j++) {
			if(i==j || j==0) C[i][j] = 1;
			else C[i][j] = (C[i-1][j] + C[i-1][j-1]) % MOD;
		}
	}
	int h, w; cin >> h >> w;
	vector<ll> dp(w+1), newdp(w+1);
	dp[1] = 1;
	for(int i=0 ; i<h ; i++) {
		for(int cur=1 ; cur<=w ; cur++) {
			for(int nxt=1 ; nxt<=w ; nxt++) {
				newdp[nxt] += dp[cur]*C[cur+nxt-1][nxt];
				newdp[nxt] %= MOD;
			}
		}
		dp=newdp;
		newdp=vector<ll>(w+1);
	}
	ll ans=0;
	for(int i=1 ; i<=w ; i++) {
		ans += dp[i];
		ans %= MOD;
	}
	cout<<ans<<'\n';
}