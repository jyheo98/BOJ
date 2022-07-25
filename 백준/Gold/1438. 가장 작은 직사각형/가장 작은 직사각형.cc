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
	vector<pii> a(n);
	for(int i=0 ; i<n ; i++) cin >> a[i].ff >> a[i].ss;
	sort(all(a));
	int ans=INF;
	for(int i=0 ; i<n ; i++) {
		for(int j=i ; j<n ; j++) {
			int mnH = min(a[i].ss,a[j].ss)-1;
			int mxH = max(a[i].ss,a[j].ss)+1;
			vector<int> idx;
			for(int k=0 ; k<n ; k++) {
				if(a[k].ss>mnH&&a[k].ss<mxH) idx.push_back(k);
			}
			if(sz(idx) < n/2) continue;
			int mnX=INF;
			for(int i=n/2-1 ; i<sz(idx) ; i++) {
				int T = a[idx[i]].ff+1-(a[idx[i-n/2+1]].ff-1);
				mnX=min(mnX,T);
			}
			ans=min(ans,mnX*(mxH-mnH));
		}
	}
	cout<<ans;
}