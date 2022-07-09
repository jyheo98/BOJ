#include <bits/stdc++.h>
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
const ll MOD = 1e9 + 7;
const long double PI = acos(-1.0);

ll L, U; 
struct Node {
	ll p, q, fl, fu;
	ll calc(ll x) {
		if(x <= p) return fl;
		else if(x >= q) return fu;
		else return fl + x-p;
	}
};

class SegmentTree {
public:
	vector<Node> seg;
	int n;
	SegmentTree(int n) {
		seg.resize(4 * n + 5);
		this->n = n;
	}
	Node op(Node a, Node b) {
		if(b.p==-INF) return a;
		if(a.p==-INF) return b;
		Node ret;
		if(a.fu <= b.p) {
			ret.p = ret.q = L;
			ret.fl = ret.fu = b.fl;
		} else if(a.fl >= b.q) {
			ret.p = ret.q = U;
			ret.fl = ret.fu = b.fu;
		} else {
			ret.fl = b.calc(a.fl);
			ret.fu = b.calc(a.fu);
			ret.p = a.p;
			if(a.fl <= b.p && b.p <= a.fu) {
				ret.p = a.p + b.p - a.fl;
			}
			ret.q = a.q;
			if(a.fl <= b.q && b.q <= a.fu) {
				ret.q = a.q + b.q - a.fu;
			}
		}
		return ret;
	}
	Node upd_(int idx, int l, int r, int pos, ll val) {
		if (pos < l || pos > r) return seg[idx];
		if (pos == l && pos == r) {
			if(val == 0) {
				seg[idx] = {L, U, L, U};
			} else if(val > 0) {
				seg[idx] = {L, max(U-val,L), min(U,L+val), U};
			} else if(val < 0) {
				seg[idx] = {min(L-val,U), U, L, max(U+val,L)};
			}
			return seg[idx];
		}
		int mid = (l + r) / 2;
		return seg[idx] = op(upd_(idx * 2, l, mid, pos, val),
				upd_(idx * 2 + 1, mid + 1, r, pos, val));
	}
	Node calc_(int idx, int l, int r, int tl, int tr) {
		if (tl > tr) return {-INF,-INF,-INF,-INF};
		if (tl == l && tr == r) return seg[idx];
		int mid = (l + r) / 2;
		return op(calc_(idx * 2, l, mid, tl, min(tr, mid)),
			calc_(idx * 2 + 1, mid + 1, r, max(mid + 1, tl), tr));
	}
	void upd(int pos, ll val) {
		upd_(1, 0, n - 1, pos, val);
	}
	Node calc(int l, int r) {
		return calc_(1, 0, n - 1, l, r);
	} 
};

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int n; cin >> n;
	cin >> L >> U;
	SegmentTree st(n);
	for(int i=0 ; i<n ; i++) {
		ll x; cin >> x;
		st.upd(i, x);
	}
	int q; cin >> q;
	while(q--) {
		int l, r; cin >> l >> r; l--, r--;
		ll x; cin >> x;
		cout << st.calc(l,r).calc(x) << '\n';
	}
}