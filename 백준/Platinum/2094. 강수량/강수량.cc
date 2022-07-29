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
		if(l>r) return -INF;
		return calc_(1, 0, n - 1, l, r);
	}
};

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int n; cin >> n;
	vector<int> years; set<int> st;
	vector<int> rains;
	SegmentTree rn(n);
	for(int i=0 ; i<n ; i++) {
		int y; cin >> y; 
		int r; cin >> r;
		years.push_back(y);
		rains.push_back(r);
		st.insert(y);
		rn.upd(i,r);
	}
	int q; cin >> q;
	while(q--) {
		int l, r; cin >> l >> r;
		if(st.count(l) && st.count(r)) {
			int lid = lower_bound(all(years),l)-years.begin();
			int rid = lower_bound(all(years),r)-years.begin();
			if(rn.calc(lid+1,rid-1)<rains[rid]&&rains[lid]>=rains[rid]) {
				if(rid-lid==r-l)
					cout<<"true\n";
				else 
					cout<<"maybe\n";
			} else {
				cout<<"false\n";
			}
		} else if(st.count(r)) {
			int lid = lower_bound(all(years),l)-years.begin();
			int rid = lower_bound(all(years),r)-years.begin();
			if(rn.calc(lid,rid-1)<rains[rid]) {
				cout<<"maybe\n";
			} else {
				cout<<"false\n";
			}
		} else if(st.count(l)) {
			int lid = lower_bound(all(years),l)-years.begin();
			int rid = lower_bound(all(years),r)-years.begin();
			if(rn.calc(lid+1,rid-1)<rains[lid]) {
				cout<<"maybe\n";
			} else {
				cout<<"false\n";
			}
		} else {
			cout<<"maybe\n";
		}
	}
}