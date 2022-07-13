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
const ll MOD = 1e9+7;
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

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	while(1) {
		int n; cin >> n;
		/*if(n==1 || n==3) {
			cout << n << " coconuts, no solution\n";
			continue;
		}*/
		if(n == -1) return 0;
		bool suc = 0;
		for(int i=sqrt(n)+1 ; i>=2 ; i--) {
			int t = n;
			bool fail = false;
			for(int j=1 ; j<=i ; j++) {
				if(t % i == 1) {
					t -= 1;
					t -= t/i;
				} else fail = true;
			}
			if(!fail && t%i == 0) {
				cout << n << " coconuts, "<< i << " people and 1 monkey\n";
				suc = true;
				break;
			} 
		}
		if(!suc) {
			cout << n << " coconuts, no solution\n"; 
		}
	}
}