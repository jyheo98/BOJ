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

vector<int> make_sa(string &s) {
	int n = sz(s);
	vector<pii> sa;
	vector<int> suff(n);
	vector<int> nums;
	for(int i=0 ; i<n ; i++) {
		suff[i] = s[i]-'a'+1;
		nums.push_back(suff[i]);
	}
	uniq(nums);
	for(int i=0 ; i<n ; i++) {
		suff[i] = lower_bound(all(nums), suff[i]) - nums.begin();
	}
	if(sz(nums) == n) {
		return suff;
	}
	for(int d=1 ; ; d*=2) {
		vector<pii> pairs;
		for(int i=0 ; i<n ; i++) {
			int nextnum = -1;
			if(i+d < n) nextnum = suff[i+d];
			pii curPair = {suff[i], nextnum};
			pairs.push_back(curPair);
		}
		uniq(pairs);
		for(int i=0 ; i<n ; i++) {
			int nextnum = -1;
			if(i+d < n ) nextnum = suff[i+d];
			pii curPair = {suff[i], nextnum};
			int idx = lower_bound(all(pairs), curPair) - pairs.begin();
			suff[i] = idx;
		}
		if(sz(pairs) == n) return suff;
	} 
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	string s; cin >> s;
	vector<int> ans = make_sa(s);
	vector<int> rans(sz(s));
	for(int i=0 ; i<sz(s) ; i++) {
		rans[ans[i]]=i;
	}
	for(auto x : rans) {
		cout << x << '\n';
	}
}