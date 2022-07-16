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

ll add(ll x, ll y) {
	x+=y; x%=MOD;
	return x;
}
ll sub(ll x, ll y) {
	x-=y; x%=MOD; if(x<0) x+=MOD;
	return x;
}
ll mult(ll x, ll y) {
	return (x*y)%MOD;
}
ll bin_pow(ll x, ll p) {
	if(p==0) return 1;
	if(p&1) return mult(x,bin_pow(x,p-1));
	return bin_pow(mult(x,x),p/2);
}
ll rev(ll x) {
	return bin_pow(x,MOD-2);
}
vector<ll> era(10000001);
vector<int> primes;

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	for(int i=2 ; i<=10000000 ; i++) {
		if(!era[i]) {
			primes.push_back(i);
			for(int j=i ; j<=10000000 ; j+=i) {
				era[j]=1;
			}
		}
	}
	while(1) {
		int n; cin >> n;
		if(n==0) return 0;
		ll ans = 1;
		for(auto x : primes) {
			ll t = n;
			ll p = x;
			ll cur = 0;
			while(t>=p) {
				cur += t/p;
				p*=x;
			} 
			if(cur&1) cur--;
			ans = mult(ans, bin_pow(x,cur));
		}
		cout << ans << '\n';
	}
}