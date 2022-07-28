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
	string s;
	cin >> s;
	int n = sz(s);
	vector<int> pi(n);
	int j=0;
	for(int i=1 ; i<n ; i++) {
		while(j>0&&s[i]!=s[j]) j=pi[j-1];
		if(s[i]==s[j]) pi[i]=++j;
	}
	int l=pi[n-1];
	while(l) {
		vector<int> pi2(l);
		j=0;
		for(int i=1 ; i<l ; i++) {
			while(j>0&&s[i]!=s[j]) j=pi2[j-1];
			if(s[i]==s[j]) pi2[i]=++j;
		}
		j=0;
		int cnt=0;
		for(int i=0 ; i<n ; i++) {
			while(j>0&&s[i]!=s[j]) j=pi2[j-1];
			if(s[i]==s[j]) {
				j++;
				if(j==l) {
					cnt++;
					j=pi2[j-1];
				}
			} 
		}
		if(cnt>=3) {
			cout<<s.substr(0,l)<<'\n';
			return 0;
		}
		l=pi[l-1];
	}
	cout<<-1<<'\n';
}