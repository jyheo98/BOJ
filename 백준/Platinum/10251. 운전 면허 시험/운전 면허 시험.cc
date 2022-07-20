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

vector<vector<vector<vector<int>>>> dp;
vector<vector<int>> garoprice, seroprice;
int m, n, l, g; 

void solve() {
	cin >> n >> m >> l >> g;
	dp = vector<vector<vector<vector<int>>>>(n, vector<vector<vector<int>>>(m, vector<vector<int>>(2, vector<int>(303, LLINF))));
	garoprice = vector<vector<int>>(n, vector<int>(m-1));
	seroprice = vector<vector<int>>(n-1, vector<int>(m));
	for(int i=0 ; i<n ; i++) {
		for(int j=0 ; j<m-1 ; j++) {
			cin >> garoprice[i][j];
		}
	}
	for(int i=0 ; i<n-1 ; i++) {
		for(int j=0 ; j<m ; j++) {
			cin >> seroprice[i][j];
		}
	}
	dp[0][0][0][0]=0;
	dp[0][0][1][0]=0;
	for(int i=0 ; i<n ; i++) for(int j=0 ; j<m ; j++) {
		for(int h=0 ; h<2 ; h++) {
			for(int c=0 ; c<303 ; c++) if(dp[i][j][h][c]!=LLINF) {
				if(h==0) {
					if(i+1<n) dp[i+1][j][h][c]=min(dp[i+1][j][h][c], dp[i][j][h][c]+seroprice[i][j]);
					if(j+1<m) dp[i][j+1][h^1][c+1]=min(dp[i][j+1][h^1][c+1], dp[i][j][h][c]+garoprice[i][j]);
				} else {
					if(i+1<n) dp[i+1][j][h^1][c+1]=min(dp[i+1][j][h^1][c+1], dp[i][j][h][c]+seroprice[i][j]);
					if(j+1<m) dp[i][j+1][h][c]=min(dp[i][j+1][h][c], dp[i][j][h][c]+garoprice[i][j]);
				}
			}
		}
	}
	int ans=INF;
	
	for(int h=0 ; h<2 ; h++) for(int c=0 ; c<303 ; c++) {
		if(dp[n-1][m-1][h][c]<=g) {
			ans=min(ans,c);
		}
	}  
		
	if(ans==INF) {
		cout<<-1<<'\n';
	} else {
		cout<<ans+(m+n-2)*l<<'\n';
	}
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int t = 1; cin >> t;
	while(t--)
		solve();
}