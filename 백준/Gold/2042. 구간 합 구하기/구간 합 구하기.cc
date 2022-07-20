#define LOCAL

#undef _GLIBCXX_DEBUG

#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(false);cin.tie(0)
#define all(x) x.begin(), x.end()
#define ff first
#define ss second
#define LLINF 1e18
#define INF (int)1e9+1

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

using llong = long long;
using PII = pair<int, int>;

const llong MOD = 1e9 + 7;
const double PI = acos(-1);

const int N = 1000100;
llong seg[N * 4], a[N];
int n, m, k;

llong build(int idx, int ll, int rr) {
	if (ll == rr) return seg[idx] = a[ll];
	int mid = (ll + rr) >> 1;
	return seg[idx] = build(idx * 2, ll, mid) + build(idx * 2 + 1, mid + 1, rr);
}

llong upd(int idx, int ll, int rr, int ch, llong val) {
	if (ll == rr && ll == ch) return seg[idx] = val;
	if (ch < ll || ch > rr) return seg[idx];
	int mid = (ll + rr) >> 1;
	return seg[idx] = upd(idx * 2, ll, mid, ch, val) + upd(idx * 2 + 1, mid + 1, rr, ch, val);
}

llong sum(int idx, int ll, int rr, int ql, int qr) {
	if (ql > qr) return 0;
	if (ll == ql && rr == qr) return seg[idx];
	int mid = (ll + rr) >> 1;
	return sum(idx * 2, ll, mid, ql, min(qr, mid)) 
		+ sum(idx * 2 + 1, mid + 1, rr, max(mid + 1, ql), qr);
}

int main() {
	IOS;
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	build(1, 0, n - 1);
	for (int i = 0; i < m + k; i++) {
		llong q, l, r; cin >> q >> l >> r;
		if (q == 1) {
			upd(1, 0, n-1, l-1, r);
		}
		if (q == 2) {
			cout << sum(1, 0, n-1, l-1, r-1) << "\n";
		}
	}
}