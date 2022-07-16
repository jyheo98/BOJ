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
	ll op(ll a, ll b) {
		return a ^ b;
	}
	ll upd_(int idx, int l, int r, int pos, ll val) {
		if (pos < l || pos > r) return seg[idx];
		if (pos == l && pos == r) return seg[idx] ^= val;
		int mid = (l + r) / 2;
		return seg[idx] = op(upd_(idx * 2, l, mid, pos, val),
				upd_(idx * 2 + 1, mid + 1, r, pos, val));
	}
	ll calc_(int idx, int l, int r, int tl, int tr, int x) {
		int len = r - l + 1;
		if(len & x) idx ^= 1;
		if (tl > tr) return 0;
		if (tl == l && tr == r) return seg[idx];
		int mid = (l + r) / 2;
		return op(calc_(idx * 2, l, mid, tl, min(tr, mid), x),
			calc_(idx * 2 + 1, mid + 1, r, max(mid + 1, tl), tr, x));
	}
	void upd(int pos, ll val) {
		upd_(1, 0, n - 1, pos, val);
	}
	ll calc(int l, int r, int x) {
		return calc_(1, 0, n - 1, l, r, x);
	} 
};

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int n; cin >> n;
	vector<ll> a(n);
	SegmentTree st(1<<20);
	for(int i=0 ; i<n ; i++) {
		cin >> a[i];
		st.upd(i, a[i]);
	}
	int q; cin >> q;
	while(q--) {
		int op; cin >> op;
		if(op == 1) {
			int l, r, x; cin >> l >> r >> x; 
			cout << st.calc(l,r,x) << '\n';
		} else {
			int l, x; cin >> l >> x; 
			st.upd(l,x);
		}
	}
}