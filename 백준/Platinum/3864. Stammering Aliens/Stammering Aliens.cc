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

void make_sa(string &s, int d) {
	if(d==1) return;
	int n = sz(s), m = max(256, n) + 1;
	vector<int> sa(n), r(n+n), nr(n+n), cnt(m), idx(n);
    for(int i=0;i<n;++i) sa[i]=i, r[i]=s[i];
    for(int d=1;d<n;d<<=1){
        auto cmp = [&](int i,int j){
            return r[i]<r[j] || (r[i]==r[j] && r[i+d]<r[j+d]); };

        for(int i=0;i<m;++i) cnt[i] = 0;
        for(int i=0;i<n;++i) cnt[r[i+d]]++;
        for(int i=1;i<m;++i) cnt[i] += cnt[i-1];
        for(int i=n-1;~i;--i) idx[--cnt[r[i+d]]] = i;

        for(int i=0;i<m;++i) cnt[i] = 0;
        for(int i=0;i<n;++i) cnt[r[i]]++;
        for(int i=1;i<m;++i) cnt[i]+=cnt[i-1];
        for(int i=n-1;~i;--i) sa[--cnt[r[idx[i]]]] = idx[i];

        nr[sa[0]] = 1;
        for(int i=1;i<n;++i) nr[sa[i]] = nr[sa[i-1]] + cmp(sa[i-1], sa[i]);
        for(int i=0;i<n;++i) r[i] = nr[i];

        if(r[sa[n-1]]==n) break; // reduce running time
    }
    vector<int> isa(n);
    for(int i=0 ; i<n ; i++) {
    	isa[sa[i]] = i;
    }
	vector<int> lcp(n);
	ll ans = 0;
    for(int k=0, i=0 ; i<n ; i++) if(isa[i]) {
        for(int j=sa[isa[i]-1]; s[i+k]==s[j+k]; ++k);
        lcp[isa[i]] = (k ? k-- : 0);
    }
    SegmentTree st(n), st2(n);
    for(int i=0 ; i<n ; i++) {
    	st.upd(i, lcp[i]);
    	st2.upd(i, -sa[i]);
    }
    vector<vector<int>> sparse_table(n, vector<int>(25));
    for(int i=0 ; i<n ; i++) {
    	sparse_table[i][0] = lcp[i];
    }
    for(int pw=1 ; pw<25 ; pw++) {
    	for(int i=0 ; i+(1LL<<(pw-1))<n ; i++) {
    		sparse_table[i][pw] = min(sparse_table[i][pw-1], sparse_table[i+(1LL<<(pw-1))][pw-1]);
    	}
    }
    vector<int> log(n+1);
    log[1] = 0;
    for(int i=2 ; i<=n ; i++)
    	log[i] = log[i/2] + 1;
    auto get_min = [&](int s, int e) {
    	int lg = log[e-s+1];
    	return min(sparse_table[s][lg],sparse_table[e-(1<<lg)+1][lg]);
    };
    vector<vector<int>> sparse_table2(n, vector<int>(25));
    for(int i=0 ; i<n ; i++) {
    	sparse_table2[i][0] = -sa[i];
    }
    for(int pw=1 ; pw<25 ; pw++) {
    	for(int i=0 ; i+(1LL<<(pw-1))<n ; i++) {
    		sparse_table2[i][pw] = min(sparse_table2[i][pw-1], sparse_table2[i+(1LL<<(pw-1))][pw-1]);
    	}
    }
    auto get_min2 = [&](int s, int e) {
    	int lg = log[e-s+1];
    	return min(sparse_table2[s][lg],sparse_table2[e-(1<<lg)+1][lg]);
    };
    int maxlen = -1;
    int maxidx = -1;
    for(int i=0 ; i+d-1<n ; i++) {
    	int x = get_min(i+1,i+d-1);
    	if(x) {
    		if(x > maxlen) {
    			maxlen = x;
    			maxidx = -get_min2(i,i+d-1);
    		} else if(x == maxlen) {
    			maxidx = max(maxidx, (int)-get_min2(i,i+d-1));
    		}
    	}
    }
    if(maxlen == -1) {
    	cout << "none" << '\n';
    } else {
    	cout << maxlen << ' ' << maxidx << '\n';
    }
}	

void solve(int n) {
	string s; cin >> s;
	make_sa(s, n);
	if(n==1) {
		cout<<sz(s)<<' '<<0<<'\n';
	}
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	while(1) {
		int n; cin >> n; if(n==0) return 0;
		solve(n);
	}
}