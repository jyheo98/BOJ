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

vector<ll> a;

class SegmentTree{
public:
    vector<ll> seg,lazy;
    int n;
    
    SegmentTree(int n) {
        seg.resize(4 * n + 5);
        lazy.resize(4 * n + 5);
        this->n=n;
    }

    void init(int idx, int tl, int tr) {
    	if(tl == tr) {
    		seg[idx] = a[tl];
    		return;
    	}
    	int mid = (tl + tr) / 2;
    	init(idx * 2, tl, mid);
    	init(idx * 2 + 1, mid + 1, tr);
    	seg[idx] = seg[idx * 2] + seg[idx * 2 + 1];
    }

    void propagate(int tl, int tr, int pos) {
        if(lazy[pos] != 0){
            seg[pos] += lazy[pos] * (tr - tl + 1);
            if(tl != tr){
                lazy[pos*2] += lazy[pos];
                lazy[pos*2+1] += lazy[pos];
            }
            lazy[pos] = 0;
        }
    }
    
    void update_(int tl, int tr, int l, int r, int pos, ll value) {
        propagate(tl, tr, pos);
        if(r < tl || tr < l) return;
        if(l <= tl && tr <= r){
            lazy[pos] += value;
            propagate(tl, tr, pos);
            return;
        }
        int mid = (tl + tr) / 2;
        update_(tl, mid, l, r, pos*2, value);
        update_(mid+1, tr, l, r, pos*2+1, value);
        seg[pos] = seg[pos*2] + seg[pos*2+1];
    }
    
    ll calc_(int tl, int tr, int l, int r, int pos) {
        propagate(tl, tr, pos);
        if(r < tl || tr < l) return 0;
        if(l <= tl && tr <= r) return seg[pos];
        int mid = (tl + tr) / 2;
        return calc_(tl, mid, l, r, pos * 2) + calc_(mid + 1, tr, l, r, pos * 2 + 1);
    }
    
    void upd(int s, int e, ll value) {
        update_(0, n-1, s, e, 1, value);
    }
    
    ll calc(int s, int e) {
        return calc_(0, n-1, s, e, 1);
    }
};

int main() {
	IOS;
	int n, m, k; cin >> n >> m >> k;
	a = vector<ll>(n);
	for(int i=0 ; i<n ; i++)
		cin >> a[i];
	m += k;
	SegmentTree st(n);
	st.init(1, 0, n-1);
	while(m--) {
		int qq; cin >> qq;
		if(qq == 1) {
			int l, r; cin >> l >> r; l--, r--;
			ll val; cin >> val;
			st.upd(l, r, val);
		} else {
			int l, r; cin >> l >> r; l--, r--;
			cout << st.calc(l, r) << '\n';
		}
	}
}