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

int nk; 
string s = "";

void make_sa() {
	int n = sz(s), m = max(256, n)+1;
	vector<int> r(n+1), nr(n+1);
    vector<int> sa(n), isa(n), cnt(m), idx(n), lcp(n);
    for(int i=0 ; i<n ; i++) sa[i] = i, r[i] = s[i];
    for(int d=1 ; d<n ; d *= 2){
        auto cmp = [&](int i,int j){
            return r[i] < r[j] || (r[i] == r[j] && r[min(n,i+d)] < r[min(n,j+d)]); };

        for(int i=0 ; i<m ; i++) cnt[i] = 0;
        for(int i=0 ; i<n ; i++) cnt[r[min(n,i+d)]]++;
        for(int i=1 ; i<m ; i++) cnt[i] += cnt[i-1];
        for(int i=n-1 ; ~i ; i--) idx[--cnt[r[min(n,i+d)]]] = i;

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
    vector<int> what(n);
    int c=0;
    for(int i=0 ; i<n ; i++) {
    	what[i] = c;
    	if(s[i] < 'a' || s[i] > 'z') c++;
    }
    int state = 0;
    vector<int> cnts(nk);
    vector<vector<int>> sparse_table(21, vector<int>(n));
    for(int i=0 ; i<n ; i++) {
    	sparse_table[0][i] = lcp[i];
    }
    vector<int> log(n+1);
   	log[1] = 0;
   	for(int i=2 ; i<=n ; i++)
   		log[i] = log[i/2] + 1;
    for(int pw=1 ; pw<21 ; pw++) {
    	for(int i=0 ; i+(1LL<<(pw-1))<n ; i++) {
    		sparse_table[pw][i] = min(sparse_table[pw-1][i], sparse_table[pw-1][i+(1LL<<(pw-1))]);
    	}
    }
    auto get_min = [&](int s, int e) {
    	int lg = log[e-s+1];
    	return min(sparse_table[lg][s],sparse_table[lg][e-(1<<lg)+1]);
    };
    int lid=0, rid=0;
    int ans = 0;
    while(rid<n) {
		int cur = what[sa[rid]];
		state |= (1<<cur);
		cnts[cur]++;
		if(state == (1<<nk)-1) {
			while(1) {
				if(cnts[what[sa[lid]]] == 1) break;
				cnts[what[sa[lid]]]--; lid++;
			}
			ans = max(ans, get_min(lid+1,rid));
			cnts[what[sa[lid]]]--;
			state ^= (1<<what[sa[lid]]);
			lid++;
		}
		rid++;
    }
    cout << ans << '\n';
}

int main() {
	cin >> nk;
	int tot = (1<<27)-1;
	string shit = "!@#$%^&*()_+[]";
	for(int i=0 ; i<nk ; i++) {
		string t; cin >> t; 
		ll z = 0;
		for(char c : t) z |= (1<<(c-'a'));
		tot &= z;
		t += shit[i];
		s += t;
	}
	if(!tot) {
		cout << 0 << '\n';
		return 0;
	}
	make_sa();
}