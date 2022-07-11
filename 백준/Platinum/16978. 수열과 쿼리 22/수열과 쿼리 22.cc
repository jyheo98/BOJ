#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(false);cin.tie(0)
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
		return seg[idx] = upd_(idx * 2, l, mid, pos, val) +
				upd_(idx * 2 + 1, mid + 1, r, pos, val);
	}
	ll calc_(int idx, int l, int r, int tl, int tr) {
		if (tl > tr) return 0;
		if (tl == l && tr == r) return seg[idx];
		int mid = (l + r) / 2;
		return calc_(idx * 2, l, mid, tl, min(tr, mid)) +
			calc_(idx * 2 + 1, mid + 1, r, max(mid + 1, tl), tr);
	}
	ll find_(int idx, int l, int r, ll rank) {
		if(l==r) return l;
		int mid = (l+r)/2;
		if(seg[idx*2]>=rank) return find_(idx*2,l,mid,rank);
		else return find_(idx*2+1,mid+1,r,rank-seg[idx*2]); 
	}
	void upd(int pos, ll val) {
		upd_(1, 0, n - 1, pos, val);
	}
	ll calc(int l, int r) {
		return calc_(1, 0, n - 1, l, r);
	} 
	ll find(ll rank) {
		return find_(1, 0, n-1, rank);
	}
};

bool cmp(pair<pii, pii> a, pair<pii, pii> b) {
	return a.ff.ss < b.ff.ss;
}

int main() {
	IOS;
	int n; cin >> n;
	SegmentTree st(n);
	for(int i=0 ; i<n ; i++) {
		int x; cin >> x; st.upd(i,x);
	}
	int q; cin >> q;
	vector<pair<int, ll>> q1; 
	vector<pair<pii, pii>> q2;
	int cnt = 0;	
	while(q--) {
		int qu; cin >> qu;
		if(qu == 1) {
			int idx; ll x; cin >> idx >> x; idx--;
			q1.push_back({idx,x});
		} else {
			int k, l, r; cin >> k >> l >> r; l-- ,r--;
			q2.push_back({{cnt,k},{l,r}});
			cnt++;
		}
	}
	sort(q2.begin(),q2.end(),cmp);
	vector<ll> ans(sz(q2));
	int querys = 0;
	for(int i=0 ; i<sz(q2) ; i++) {
		int ansIdx = q2[i].ff.ff;
		int no = q2[i].ff.ss;
		while(querys < no) {
			st.upd(q1[querys].ff, q1[querys].ss);
			querys++;
		}
		ans[ansIdx] = st.calc(q2[i].ss.ff, q2[i].ss.ss);
	}
	for(auto x : ans) cout << x << "\n";
}