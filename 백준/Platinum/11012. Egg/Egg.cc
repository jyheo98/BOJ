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



class PST {
public:
	struct Node {
		int l, r; 
		ll v;
		Node() {
			l = -1, r = -1;
			v = 0LL;
		}
	};
	vector<Node> seg;
	int query_no, siz;
	void build(int id, int l, int r) {
		if(l == r) {
			return;
		}
		seg[id].l = sz(seg); seg.emplace_back(Node());
		seg[id].r = sz(seg); seg.emplace_back(Node());
		int mid = (l + r) / 2;
		build(seg[id].l, l, mid);
		build(seg[id].r, mid+1, r);
	} 
	PST(int query_no, int siz) {
		this->query_no = query_no;
		this->siz = siz;
		seg.resize(query_no + 5);
		build(0, 0, siz);
	}
	void update(int old, int cur, int l, int r, int idx, ll val) {
		seg[cur] = seg[old];
		if(l == r) {
			seg[cur].v = seg[old].v + val;
			return;
		}
		int mid = (l + r) / 2;
		if(idx <= mid) {
			seg[cur].l = sz(seg); seg.emplace_back(Node());
			update(seg[old].l, seg[cur].l, l, mid, idx, val);
		} else {
			seg[cur].r = sz(seg); seg.emplace_back(Node());
			update(seg[old].r, seg[cur].r, mid+1, r, idx, val);
		}
		seg[cur].v = seg[seg[cur].l].v + seg[seg[cur].r].v;
	} 
	ll calc(int id, int l, int r, int tl, int tr) {
		if(tr < l || tl > r) return 0LL;
		else if(tl <= l && r <= tr) return seg[id].v;
		int mid = (l + r) / 2;
		return calc(seg[id].l, l, mid, tl, tr) +
				calc(seg[id].r, mid+1, r, tl, tr);
	}
	void update(int old, int cur, int idx, int val) {
		update(old, cur, 0, siz, idx, val);
	}
	ll calc(int id, int l, int r) {
		return calc(id, 0, siz, l, r);
	}
};

bool cmp(pii a, pii b) {
	return a.ff < b.ff;
}

void solve() {
	int n, m; cin >> n >> m;
	PST st(n, 1e5+1);
	vector<pii> query;
	for(int i=0 ; i<n ; i++) {
		int x, y; cin >> x >> y;
		query.push_back({x, y});
	}
	sort(all(query), cmp);
	int qno = 1;
	vector<int> lookup(1e5+1);
	for(int i=0 ; i<=1e5 ; i++) {
		while(qno-1<n&&query[qno-1].ff == i) {
			st.update(qno-1,qno,query[qno-1].ss,1);
			qno++;
		}
		lookup[i] = qno-1;
	}
	ll ans = 0;
	while(m--) {
		int l, r, b, t; cin >> l >> r >> b >> t;
		ans += st.calc(lookup[r],b,t)-st.calc(lookup[l-1],b,t);
	}
	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int T; cin >> T;
	while(T--) {
		solve();
	} 
}