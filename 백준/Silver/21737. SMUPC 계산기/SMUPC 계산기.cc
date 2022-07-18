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
	int n; cin >> n;
	string s; cin >> s;
	ll ans = 0, cur = 0;
	n=sz(s);
	int curOp = 0;
	bool flag = 0;
	for(int i=0 ; i<n ; i++) {
		if(s[i] >= '0' && s[i] <= '9') {
			cur *= 10;
			cur += s[i] - '0';
		} else {
			if(curOp == 0) {
				ans += cur;
				cur = 0;
			} else if(curOp == 1) {
				ans -= cur;
				cur = 0;
			} else if(curOp == 2) {
				ans *= cur;
				cur = 0;
			} else if(curOp == 3) {
				assert(cur);
				ans /= cur;
				cur = 0;
			}
			if(s[i] == 'S') {
				curOp = 1;
			} else if(s[i] == 'M') {
				curOp = 2;
			} else if(s[i] == 'U') {
				curOp = 3;
			} else if(s[i] == 'P') {
				curOp = 0;
			} else if(s[i] == 'C') {
				curOp = 0;
				flag = 1;
				cout << ans << ' ';
			}
		}
	}
	if(!flag) {
		cout << "NO OUTPUT\n";
	}
}