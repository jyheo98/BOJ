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
	string s; cin >> s;
	int tar = 11;
	int a=0, b=0;
	for(int i=0 ; i<sz(s) ; i+=2) {
		if(s[i] == 'A') {
			a += s[i+1] - '0';
		} else {
			b += s[i+1] - '0';
		}
		if(a == tar-1 && b == tar-1) {
			tar++;
		}
		else if(a >= tar) {
			cout << "A\n";
			return 0;
		} else if(b >= tar) {
			cout << "B\n";
			return 0;
		}
	}
}