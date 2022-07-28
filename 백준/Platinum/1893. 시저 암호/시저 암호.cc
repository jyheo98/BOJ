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

void solve() {
	string st; cin >> st;
	map<char,char> mp;
	for(int i=0 ; i<sz(st)-1 ; i++) {
		mp[st[i]]=st[i+1];
	}

	mp[st.back()]=st[0];
	string s, t; cin >> s >> t;
	vector<int> pi(sz(s));
	int j=0;
	for(int i=1 ; i<sz(s) ; i++) {
		while(j>0 && s[i] != s[j]) {
			j = pi[j-1];
		}
		if(s[j] == s[i]) {
			pi[j] = ++j;
		}
	}
	vector<int> ans;
	for(int tt=0 ; tt<sz(st) ; tt++) {
		j=0;
		int cans = 0;
		for(int i=0 ; i<sz(t) ; i++) {
			while(j>0 && s[j] != t[i]) {
				j = pi[j-1];
			} 
			if(s[j] == t[i]) {
				j++;
				if(j == sz(s)) {
					cans++;
					j = pi[j-1];
				}
			}
		}
		if(cans == 1) ans.push_back(tt);
		//shift
		for(char& c : s) {
			c=mp[c];
		}
	}
	if(sz(ans) == 0) {
		cout << "no solution\n";
		return;
	} else if(sz(ans) == 1) {
		cout << "unique: ";
	} else {
		cout << "ambiguous: ";
	}
	for(auto x : ans) cout << x << ' ';
	cout << '\n';
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int t; cin >> t;
	while(t--) {
		solve();
	}
}