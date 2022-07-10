#include <bits/stdc++.h>
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
const ll MOD = 1e9 + 7;
const long double PI = acos(-1.0);

int n, m;
vector<int> l, r;
ll dp[1005][1005][2];

ll dfs(int lid, int rid, int lr) {
  ll& ret = dp[lid][rid][lr];
  if(ret != -1) return ret;
  if(lid == sz(l)-1 && rid == sz(r)-1) {
    return ret = 0LL;
  }
  ret = LLINF;
  ll curPos = ((lr==0)?l[lid]:r[rid]);
  ll noteaten = sz(l)+sz(r)-lid-rid-2;
  if(lid<sz(l)-1) 
    ret = min(ret, noteaten*abs(curPos-l[lid+1])+dfs(lid+1,rid,0));
  if(rid<sz(r)-1)
    ret = min(ret, noteaten*abs(curPos-r[rid+1])+dfs(lid,rid+1,1));
  return ret;
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  for(int i=0 ; i<1005 ; i++) {
    for(int j=0 ; j<1005 ; j++) {
      for(int k=0 ; k<2 ; k++) {
        dp[i][j][k] = -1;
      }
    }
  }
  cin >> n >> m;
  for(int i=0 ; i<n ; i++) {
    int x; cin >> x;
    if(x <= m) l.push_back(x);
    if(x >= m) r.push_back(x);
  }
  l.push_back(m); r.push_back(m);
  uniq(l); uniq(r);
  reverse(all(l));
  cout << dfs(0,0,0) << '\n';
}