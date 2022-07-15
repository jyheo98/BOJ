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

int n;
vector<ll> a;
vector<ll> dp((1<<17)-1, -1);
vector<ll> canmask(17);
vector<int> ppc(1<<17);
vector<ll> fact(17);

ll dfs(int mask) {
	if(mask == (1<<n)-1) return 1;
	ll& ret = dp[mask];
	if(ret != -1) return ret;
	int fidx = -1;
	for(int i=0 ; i<n ; i++) {
		if(mask & (1<<i)) continue;
		fidx = i;
		break;	
	}
	ret = 0;
	int rmask = (1<<n)-1-mask;
	for(int i=1 ; i<=n ; i++) {
		if(a[fidx] % i) continue;
		int candomask = (rmask & canmask[i]);
		for(int j=candomask ; j; j=((j-1)&candomask)) {
			if(ppc[j] == i && ((1<<fidx) & j)) {
				ret += dfs(mask+j)*fact[i-1];
			}
		}
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n;
	a = vector<ll>(n);
	fact[0]=1;
	for(int i=1 ; i<17 ; i++) fact[i]=fact[i-1]*i;
	for(int i=1 ; i<(1<<17) ; i++) {
		ppc[i] = ppc[i/2] + (i&1);
	}
	for(int i=0 ; i<n ; i++) {
		cin >> a[i];
		for(int j=1 ; j<=n ; j++) {
			if(a[i] % j) continue;
			canmask[j] |= (1<<i); 
		}
	}
	cout << dfs(0);
}