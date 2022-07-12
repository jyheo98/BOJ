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
const char st = 0;

class TrieNode {
public:
  bool valid;
  int child[mxN];
  int cnt = 0;
  TrieNode() {
    for(int i=0 ; i<mxN ; i++)
      child[i] = -1;
  }
};

class Trie {
private:
  vector<TrieNode> trie;
  int _newNode() {
    TrieNode tmp;
    trie.push_back(tmp);
    return sz(trie) - 1;
  }
  void _add(int str, int node, int idx) {
    trie[node].cnt++;
    if(idx == -1) return;
    int nxtC = !!(str & (1<<idx));
    if(trie[node].child[nxtC] == -1) {
      int next = _newNode();
      trie[node].child[nxtC] = next;
    }
    _add(str, trie[node].child[nxtC], idx-1);
  }
  void _del(int str, int node, int idx) {
    trie[node].cnt--;
    if(idx == -1) return;
    int nxtC = !!(str & (1<<idx));
    _del(str, trie[node].child[nxtC], idx-1);
  }
  int _calc(int str, int node, int idx) {
    if(idx == -1) return 0;
    if(trie[node].child[0] == -1 || trie[trie[node].child[0]].cnt == 0) {
      return (1<<idx) + _calc(str, trie[node].child[1], idx-1);
    } else if(trie[node].child[1] == -1 || trie[trie[node].child[1]].cnt == 0) {
      return _calc(str, trie[node].child[0], idx-1);
    } else {
      if(str & (1<<idx)) {
        return _calc(str, trie[node].child[0], idx-1);
      } else {
        return (1<<idx) + _calc(str, trie[node].child[1], idx-1);
      }
    }
  }
    
public:
  Trie() {
    _newNode();
  }
  void add(int &str) {
    _add(str, 0, 31);
  }
  void del(int &str) {
    _del(str, 0, 31);
  }
  int calc(int &str) {
    return _calc(str, 0, 31);
  }
};

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  int q; cin >> q;
  Trie t;
  int z = 0;
  t.add(z);
  while(q--) {
    int op; cin >> op;
    if(op == 1) {
      int x; cin >> x;
      t.add(x);
    } else if(op ==2) {
      int x; cin >> x;
      t.del(x);
    } else {
      int x; cin >> x;
      cout << (x^t.calc(x)) << '\n';
    }
  }
}