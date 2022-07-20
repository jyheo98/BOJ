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

struct node {
	node *l, *r, *p;
	ll sum;
	ll v;
	ll cnt;
	ll mn, mx;
	bool rev;
	node(ll _v, node* _p) : v(_v), p(_p) {
		l = r = nullptr;
		sum = mn = mx = _v;
		cnt = 1;
		rev = false;
	}
	node(ll _v) : node(_v, nullptr) {}
	node() : node(0) {}
} *root;

void update(node *x) {
	x->cnt = 1;
	x->mn = x->mx = x->sum = x->v;
	if(x->l) {
		x->cnt += x->l->cnt;
		x->sum += x->l->sum;
		x->mx = max(x->mx, x->l->mx);
		x->mn = min(x->mn, x->l->mn);
	} 
	if(x->r) {
		x->cnt += x->r->cnt;
		x->sum += x->r->sum;
		x->mx = max(x->mx, x->r->mx);
		x->mn = min(x->mn, x->r->mn);
	}
} 

void propagate(node *x) {
	if(!x->rev) return;
	swap(x->l, x->r);
	if(x->l) x->l->rev = !x->l->rev;
	if(x->r) x->r->rev = !x->r->rev;
	x->rev = false;
}

void rotate(node *x) { // x를 부모로
	node *p = x->p, *q;
	if(!p) return;
	propagate(p);
	propagate(x);
	if(x == p->l) {
		p->l = q = x->r; x->r = p;
	} else {
		p->r = q = x->l; x->l = p;
	}
	x->p = p->p; 
	p->p = x;
	if(q) q->p = p;
	if(x->p) {
		if(x->p->l == p) {
			x->p->l = x;
		} else {
			x->p->r = x;
		}
	} else root = x;
	update(p);
	update(x);
}

void splay(node *x, node *g = nullptr) { // g를 x의 부모로 만듦
	while(x->p != g) {
		node *p = x->p;
		if(p->p == g) {
			rotate(x);
			break;
		}
		node *pp = p->p;
		if((pp->l==p)==(p->l==x)) {
			rotate(p);
			rotate(x);
		} else {
			rotate(x);
			rotate(x);
		}
	}
	if(!g) root = x;
}

void kth(int k) { // 0-based, 더미 있으면 1-based로 작동
	node *x = root;
	propagate(x);
	while(1) {
		while(x->l && x->l->cnt > k) {
			x = x->l;
			propagate(x);
		}
		if(x->l) k -= x->l->cnt;
		if(!k) break;
		k--;
		x = x->r;
		propagate(x);
	}
	splay(x);
}

node* gather(int s, int e) {
	kth(e+1);
	node *tmp = root;
	kth(s-1);
	splay(tmp, root);
	return root->r->l;
}

void flip(int s, int e) {
	assert(s<=e);
	node *x = gather(s,e);
	x->rev = !x->rev;
}

node* ptr[300005];
vector<int> a;
void init(int n) {
	vector<bool> vis(n+2);
	if(root) delete root;
	node *now = new node(-INF);
	ptr[0] = root = now;
	for(int i=1 ; i<=n ; i++) {
		now->r = new node(a[i], now);
		now = now->r;
		ptr[a[i]] = now;
	}
	now->r = new node(INF, now);
	now = now->r;
	while(now) {
		update(now); now = now->p;
	}
	splay(ptr[n/2]);
}

void inorder(node *x = root) {
	propagate(x);
	if(x->l) inorder(x->l);
	if(x->v!=-INF && x->v!=INF) cout << x->v << ' ';
	if(x->r) inorder(x->r); 
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	while(1) {
    	int n; cin >> n;
    	if(n==0) return 0;
    	a = vector<int>(n+1);
    	vector<int> nums;
    	for(int i=1 ; i<=n ; i++) {
    		cin >> a[i];
    		nums.push_back(a[i]);
    	} 
    	uniq(nums);
    	vector<vector<int>> g(sz(nums));
    	for(int i=1 ; i<=n ; i++) {
    		a[i] = lower_bound(all(nums),a[i])-nums.begin();
    		g[a[i]].push_back(i);
    	}
    	int z = 1;
    	for(int i=0 ; i<sz(nums) ; i++) {
    		for(auto x : g[i]) {
    			a[x] = z++; 
    		}
    	}
    	debug(a);
    	init(n);
    	for(int i=1 ; i<=n ; i++) {
    		splay(ptr[i]);
    		cout << root->l->cnt << ' ';
    		flip(i,root->l->cnt);
    	}	
    	cout << '\n';
    }
}