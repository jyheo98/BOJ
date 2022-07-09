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

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	ll n; cin >> n;
	vector<ll> yaksu;
	for(ll i=1 ; i*i<=n ; i++) {
		if(n % i == 0) {
			yaksu.push_back(i);
			if(i != n / i) {
				yaksu.push_back(n / i);
			}
		}
	}
	vector<vector<ll>> rs(1000005);
	for(ll r=2 ; r<=1000000 ; r++) {
		ll t = r;
		while(1) {
			rs[r].push_back((t-1)/(r-1));
			assert((t-1)%(r-1)==0);
			if(t > 1e18 / r) break;
			t *= r;

		}
	}
	sort(all(yaksu));
	for(ll a0 : yaksu) {
		for(ll r = 2 ; r<=1000000 ; r++) {
			if(sz(rs[r])<3) continue;
			for(ll i=2 ; i<sz(rs[r]) ; i++) {
				if(rs[r][i] * a0 == n) {
					ll sa = a0;
					cout << i+1 << '\n';
					for(int j=0 ; j<=i ; j++) {
						cout << sa << ' ';
						sa *= r;
					}
					return 0;
				}
			}
		}
	}
	cout << -1 << '\n';
}