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
	map<int, string> mp;
	while(n--) {
		string s, t; cin >> s >> t;
		int cup = 0;
		if(s[0] >= 'a' && s[0] <= 'z') {
			int cur = 0;
			for(int i=0 ; i<sz(t) ; i++) {
				cur *= 10;
				cur += t[i] - '0';
			}
			mp[cur] = s;
		}
		else {
			int cur = 0;
			for(int i=0 ; i<sz(s) ; i++) {
				cur *= 10;
				cur += s[i] - '0';
			}
			cup = cur / 2;
			mp[cup]=t;
		}
	}
	for(auto x : mp) {
		cout << x.ss << '\n';
	}
}