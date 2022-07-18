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
	ll s, t; cin >> s >> t;
	if(s==t) {
		cout << 0 << '\n';
		return 0;
	}
	map<ll, string> mp;
	mp[s] = "";
	queue<ll> q; q.push(s);
	while(sz(q)) {
		ll cur = q.front(); q.pop();
		if(cur > 1e9) continue;
		if(cur == t) {
			cout << mp[cur] << '\n';
			return 0;
		}
		if(cur > 1e9) break;
		if(!mp.count(cur*cur)) {
			mp[cur*cur]=mp[cur]+"*";
			q.push(cur*cur);
		}
		if(!mp.count(cur+cur)) {
			mp[cur+cur]=mp[cur]+"+";
			q.push(cur*2);
		}
		if(!mp.count(1)) {
			mp[1]=mp[cur]+"/";
			q.push(1);
		}
	}
	cout << -1 << '\n';
}