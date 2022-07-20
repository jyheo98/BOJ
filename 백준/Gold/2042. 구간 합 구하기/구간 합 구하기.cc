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
    node* l;
    node* r;
    node* p;
    ll sum;
    ll v;
    ll cnt;
    node(ll k,node* pp) {
        p = pp;
        l = r = nullptr;
        v = k;
        cnt = 1;
        sum = k;
    }
} *root;

void update(node *x){
    x->cnt = 1;
    x->sum = x->v;
    if(x->l){
        x->cnt += x->l->cnt;
    	x->sum += x->l->sum;
    }
    if(x->r){
        x->cnt += x->r->cnt;
        x->sum += x->r->sum;
    }
  
}
void rotate(node* x){//x to be parent
    node* p=x->p;
    node* b=nullptr;
    if(!p)return;
    if(x==p->l) p->l=b=x->r,x->r=p;
    else p->r=b=x->l,x->l=p;
    x->p=p->p;p->p=x;
    if(b) b->p=p;
    if(x->p){
        if(x->p->l==p)
            x->p->l=x;
        else x->p->r=x;
    }else root=x;
    update(p);update(x);
}
void splay(node *x,node *g=nullptr){//x to be g's child
    while(x->p!=g){
        node* p=x->p;
        if(p->p==g){rotate(x);break;}
        node* pp = p->p;
        if((p->l==x)^(pp->l==p)) {rotate(x);rotate(x);}
        else {rotate(p);rotate(x);}
    }
    if(!g)root=x;
}
void kth(ll k){
    node* x=root;
    while(1){
        while(x->l&&x->l->cnt>k)x=x->l;
        if(x->l)k-=x->l->cnt;
        if(!k)break;k--;
        x=x->r;
    }
    splay(x);
}
void gather(int s,int e){
    kth(e+1);
    node* temp=root;
    kth(s-1);
    splay(temp,root);
    return;
}

node* ptr[1000100];
ll arr[1001000];
void init(ll n){
    if(root) delete root;
    node* now=new node(-INF, nullptr);
    root=now;
    for(ll i=1; i<=n; i++){
        ptr[i] =  now->r = new node(arr[i],now);
        now = now->r;
    }
    now->r=new node(INF, now);
    for(ll i=n; i>=1; i--) update(ptr[i]);
    splay(ptr[n/2+1]);
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int n, p, q; cin >> n >> p >> q; p+=q;
	for(int i=1 ; i<=n ; i++) cin >> arr[i];
	init(n);
	while(p--) {
		int op; cin >> op;
		if(op == 1) {
			int id; ll val; cin >> id >> val;
			kth(id);
			root->v=val;
			update(root);
		} else {
			int l, r; cin >> l >> r;
			gather(l,r);
			cout<<root->r->l->sum<<'\n';
		}
	}
}