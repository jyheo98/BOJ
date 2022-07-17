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

class SegmentTree {
public:
	vector<ll> seg;
	int n;
	SegmentTree(int n) {
		seg.resize(4 * n + 5);
		this->n = n;
	}
	ll upd_(int idx, int l, int r, int pos, ll val) {
		if (pos < l || pos > r) return seg[idx];
		if (pos == l && pos == r) return seg[idx] = val;
		int mid = (l + r) / 2;
		return seg[idx] = max(
			upd_(idx * 2, l, mid, pos, val),
			upd_(idx * 2 + 1, mid + 1, r, pos, val)
			);
	}
	ll calc_(int idx, int l, int r, int tl, int tr) {
		if (tl > tr) return -LLINF;
		if (tl == l && tr == r) return seg[idx];
		int mid = (l + r) / 2;
		return max(
			calc_(idx * 2, l, mid, tl, min(tr, mid)),
			calc_(idx * 2 + 1, mid + 1, r, max(mid + 1, tl), tr)
			);
	}
	void upd(int pos, ll val) {
		upd_(1, 0, n - 1, pos, val);
	}
	ll calc(int l, int r) {
		return calc_(1, 0, n - 1, l, r);
	}
};

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int n, t; cin >> n >> t;
	vector<int> nums;
	vector<int> a(n);
	vector<int> q(t);
	for(int i=0 ; i<n ; i++) {
		cin >> a[i];
		nums.push_back(a[i]);
	}
	
	sort(all(nums));
	vector<int> idx(n);
	for(int i=0 ; i<n ; i++) {
		idx[lower_bound(all(nums), a[i]) - nums.begin()] = i;
	}
	SegmentTree st(n);
	stack<pii> sta;
	vector<int> ans(n);
	for(int i=n-1 ; i>=0 ; i--) {
		while(!sta.empty() && sta.top().ss < a[i]) {
			sta.pop();
		}
		int eidx = n;
		if(sz(sta)) eidx = sta.top().ff;
		sta.push({i,a[i]});
		ans[i] = st.calc(i, eidx-1) + 1;
		st.upd(i, ans[i]);
	}
	int curMax = 0;
	for(int i=0 ; i<n ; i++) {
		ans[idx[i]] = max(ans[idx[i]], curMax);
		curMax = max(curMax, ans[idx[i]]);
	}
	for(int i=0 ; i<t ; i++) {
		cin >> q[i];
		int id = lower_bound(all(nums), q[i]) - nums.begin();
		if(id == 0) cout << 0 << '\n';
		else cout << ans[idx[id-1]] << ' ';
	}
}