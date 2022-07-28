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
	vector<string> a(n);
	for(int i=0 ; i<n ; i++) {
		int x; cin >> x;
		cin >> a[i];
	}
	int foo; cin >> foo;
	string t; cin >> t;
	vector<vector<pii>> b(n);
	for(int i=0 ; i<n ; i++) {
		int j=0;
		vector<int> pi(sz(a[i]));
		for(int k=1 ; k<sz(a[i]) ; k++) {
			while(j>0 && a[i][j] != a[i][k]) {
				j = pi[j-1];
			}
			if(a[i][j] == a[i][k]) {
				pi[k] = ++j;
			}
		} 
		j=0;
		for(int k=0 ; k<sz(t) ; k++) {
			while(j>0 && a[i][j] != t[k]) {
				j = pi[j-1];
			}
			if(a[i][j] == t[k]) {
				j++;
				if(j == sz(a[i])) {
					b[i].push_back({k-sz(a[i])+1,k});
					j = pi[j-1];
				}
			}
		}
	}
	vector<int> ptr(n);
	int l=0, r=0, ans=INF;
	while(r<sz(t)) {		
		bool good = true;
		for(int i=0 ; i<n ; i++) {
			bool good1 = false;
			while(ptr[i]<sz(b[i])&&b[i][ptr[i]].ff<l) ptr[i]++;
			if(ptr[i]==sz(b[i])) {good=false; break;}
			if(l<=b[i][ptr[i]].ff && b[i][ptr[i]].ss<=r) {
				good1=true;
			}
			if(!good1) {good=false;break;}
		}
		if(good) ans=min(ans,r-l+1), l++;
		else r++;
	}
	cout<<ans;
}