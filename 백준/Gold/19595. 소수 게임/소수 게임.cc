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

vector<int> dp(100005,-1);
vector<int> primes;
int p[100005];

int dfs(int x) {
	if(dp[x]!=-1) return dp[x];
	for(auto pp : primes) {
		if(x-pp<0) break;
		if(dfs(x-pp)==1) return dp[x]=0;
	}
	return dp[x]=1;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	for(int i=0 ; i<100005 ; i++) dp[i]=-1;
	for(int i=2 ; i<100005 ; i++) {
		if(p[i]==0) {
			primes.push_back(i);
			for(int j=i ; j<100005 ; j+=i) {
				p[j] = 1;
			}
		}
	}
	dp[0]=1;
	dp[1]=1;
	for(int i=2 ; i<100005 ; i++) {
		dfs(i);
	}
	for(int i=1 ; i<100005 ; i++) {
		dp[i]+=dp[i-1];
	}
	int T; cin >> T;
	while(T--) {
		int lim, k; cin >> lim >> k;
		int maxidx, mx=-1;
		for(int i=2 ; i+k-1<=lim ; i++) {
			if(mx<dp[i+k-1]-dp[i-1]) {
				mx=dp[i+k-1]-dp[i-1];
				maxidx=i;
			}
		}
		cout<<mx<<' '<<maxidx<<'\n';
	}
}