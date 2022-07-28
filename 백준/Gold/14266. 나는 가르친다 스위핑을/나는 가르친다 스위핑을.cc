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

bool cmp(pair<pair<ll, ll>, int> a, pair<pair<ll, ll>, int> b) {
	if(a.ff.ss * b.ff.ff == b.ff.ss * a.ff.ff) return a.ss > b.ss;
	return a.ff.ss * b.ff.ff < b.ff.ss * a.ff.ff;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int n; cin >> n;
	vector<pair<pair<ll, ll>, int>> a;
	for(int i=0 ; i<n ; i++) {
		ll x, y; cin >> x >> y;
		ll x2, y2; cin >> x2 >> y2;
		if(y*x2 > y2*x) swap(x,x2),swap(y,y2);
		a.push_back({{x,y},1});
		a.push_back({{x2,y2},-1});
	}
	sort(all(a), cmp);
	int ans = 0, cur = 0;
	for(int i=0 ; i<sz(a) ; i++) {
		if(a[i].ss == 1) cur++;
		else cur--;
		ans=max(ans,cur);	
	}
	cout<<ans<<'\n';
}