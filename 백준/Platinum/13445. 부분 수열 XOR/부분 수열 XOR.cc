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

const int mxN = 2;

class TrieNode {
public:
	bool valid;
  	int child[mxN];
  	int cnt;
  	TrieNode() {
  		cnt = 0;
    	valid = false;
    	for(int i=0 ; i<mxN ; i++)
      		child[i] = -1;
  	}
};

int k;

class Trie {
public:
 	vector<TrieNode> trie;
  	int _newNode() {
    	TrieNode tmp;
    	trie.push_back(tmp);
    	return sz(trie) - 1;
  	}
  	void _add(int str, int node, int idx) {
  		trie[node].cnt++;
    	if(idx == -1) {
      		trie[node].valid = true;
      		return;
    	}
    	int nxtC = !!(str & (1<<idx));
    	if(trie[node].child[nxtC] == -1) {
      		int next = _newNode();
      		trie[node].child[nxtC] = next;
    	}
    	_add(str, trie[node].child[nxtC], idx-1);
  	}
  	Trie() {
  	 	_newNode();
  	}
  	void add(int str) {
    	_add(str, 0, 25);
  	}
  	ll calc(int cur, int node=0, int idx=25) {
  		if(idx==-1) return 0;
  		if(k & (1<<idx)) {
  			int rev=(cur&(1<<idx));
  			if(rev==0) {
  				ll ret=0;
  				if(trie[node].child[0]!=-1) ret+=trie[trie[node].child[0]].cnt;
  				if(trie[node].child[1]!=-1) ret+=calc(cur,trie[node].child[1],idx-1);
  				return ret;
  			} else {
  				ll ret=0;
  				if(trie[node].child[1]!=-1) ret+=trie[trie[node].child[1]].cnt;
  				if(trie[node].child[0]!=-1) ret+=calc(cur,trie[node].child[0],idx-1);
  				return ret;
  			}
  		} else {
  			int rev=(cur&(1<<idx));
  			if(rev==0) {
  				if(trie[node].child[0]!=-1) return calc(cur,trie[node].child[0],idx-1);
  				else return 0;
  			} else {
  				if(trie[node].child[1]!=-1) return calc(cur,trie[node].child[1],idx-1);
  				else return 0;
  			}
  		}
  	}
};

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int n; cin >> n >> k;
	Trie t;
	int x = 0;
	t.add(0);
	ll ans=0;
	for(int i=0 ; i<n ; i++) {
		int p; cin >> p;
		x ^= p;
		ans += t.calc(x);
		t.add(x);
	}
	cout<<ans<<'\n';
}