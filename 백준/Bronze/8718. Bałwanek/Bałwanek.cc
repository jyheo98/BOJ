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
	ll a, b; cin >> a >> b;
	if(b*7 <= a) {
		cout << 1000*7*b << '\n';
	} else if(b+b*2+b*4<=a*2) {
		cout << 3500*b << '\n';
	} else if(b+b*2+b*4<=a*4) {
		cout << 1750*b << '\n';
	} else {
		cout << 0 << '\n';
	}
}