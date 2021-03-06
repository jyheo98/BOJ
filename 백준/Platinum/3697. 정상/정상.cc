#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(false);cin.tie(0)
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

#define int ll

int p[250005];
int s[250005];

int find(int x) {
  if(x == p[x]) return x;
  return p[x] = find(p[x]);
}

bool unite(int u, int v) {
  u = find(u);
  v = find(v);
  if(u == v) return false;
  if(s[u] < s[v]) swap(u, v);
  p[v] = u;
  return true;
}

void solve() {
  int n, m, d; cin >> n >> m >> d;
  vector<vector<int>> a(n, vector<int>(m));
  map<int, vector<pii>> g;
  for(int i=0 ; i<n ; i++) {
    for(int j=0 ; j<m ; j++) {
      cin >> a[i][j];
      g[-a[i][j]].push_back({i, j});
    }
  }
  for(int i=0 ; i<n*m; i++) {
    p[i]=i, s[i] = a[i/m][i%m];
  }
  vector<int> dx = {1, -1, 0, 0}, dy = {0, 0, -1, 1};
  auto valid = [&](int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m;
  };
  vector<pair<int, pii>> unpair; 
  for(int i=0 ; i<n ; i++) {
    for(int j=0 ; j<m ; j++) {
      pii coor = {i, j};
      for(int dd=0 ; dd<4 ; dd++) {
        int nx = coor.ff + dx[dd];
        int ny = coor.ss + dy[dd];
        if(valid(nx,ny)) {
          unpair.push_back({min(a[i][j], a[nx][ny]),{i*m+j,nx*m+ny}});
        } 
      }
    }
  }
  sort(unpair.begin(),unpair.end());
  int ans = 0;
  for(auto x : g) {
    while(sz(unpair)&&unpair.back().ff>=-x.ff-d+1) {
      if(unite(unpair.back().ss.ff, unpair.back().ss.ss)) {
        //debug(unpair.back().ss.ff/m, unpair.back().ss.ff%m, unpair.back().ss.ss/m, unpair.back().ss.ss%m);
      }
      unpair.pop_back();
    }
    for(pii coor : x.ss) {
      if(s[find(coor.ff*m+coor.ss)]==a[coor.ff][coor.ss]) {
        ans++;
        //debug(coor);
      }
    }
    for(pii coor : x.ss) {
      for(int dd=0 ; dd<4 ; dd++) {
        int nx = coor.ff + dx[dd];
        int ny = coor.ss + dy[dd];
        if(valid(nx,ny)) {
          if(unite(coor.ff*m+coor.ss,nx*m+ny)) {
            //debug(coor, nx,ny);
          }
        } 
      }
    }
  }
  cout << ans << '\n';
}

int32_t main() {
  ios::sync_with_stdio(0), cin.tie(0);
  int t = 1; cin >> t;
  while(t--)
    solve();
}