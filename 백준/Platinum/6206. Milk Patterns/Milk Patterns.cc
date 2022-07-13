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

int n, k;
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
		return seg[idx] = min(
			upd_(idx * 2, l, mid, pos, val),
			upd_(idx * 2 + 1, mid + 1, r, pos, val)
			);
	}
	ll calc_(int idx, int l, int r, int tl, int tr) {
		if (tl > tr) return LLINF;
		if (tl == l && tr == r) return seg[idx];
		int mid = (l + r) / 2;
		return min(
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

void make_sa(vector<int> &s) {
	int n = sz(s);
	vector<int> isa(n);
	vector<int> nums;
	for(int i=0 ; i<n ; i++) {
		isa[i] = s[i];
		nums.push_back(isa[i]);
	}
	uniq(nums);
	for(int i=0 ; i<n ; i++) {
		isa[i] = lower_bound(all(nums), isa[i]) - nums.begin();
	}
	if(sz(nums) != n) {
		for(int d=1 ; ; d*=2) {
			vector<pii> pairs;
			for(int i=0 ; i<n ; i++) {
				int nextnum = -1;
				if(i+d < n) nextnum = isa[i+d];
				pii curPair = {isa[i], nextnum};
				pairs.push_back(curPair);
			}
			uniq(pairs);
			for(int i=0 ; i<n ; i++) {
				int nextnum = -1;
				if(i+d < n) nextnum = isa[i+d];
				pii curPair = {isa[i], nextnum};
				int idx = lower_bound(all(pairs), curPair) - pairs.begin();
				isa[i] = idx;
			}
			if(sz(pairs) == n) {
				break;
			}
		} 
	}
	vector<int> sa(n);
	for(int i=0 ; i<n ; i++) {
		sa[isa[i]] = i;
	}
	vector<int> lcp(n);
	for(int k=0, i=0 ; i<n ; i++) if(isa[i]) {
        for(int j=sa[isa[i]-1]; s[i+k]==s[j+k]; ++k);
        lcp[isa[i]] = (k ? k-- : 0);
    }
    SegmentTree st(n);
    for(int i=0 ; i<n ; i++) {
    	st.upd(i, lcp[i]);
    }
    ll ans = 0;
    for(int i=0 ; i+k-2<n ; i++) {
    	ans = max(ans, st.calc(i,i+k-2));
    }
    cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n >> k;
	vector<int> a(n);
	for(int i=0 ; i<n ; i++) {
		cin >> a[i];
	}
	make_sa(a);
}