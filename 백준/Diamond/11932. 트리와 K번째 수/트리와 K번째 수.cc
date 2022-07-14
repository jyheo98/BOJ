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

int n, m;
vector<ll> a;
vector<vector<int>> g;
vector<int> p;

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
		build(0, 0, siz-1);
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
		update(old, cur, 0, siz-1, idx, val);
	}
	ll calc(int id, int l, int r) {
		return calc(id, 0, siz-1, l, r);
	}
	ll find(int u, int v, int lca, int plca, int k, int l, int r) {
		if(l==r) {
			return l;
		}
		assert(seg[u].l != -1);
		//debug(seg[u].v, seg[v].v, seg[lca].v);
		
		ll leftsum = seg[seg[u].l].v + seg[seg[v].l].v - seg[seg[lca].l].v - seg[seg[plca].l].v;
		//debug(seg[seg[u].l].v, seg[seg[v].l].v, seg[seg[lca].l].v, seg[seg[plca].l].v, leftsum, l, r, (l+r)/2);
		//debug(leftsum);
		int mid = (l+r)/2;
		//debug(l,r,mid,leftsum);
		if(leftsum >= k) {
			//debug("LEFT");
			return find(seg[u].l, seg[v].l, seg[lca].l, seg[plca].l, k, l, mid);
		} else {
			//debug("RIGHT");
			return find(seg[u].r, seg[v].r, seg[lca].r, seg[plca].r, k-leftsum, mid+1, r);
		}
	}
};

void dfs(int v, int par) {
	p[v]=par;
	for(int nxt : g[v]) if(nxt != par) {
		dfs(nxt, v);
	}
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n >> m;
	a = vector<ll>(n+1);
	p = vector<int>(n+1);
	vector<ll> nums;
	for(int i=1 ; i<=n ; i++) {
		cin >> a[i];
		nums.push_back(a[i]);
	}
	uniq(nums);
	PST st(n,sz(nums));
	g = vector<vector<int>>(n+1);
	for(int i=0 ; i<n-1 ; i++) {
		int u, v; cin >> u >> v; 
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(1, 0);
	function<void(int,int)> dfs_update = [&](int v, int par) {
		int x = lower_bound(all(nums),a[v])-nums.begin();
		st.update(p[v],v,x,1);
		//debug(p[v],v,x);
		for(int nxt : g[v]) if(nxt != par) {
			dfs_update(nxt, v);
		}
	};
	dfs_update(1,0);
	vector<vector<int>> par(n+1, vector<int>(21));
	vector<int> dep(n+1);
	function<void(int, int, int)> dfsx = [&](int v, int d, int p) {
		par[v][0] = p;
		dep[v] = d;
		for(int nxt : g[v]) {
			if(nxt == p) continue;
			dfsx(nxt, d+1, v);
		}
	};
	dfsx(1,0,0);
	for(int x=1 ; x<21 ; x++) {
		for(int v=1 ; v<=n ; v++) {
			par[v][x] = par[par[v][x-1]][x-1];
		}
	}
	function<int(int, int)> LCA = [&](int x, int y) {
		if(dep[x] > dep[y]) 
			swap(x,y);
		for(int i=20 ; i>=0 ; i--) {
			if(dep[y]-dep[x] >= pw(i))
				y = par[y][i];
		}
		if(x==y)
			return x;
		for(int i=20 ; i>=0 ; i--) {
			if(par[x][i] != par[y][i]) {
				x = par[x][i];
				y = par[y][i];
			}
		}
		return par[x][0];
	};
	for(int i=0 ; i<m ; i++) {
		int u, v, k; cin >> u >> v >> k; 
		//debug(LCA(u,v));
		cout << nums[st.find(u,v,LCA(u,v),p[LCA(u,v)],k,0,sz(nums)-1)] << '\n';
	}
}