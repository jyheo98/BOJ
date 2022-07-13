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
	int n; cin >> n;
	vector<ld> c(n), w(n);
	for(int i=0 ; i<n ; i++) cin >> c[i];
	for(int i=0 ; i<n ; i++) cin >> w[i];
	ld l=0,r=1e6;
	ld ans;
	while(l+1e-12<r) {
		ld tl=(l+l+r)/3;
		ld tr=(l+r+r)/3;
		ld chaL=0,chaR=0;
		for(int i=0 ; i<n ; i++) {
			ld Lw = c[i]*tl;
			ld Rw = c[i]*tr;
			chaL+=abs(Lw-w[i]);
			chaR+=abs(Rw-w[i]);
		}
		ans=chaL;
		if(chaL<=chaR) {
			r=tr;
		} else l=tl;
	}
	cout<<fixed<<setprecision(12);
	cout<<ans<<'\n';
}