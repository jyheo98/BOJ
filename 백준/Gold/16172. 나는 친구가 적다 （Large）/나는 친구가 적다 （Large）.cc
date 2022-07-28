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
	string s, t;
	cin >> s >> t;
	string tmp = "";
	for(char c : s) if(!(c>='0'&&c<='9')) tmp+=c;
	s = tmp;
	vector<int> pi(sz(t));
	int j=0;
	for(int i=1 ; i<sz(t) ; i++) {
		while(j>0&&t[i]!=t[j]) {
			j=pi[j-1];
		}
		if(t[i]==t[j]) {
			pi[i]=++j;
		}
	}
	j=0;
	for(int i=0 ; i<sz(s) ; i++) {
		while(j>0&&t[j]!=s[i]) j=pi[j-1];
		if(t[j]==s[i]) {
			j++;
			if(j==sz(t)) {
				cout<<1;
				return 0;
			}
		}
	}
	cout<<0;
}