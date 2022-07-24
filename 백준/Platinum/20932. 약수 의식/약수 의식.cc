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

int n, curmod;
int a[17];
ll dp[10][16][1<<17];
ll pows[11][16];

ll mult(ll x, ll y) {
	return (x*y)%curmod;
}
ll bin_pow(ll x, ll p) {
	if(p==0) return 1;
	if(p&1) return mult(x,bin_pow(x,p-1));
	return bin_pow(mult(x,x),p/2);
}
ll dfs(int mod, int id, int mask) {
	if(mask==(1<<n)-1) {
		return (mod==0);
	}
	ll& ret=dp[mod][id][mask];
	if(ret!=-1) return ret;
	ret=0;
	for(int i=0;i<n;i++) if(!(mask&(1<<i))) {
		ret+=dfs((mod+pows[curmod][id]*a[i])%curmod,id+1,mask+(1<<i));
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n;
	for(int i=0 ; i<n ; i++) cin >> a[i];
	ll ans=0;
	ll cur=1;
	for(int i=0 ; i<16 ; i++) {
		for(int j=1 ; j<=10 ; j++) {
			pows[j][i]=cur%j;
		}
		cur*=10;
	}
	for(int i=0 ; i<n ; i++) {
		curmod=a[i];
		for(int x=0;x<10;x++) for(int y=0;y<16;y++) for(int z=0;z<(1<<16);z++) dp[x][y][z]=-1;
		ans+=dfs(0,0,1<<i);
	}
	ll f=1;
	cout<<fixed<<setprecision(15);
	for(int i=1;i<=n;i++) f*=i;
	cout<<(ld)ans/(ld)f<<'\n';
}