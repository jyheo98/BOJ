#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(false);cin.tie(0)
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
const long double e = 1e-9;

// Copied from Gennady-Korotkevich's template

#define LOCAL

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

struct Point2D {
	long double x;
	long double y;
};

void solve() {
	int n; cin >> n;
	vector<Point2D> a(n);
	long double minFloor = INF, maxFloor = -INF;
	for(int i=0 ; i<n ; i++) {
		cin >> a[i].x >> a[i].y;
		if(a[i].y == 0) {
			minFloor = min(minFloor, a[i].x);
			maxFloor = max(maxFloor, a[i].x);
		}
	}
	long double cX = 0;
	long double W = 0;
	for(int i=0 ; i<n ; i++) {
		W += a[i].x * a[(i+1)%n].y - a[i].y * a[(i+1)%n].x;
	}
	for(int i=0 ; i<n ; i++) {
		cX += (a[i].x + a[(i+1)%n].x) * (a[i].x * a[(i+1)%n].y - a[(i+1)%n].x * a[i].y);
	}
	W /= 2.0;
	cX /= W * 6;
	if(W < 0) {
		W = -W;
	}
	if(minFloor - e > cX && a[0].x <= minFloor || cX > maxFloor + e && a[0].x >= maxFloor) {
		cout << "unstable\n";
		return;
	} 
	if(cX + e < minFloor) {
		long double M = W * (minFloor - cX) / (a[0].x - minFloor);
		M += e;
		cout << (int)M << " .. ";
	} else if(cX - e > maxFloor) {
		long double M = W * (maxFloor - cX) / (a[0].x - maxFloor);
		M += e;
		cout << (int)M << " .. ";
	} else {
		cout << "0 .. ";
	}
	if(a[0].x >= minFloor && a[0].x <= maxFloor) {
		cout << "inf" << "\n";
	} else if(a[0].x < minFloor) {
		long double M = W * (minFloor - cX) / (a[0].x - minFloor);
		M += 1;
		M -= e;
		cout << (int)M << "\n"; 
	} else {
		long double M = W * (maxFloor - cX) / (a[0].x - maxFloor);
		M += 1;
		M -= e;
		cout << (int)M << "\n";
	}
}

int main() {
	IOS;
	int t = 1;
	while(t--)
		solve();
}