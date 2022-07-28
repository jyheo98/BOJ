#include <bits/stdc++.h>
using namespace std;

#define pb emplace_back
#define all(x) x.begin(), x.end()
#define ff first
#define ss second
#define LLINF 0x3f3f3f3f3f3f3f3f
#define INF 0x3f3f3f3f
#define uniq(x) sort(all(x)), x.resize(unique(all(x))-x.begin());
#define sz(x) (int)x.size()
#define pw(x) (1LL<<x)

using pii = pair<int, int>;
using ll = long long;
using ld = long double;
const ll MOD = 1e9 + 7;
const ld PI = acos(-1.0);

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; string s; cin >> n >> s;
    vector<int> pi(n);
    for(int i=1 ; i<n ; i++) {
        int z = pi[i-1];
        bool good = false;
        while(1) {
            if(s[i] == s[z]) {
                good = true;
                break;
            }
            if(z == 0) break;
            z = pi[z-1];
        }
        if(good) z++;
        pi[i] = z;
    }
    cout << n - pi[n-1] << '\n';
}