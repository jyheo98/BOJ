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

int n, k;
int dp[55][55][22];
int a[55];

int dfs(int l, int r, int lft) {
	int& ret = dp[l][r][lft];
	if(ret!=-1) return ret;
	if(lft == 0) return ret = 0;
	if(l>r) return ret = 0;
	ret = dfs(l+1,r,lft);
	ret = max(ret,dfs(l+1,r,lft-1)+a[l]);
	for(int i=l+1 ; i<=r ; i++) {
		for(int x=0 ; x<=lft-1 ; x++) {
			ret = max(ret, a[l]*a[i] + dfs(l+1,i-1,x) + dfs(i+1,r,lft-x-1));
		}
	}
	return ret;
}

vector<int> ans;
vector<int> ans2;

void reconstruct(int l, int r, int lft) {
	if(lft == 0) return;
	if(l>r) return;
	if(dp[l][r][lft]==dp[l+1][r][lft]) {
		reconstruct(l+1,r,lft);
		return;
	}
	if(dp[l][r][lft]==dp[l+1][r][lft-1]+a[l]) {
		ans[l]=l+1;
		ans2.push_back(l+1);
		reconstruct(l+1,r,lft-1);
		return;
	}
	for(int i=l+1 ; i<=r ; i++) {
		for(int x=0 ; x<=lft-1 ; x++) {
			if(dp[l][r][lft] == a[l]*a[i] + dp[l+1][i-1][x] + dp[i+1][r][lft-x-1]) {
				ans[l]=i+1;
				ans[i]=l+1;
				ans2.push_back(l+1);
				reconstruct(l+1,i-1,x);
				reconstruct(i+1,r,lft-x-1);
				return;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	for(int i=0 ; i<55 ; i++) for(int j=0 ; j<55 ; j++) for(int k=0 ; k<22 ; k++) 
		dp[i][j][k] = -1;
	cin >> n >> k;
	for(int i=0 ; i<n ; i++) 
		cin >> a[i];
	ans = vector<int>(n);
	dfs(0,n-1,k);
	reconstruct(0,n-1,k);
	while(sz(ans2)<k) ans2.push_back(0); 
	for(auto x : ans2) cout << x << '\n';
	for(auto x : ans) cout << x << '\n';
}