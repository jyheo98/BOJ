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

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int n, q; cin >> n >> q;
	vector<ll> x(n+10), dx(n+10), ddx(n+10);
	for(int i=0 ; i<q ; i++) {
		char c; cin >> c;
		int l, r; cin >> l >> r; l--, r--;
		if(c == 'H') {
			if((r-l) % 2 == 1) {
				ddx[l]++;
				ddx[r+2]++;
				ddx[(l+r)/2+1]--;
				ddx[(l+r)/2+2]--;
			} else {
				ddx[l]++;
				ddx[r+2]++;
				ddx[(l+r)/2+1]-=2;
			}
		} else if(c == 'V') {
			if((r-l) % 2 == 1) {
				ddx[l]--;
				ddx[r+2]--;
				ddx[(l+r)/2+1]++;
				ddx[(l+r)/2+2]++;
			} else {
				ddx[l]--;
				ddx[r+2]--;
				ddx[(l+r)/2+1]+=2;
			}
		} else if(c == 'R') {
			dx[l]++;
			dx[r+1]--;
 		} else {
 			dx[l]--;
 			dx[r+1]++;
 		}
	} 
	for(int i=1 ; i<n+5 ; i++) {
		ddx[i] += ddx[i-1];
	}
	for(int i=0 ; i<n ; i++) {
		dx[i] += ddx[i];
	}
	for(int i=1 ; i<n+5 ; i++) {
		dx[i] += dx[i-1];
	}
	for(int i=0 ; i<n ; i++) {
		x[i] += dx[i];
	}
	for(int i=0 ; i<n ; i++) {
		cout << x[i] << '\n';
	}
}