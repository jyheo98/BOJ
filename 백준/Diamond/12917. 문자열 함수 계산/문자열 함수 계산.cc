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
	vector<ll> sa(n), isa(n), cnt(m), idx(n), lcp(n);
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
   	function<ll(int,int)> solve = [&](int l, int r) -> ll {
   		if(l == r) return 2*lcp[r];
   		int mid = (l+r) / 2;
   		ll ans1 = solve(l,mid);
   		ll ans2 = solve(mid+1, r);
   		ll ans3 = 0;
   		int p1 = mid, p2 = mid+1;
   		ll curH = min(lcp[p1], lcp[p2]);
   		ans3 = 3 * curH;
   		while(p1!=l||p2!=r) {
   			if(p1==l) {
   				p2++;
   				curH = min(curH, lcp[p2]);
   			} else if(p2==r) {
   				p1--;
   				curH = min(curH, lcp[p1]);
   			} else {
   				if(lcp[p1-1] > lcp[p2+1]) {
   					p1--;
   					curH = min(curH, lcp[p1]);
   				} else {
   					p2++;
   					curH = min(curH, lcp[p2]);
   				}
   			}
   			ans3 = max(ans3, curH * (p2-p1+2));
   		}
   		return max({ans1,ans2,ans3});
   	};
    cout << max((ll)sz(s),solve(0,sz(lcp)-1));
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	string s; cin >> s;
	make_sa(s);
}