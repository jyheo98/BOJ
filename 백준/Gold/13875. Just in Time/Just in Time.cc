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

bool is_prime(int x) {
	for(int i=2 ; i*i<=x ; i++) {
		if(x%i==0) return false;
	}
	return true;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	ll n; cin >> n;
	for(int i=n ; i>=1 ; i--) {
		if(is_prime(i)) {
			cout << i << '\n';
			return 0;
		}
	}	
}