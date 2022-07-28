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

int n, k;
vector<vector<int>> a, b;

bool kmp(int x) {
	vector<int> pi(k);
	int z = 0;
	for(int i=1 ; i<k ; i++) {
		while(z>0 && a[0][x+i] != a[0][x+z]) {
			z = pi[z-1];
		}
		if(a[0][x+i] == a[0][x+z]) {
			pi[i] = ++z;
		}
	}
	for(int i=1 ; i<n ; i++) {
		bool good = false;
		z = 0;
		for(int j=0 ; j<sz(a[i]) ; j++) {
			while(z>0 && a[i][j] != a[0][x+z])
				z = pi[z-1];
			if(a[i][j] == a[0][x+z]) {
				z++;
				if(z == k) {
					good = true;
					break;
				}
			}
		}
		z = 0;
		for(int j=0 ; j<sz(b[i]) ; j++) {
			while(z>0 && b[i][j] != a[0][x+z])
				z = pi[z-1];
			if(b[i][j] == a[0][x+z]) {
				z++;
				if(z == k) {
					good = true;
					break;
				}
			}
		}
		if(!good) return false;
	}
	return true;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n >> k;
	a = vector<vector<int>>(n);
	b = vector<vector<int>>(n);	
	for(int i=0 ; i<n ; i++) {
		int x; cin >> x;
		while(x--) {
			int v; cin >> v;
			a[i].push_back(v);
		}
		b[i] = a[i];
		reverse(all(b[i]));
	}
	bool ans = false;
	for(int i=0 ; i+k-1<sz(a[0]) ; i++) {
		ans |= kmp(i);
	}
	cout << (ans ? "YES" : "NO") << '\n';
}