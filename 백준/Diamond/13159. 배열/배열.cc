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
#define LLInF 0x3f3f3f3f3f3f3f3f
#define InF 0x3f3f3f3f
#define uniq(x) sort(all(x)); x.resize(unique(all(x))-x.begin());
#define pw(x) (1LL<<x)

using pii = pair<int, int>;
using ll = long long;
using ld = long double;
const ll MOD = 1e9 + 7;
const long double PI = acos(-1.0);

struct node {
    node *l, *r, *p;
    ll sz;
    ll val, mn, mx, sum;
    bool inv;
    node() : l(nullptr), r(nullptr), p(nullptr) {};
    node(ll _v, node* _p) : l(nullptr), r(nullptr), p(_p), val(_v), mn(_v), mx(_v), sum(_v), inv(false), sz(1) {};
} *root;

node *ptr[300005];
void push(node *cur) {
    if(!cur->inv) return ;
    swap(cur->l, cur->r);
    if(cur->l) cur->l->inv = !cur->l->inv;
    if(cur->r) cur->r->inv = !cur->r->inv;
    cur->inv = false;
}

void update(node *cur) {
    cur->sz = 1;
    cur->mn = cur->mx = cur->sum = cur->val;
    if(cur->l) {
        cur->sz += cur->l->sz;
        cur->sum += cur->l->sum;
        cur->mn = min(cur->mn, cur->l->mn);
        cur->mx = max(cur->mx, cur->l->mx);
    }
    if(cur->r) {
        cur->sz += cur->r->sz;
        cur->sum += cur->r->sum;
        cur->mn = min(cur->mn, cur->r->mn);
        cur->mx = max(cur->mx, cur->r->mx);
    }
}

void rotate(node *cur) {
    node *p, *b;
    p = cur->p;
    if(!p) return;
    push(p); push(cur);
    node *pp = p->p;
    if(p->l == cur) {
        p->l = b = cur->r;
        cur->r = p;
    }
    else {
        p->r = b = cur->l;
        cur->l = p;
    }
    p->p = cur;
    cur->p = pp;
    if(b) b->p = p;
    if(!pp) root = cur;
    else {
        if(pp->l == p) pp->l = cur;
        else pp->r = cur;
    }
    update(p); 
    update(cur);
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

void kth(ll k) {
    node *p = root;
    push(p);
    while(1) {
        while(p->l && p->l->sz > k) {
            p = p->l;
            push(p);
        }
        if(p->l) k -= p->l->sz;
        if(!k) break;
        k--;
        p = p->r;
        push(p);
    }
    splay(p);
}

void gather(int l, int r) {
    kth(l-1);
    node *p = root;
    root = p->r;
    root->p = nullptr;
    kth(r-l+1);
    root->p = p;
    p->r = root;
    root = p;
}

int n, q;

void init(int n) {
    node *p;
    root = p = new node(-1,nullptr);
    ptr[0] = p;
    for(int i=1 ; i<=n ; i++) {
        p->r = new node(i,p);
        p = p->r;
        ptr[i] = p;
    }
    p->r = new node(400000,p);
    p = p->r;
    ptr[n+1] = p;
    while(p) {
        update(p); p = p->p;
    }
}

void flip(int l, int r) {
    gather(l,r);
    node *p = root->r->l;
    p->inv = !p->inv;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> q;
    init(n);
    while(q--) {
        int op;
        cin >> op;
        if(op == 1) {
            int l, r;
            cin >> l >> r;
            gather(l,r);
            node *p = root->r->l;
            cout << p->mn << ' ' << p->mx << ' ' << p->sum << '\n';
            p->inv = !p->inv;
        }
        else if(op == 2) {
            int l, r, x; 
            cin >> l >> r >> x;
            gather(l,r);
            node *p = root->r->l;
            cout << p->mn << ' ' << p->mx << ' ' << p->sum << '\n';
            if(l == r) continue;
            int k = r-l+1;
            if(x > 0) {
                x %= k;
                if(x == 0) continue ;
                flip(r-x+1,r);
                flip(l,r-x);
                flip(l,r);
            }
            else if (x < 0) {
                x = -x;
                x %= k;
                if(x == 0) continue ;
                flip(l,l+x-1);
                flip(l+x,r);
                flip(l,r);
            }
        }
        else if(op == 3) {
            int v; cin >> v;
            kth(v); 
            cout << root->val << '\n';
        }
        else {
            int v; cin >> v;
            splay(ptr[v]); cout << root->l->sz << '\n';
        }
    }
    for(int i=1 ; i<=n ; i++) {
    	kth(i);
    	cout << root->val << ' ';
    }
    cout << '\n';
    return 0;
}
