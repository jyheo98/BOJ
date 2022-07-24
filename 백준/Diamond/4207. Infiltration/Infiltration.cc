#define LOCAL

#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2")

#define IOS ios::sync_with_stdio(false);cin.tie(0)
#define all(x) x.begin(), x.end()
#define ff first
#define ss second
#define LLINF 0x3f3f3f3f3f3f3f3f
#define INF 0x3f3f3f3f
#define uniq(x) sort(all(x)); x.resize(unique(all(x))-x.begin());
#define sz(x) (int)x.size()

// Copied from Gennady-Korotkevich's template

template <typename A, typename B>
string to_string(pair<A, B> p);

template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p);

template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p);

string to_string(const string& s) {
	return '"' + s + '"';
}

string to_string(const char* s) {
	return to_string((string)s);
}

string to_string(bool b) {
	return (b ? "true" : "false");
}

string to_string(vector<bool> v) {
	bool first = true;
	string res = "{";
	for (int i = 0; i < static_cast<int>(v.size()); i++) {
		if (!first) {
			res += ", ";
		}
		first = false;
		res += to_string(v[i]);
	}
	res += "}\n";
	return res;
}

template <size_t N>
string to_string(bitset<N> v) {
	string res = "";
	for (size_t i = 0; i < N; i++) {
		res += static_cast<char>('0' + v[i]);
	}
	return res;
}

template <typename A>
string to_string(A v) {
	bool first = true;
	string res = "{";
	for (const auto& x : v) {
		if (!first) {
			res += ", ";
		}
		first = false;
		res += to_string(x);
	}
	res += "}\n";
	return res;
}

template <typename A, typename B>
string to_string(pair<A, B> p) {
	return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p) {
	return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ")";
}

template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p) {
	return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ")";
}

template <typename A, typename B, typename C, typename D, typename E>
string to_string(tuple<A, B, C, D, E> p) {
	return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + "," + to_string(get<4>(p)) + ")";
}

void debug_out() {
	cerr << endl;
}

template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
	cerr << " " << to_string(H);
	debug_out(T...);
}

#ifdef LOCAL
#define debug(...) cerr << "\n[" << #__VA_ARGS__ << "]:\n", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

// End of Gennady-Korotkevich's template 

using pii = pair<int, int>;
using ll = long long;
const ll MOD = 1e9 + 7;
const long double PI = acos(-1.0);

int tc = 1;

void solve(int n) {
	int ans = 6;
	vector<bitset<76>> G(n);
	for(int i=0 ; i<n ; i++) {
		string s; cin >> s;
		for(int j=0 ; j<sz(s) ; j++) {
			if(s[j] == '1')
				G[i][j] = 1;
			else if(i == j)
				G[i][j] = 1;
		}
	}
	bitset<76> bit, tmp1, tmp2, tmp3, tmp4, tmp5;
	ll rans = 0;
	for(ll i1=0 ; i1<n ; i1++) {
		tmp1 = bit;
		bit |= G[i1];
		for(ll i2=i1+1 ; i2<n ; i2++) {
			tmp2 = bit;
			bit |= G[i2];
			for(ll i3 = i2+1 ; i3<n ; i3++) {
				tmp3 = bit;
				bit |= G[i3];
				for(ll i4 = i3+1 ; i4<n ; i4++) {
					tmp4 = bit;
					bit |= G[i4];
					for(ll i5 = i4+1 ; i5<n ; i5++) {
						tmp5 = bit;
						bit |= G[i5];
						if(bit.count()==n) {
							ans = 5;
							rans = i1 + i2 * 75 + i3 * 75 * 75 + i4 * 75 * 75 * 75 + i5 * 75 * 75 * 75 * 75;
						} else if(bit.count()==n-1 && ans != 5) {
							ans = 6;
							rans = i1 + i2 * 75 + i3 * 75 * 75 + i4 * 75 * 75 * 75 + i5 * 75 * 75 * 75 * 75;
							for(ll i=0 ; i<n ; i++) {
								if(bit[i] == 0)
									rans += i * 75 * 75 * 75 * 75 * 75;
							}
						}
						bit = tmp5;
					}
					bit = tmp4;
				}
				bit = tmp3;
			}
			bit = tmp2;
		}
		bit = tmp1;
	}
	for(ll i1=0 ; i1<n ; i1++) {
		tmp1 = bit;
		bit |= G[i1];
		for(ll i2=i1+1 ; i2<n ; i2++) {
			tmp2 = bit;
			bit |= G[i2];
			for(ll i3 = i2+1 ; i3<n ; i3++) {
				tmp3 = bit;
				bit |= G[i3];
				for(ll i4 = i3+1 ; i4<n ; i4++) {
					tmp4 = bit;
					bit |= G[i4];
					if(bit.count()==n) {
						ans = 4;
						rans = i1 + i2 * 75 + i3 * 75 * 75 + i4 * 75 * 75 * 75;
					}
					bit = tmp4;
				}
				bit = tmp3;
			}
			bit = tmp2;
		}
		bit = tmp1;
	}
	for(ll i1=0 ; i1<n ; i1++) {
		tmp1 = bit;
		bit |= G[i1];
		for(ll i2=i1+1 ; i2<n ; i2++) {
			tmp2 = bit;
			bit |= G[i2];
			for(ll i3 = i2+1 ; i3<n ; i3++) {
				tmp3 = bit;
				bit |= G[i3];
				if(bit.count()==n) {
					ans = 3;
					rans = i1 + i2 * 75 + i3 * 75 * 75;
				}
				bit = tmp3;
			}
			bit = tmp2;
		}
		bit = tmp1;
	}
	for(ll i1=0 ; i1<n ; i1++) {
		tmp1 = bit;
		bit |= G[i1];
		for(ll i2=i1+1 ; i2<n ; i2++) {
			tmp2 = bit;
			bit |= G[i2];
			if(bit.count()==n) {
				ans = 2;
				rans = i1 + i2 * 75;
			}
			bit = tmp2;
		}
		bit = tmp1;
	}
	for(ll i=0 ; i<n ; i++) {
		tmp1 = bit;
		bit |= G[i];
		if(bit.count()==n) {
			ans = 1;
			rans = i;
		}
		bit = tmp1;
	}
	cout << "Case " << tc << ": "; tc += 1;
	cout << ans << " ";

	assert(ans <=6);
	while(ans --) {
		cout << rans % 75 + 1 << " ";
		rans /= 75LL;
	}
	cout << "\n";
}

int main() {
	IOS;
	while(!cin.eof()) {
		int n; cin >> n;
		solve(n);
	}
}