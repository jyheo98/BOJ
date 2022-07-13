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
	int n; cin>>n;
	set<string> st;
	for(int i=0 ; i<n ; i++) {
		string s; cin >> s;
		st.insert(s);
	}
	ll ans = 0;
	for(auto &s : st) {
		string t = s;
		for(auto &c : t) {
			if(c<='m') c+=13;
			else c-=13;
		}
		debug(t);
		ans += st.count(t);
	}
	cout << ans;
}