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
	int n = sz(s), m = max(256, n)+1;
	vector<int> r(n*2), nr(n*2);
    vector<int> sa(n), isa(n), cnt(m), idx(n), lcp(n);
    for(int i=0 ; i<n ; i++) sa[i] = i, r[i] = s[i];
    for(int d=1 ; d<n ; d *= 2){
        auto cmp = [&](int i,int j){
            return r[i] < r[j] || (r[i] == r[j] && r[i+d] < r[j+d]); };

        for(int i=0 ; i<m ; i++) cnt[i] = 0;
        for(int i=0 ; i<n ; i++) cnt[r[i+d]]++;
        for(int i=1 ; i<m ; i++) cnt[i] += cnt[i-1];
        for(int i=n-1 ; ~i ; i--) idx[--cnt[r[i+d]]] = i;

        for(int i=0 ; i<m ; ++i) cnt[i] = 0;
        for(int i=0 ; i<n ; ++i) cnt[r[i]]++;
        for(int i=1 ; i<m ; ++i) cnt[i] += cnt[i-1];
        for(int i=n-1 ; ~i ; --i) sa[--cnt[r[idx[i]]]] = idx[i];

        nr[sa[0]] = 1;
        for(int i=1 ; i<n ; ++i) nr[sa[i]] = nr[sa[i-1]] + cmp(sa[i-1], sa[i]);
        for(int i=0 ; i<n ; ++i) r[i] = nr[i];

        if(r[sa[n-1]]==n) break;
    }
	for(int i=0 ; i<n ; i++) {
		isa[sa[i]] = i;
	}
    for(int k=0, i=0 ; i<n ; i++) if(isa[i]) {
        for(int j=sa[isa[i]-1]; s[i+k]==s[j+k]; ++k);
        lcp[isa[i]] = (k ? k-- : 0);
    }
    vector<int> ans(n);
    for(int i=0 ; i<n ; i++) {
    	ans[sa[i]] = lcp[i];
    	if(i+1<n) ans[sa[i]] = max(ans[sa[i]], lcp[i+1]);
    }
    for(auto x : ans) cout<<x<<'\n';
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int n; cin >> n;
	string s; cin >> s;
	make_sa(s);
}