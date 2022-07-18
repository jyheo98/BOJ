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

#define int ll

int n;
vector<pii> a;
vector<int> sum[100005];
vector<pii> coor[20002];

int32_t main(){
    ios::sync_with_stdio(0), cin.tie(0); 
    cin >> n;
	for(int i=0 ; i<n ; i++) {
		int x, y; cin >> x >> y;
		a.push_back({x,y});
	}
	for(int i=0 ; i<n ; i++) {
		int x = a[i].ff, y = a[i].ss;
		coor[x + 10000].push_back({y, i});
	}
	for(int i=0 ; i<20002 ; i++) if(sz(coor[i])){
		sort(all(coor[i]));
		ll cur = 0;
		for(int j=0 ; j<sz(coor[i]) ; j++) {
			cur += coor[i][j].ff - coor[i][0].ff;
			cur = cur % MOD;
		}
		for(int j=0 ; j<sz(coor[i]) ; j++) {
			int idx = coor[i][j].ss; 
			if(j){
				cur = cur + (j * 2 - sz(coor[i])) * ( coor[i][j].ff - coor[i][j-1].ff);
				cur = cur % MOD;
			}
			sum[idx].push_back(cur);
		}
	}
	for(int i=0 ; i<20002 ; i++) coor[i].clear();
	for(int i=0 ; i<n ; i++) {
		int x = a[i].ff, y = a[i].ss;
		coor[y + 10000].push_back({x, i});
	}
	for(int i=0 ; i<20002 ; i++) if(sz(coor[i])){
		sort(all(coor[i]));
		ll cur = 0;
		for(int j=0 ; j<sz(coor[i]) ; j++) {
			cur += coor[i][j].ff - coor[i][0].ff;
			cur = cur % MOD;
		}
		for(int j=0 ; j<sz(coor[i]) ; j++) {
			int idx = coor[i][j].ss; 
			if(j){
				cur = cur + (j * 2 - sz(coor[i])) * ( coor[i][j].ff - coor[i][j-1].ff);
				cur = cur % MOD;
			}
			sum[idx].push_back(cur);
		}
	}
	ll ans = 0;
	for(int i=0 ; i<n ; i++) {
		ans = ans + sum[i][0] * sum[i][1];
		ans = ans % MOD;
	}
	cout << ans << endl;
    return 0;
}
