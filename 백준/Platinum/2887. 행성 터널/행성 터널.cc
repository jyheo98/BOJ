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

int par[100003];
struct p {
	int x, y, z, i;
};
bool cmp1(p a, p b) {
	return a.x < b.x;
}
bool cmp2(p a, p b) {
	return a.y < b.y;
}
bool cmp3(p a, p b) {
	return a.z < b.z;
}
bool cmp(pair<ll, pii> a, pair<ll, pii> b) {
	return a.ff < b.ff;
}

int find(int x) {
	if(x == par[x]) return x;
	return par[x] = find(par[x]);
}
bool unite(int x, int y) {
	x = find(x);
	y = find(y);
	if(x == y) return false;
	par[x] = y;
	return true;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int n; cin >> n;
	for(int i=0 ; i<n ; i++) par[i] = i;
	vector<p> a(n);
	for(int i=0 ; i<n ; i++) {
		cin >> a[i].x >> a[i].y >> a[i].z;
		a[i].i = i;
	}
	vector<pair<ll, pii>> qu;
	sort(all(a),cmp1);
	for(int i=0 ; i<n-1 ; i++) {
		qu.push_back({a[i+1].x-a[i].x,{a[i].i,a[i+1].i}});
	}
	sort(all(a),cmp2);
	for(int i=0 ; i<n-1 ; i++) {
		qu.push_back({a[i+1].y-a[i].y,{a[i].i,a[i+1].i}});
	}
	sort(all(a),cmp3);
	for(int i=0 ; i<n-1 ; i++) {
		qu.push_back({a[i+1].z-a[i].z,{a[i].i,a[i+1].i}});
	}
	sort(all(qu),cmp);
	ll ans = 0;
	for(auto x : qu) {
		if(unite(x.ss.ff, x.ss.ss)) ans += x.ff;
	}
	cout << ans << '\n';
} 