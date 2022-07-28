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
	ll n; cin >> n;
	int mod = 2;
	vector<int> a;
	while(n) {
		a.push_back(n%mod);
		n /= mod;
		mod++;
	}
	vector<int> cnt(25);
	for(int i=0 ; i<sz(a) ; i++) {
		cnt[a[i]]++;
	}
	sort(all(a));
	ll ans = 1;
	for(int curMod=2,id=0 ; id<sz(a) ; id++,curMod++) {
		int canUse = 0;
		for(int j=0 ; j<curMod ; j++) {
			canUse += cnt[j];
		}
		canUse -= id;
		ans *= canUse;
	}
	for(int i=0 ; i<24 ; i++) if(cnt[i]) {
		for(int j=1 ; j<=cnt[i] ; j++) {
			ans /= j;
		}
	}
	if(cnt[0]) {
		cnt[0]--;
		reverse(all(a)); a.pop_back(); reverse(all(a));
		ll ans2 = 1;
		for(int curMod=2,id=0 ; id<sz(a) ; id++,curMod++) {
			int canUse = 0;
			for(int j=0 ; j<curMod ; j++) {
				canUse += cnt[j];
			}
			canUse -= id;
			ans2 *= canUse;
		}
		for(int i=0 ; i<24 ; i++) if(cnt[i]) {
			for(int j=1 ; j<=cnt[i] ; j++) {
				ans2 /= j;
			}
		}
		ans -= ans2;
	}
	cout << ans-1 << '\n';
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int t; cin >> t;
	while(t--) solve();
}