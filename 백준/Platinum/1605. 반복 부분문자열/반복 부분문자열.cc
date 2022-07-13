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

void make_sa(string &s) {
	int n = sz(s);
	vector<int> isa(n);
	vector<int> nums;
	for(int i=0 ; i<n ; i++) {
		isa[i] = s[i]-'a'+1;
		nums.push_back(isa[i]);
	}
	uniq(nums);
	for(int i=0 ; i<n ; i++) {
		isa[i] = lower_bound(all(nums), isa[i]) - nums.begin();
	}
	if(sz(nums) != n) {
		for(int d=1 ; ; d*=2) {
			vector<pii> pairs;
			for(int i=0 ; i<n ; i++) {
				int nextnum = -1;
				if(i+d < n) nextnum = isa[i+d];
				pii curPair = {isa[i], nextnum};
				pairs.push_back(curPair);
			}
			uniq(pairs);
			for(int i=0 ; i<n ; i++) {
				int nextnum = -1;
				if(i+d < n ) nextnum = isa[i+d];
				pii curPair = {isa[i], nextnum};
				int idx = lower_bound(all(pairs), curPair) - pairs.begin();
				isa[i] = idx;
			}
			if(sz(pairs) == n) {
				break;
			}
		} 
	}
	vector<int> sa(n);
	for(int i=0 ; i<n ; i++) {
		sa[isa[i]] = i;
	}
	vector<int> lcp(n);
    for(int k=0, i=0 ; i<n ; i++) if(isa[i]) {
        for(int j=sa[isa[i]-1]; s[i+k]==s[j+k]; ++k);
        lcp[isa[i]] = (k ? k-- : 0);
    }
    int ans = 0;
    for(int i=1 ; i<n ; i++) {
    	ans = max(ans, lcp[i]);
    }
    cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int n; cin >> n;
	string s; cin >> s;
	make_sa(s);
}