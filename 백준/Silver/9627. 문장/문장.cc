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

vector<int> hundi = {-7,3,3,5,4,4,3,5,5,4};
vector<int> ones = {0,3,3,5,4,4,3,5,5,4,3};
vector<int> shit = {6,6,8,8,7,7,9,8,8}; 
vector<int> tens = {0,0,6,6,5,5,5,7,6,6};
vector<string> hu = {"","onehundred", "twohundred", "threehundred", "fourhundred", "fivehundred", "sixhundred", "sevenhundred", "eighthundred", "ninehundred" };
vector<string> te = {"","","twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};
vector<string> shitt = {"eleven", "twelve","thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
vector<string> os = {"","one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten"};
int f(int x) {
	int hun = hundi[x/100]+7; 
	x%=100; 
	if(x<=10) return hun+ones[x];
	else if(x<=19) return hun+shit[x-11];
	else {
		hun += tens[x/10];
		x %= 10;
		hun += ones[x];
		return hun;
	}
}

void ff(int x) {
	cout << hu[x/100];
	x%=100;
	if(x<=10) {
		cout<<os[x];
	} else if(x<=19) {
		cout<<shitt[x-11];
	} else {
		cout<<te[x/10];
		x%=10;
		cout<<os[x];
	}
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int n; cin >> n;
	vector<string> a(n);
	int sum = 0;
	for(int i=0 ; i<n ; i++) {
		cin >> a[i];
		if(a[i]!="$") {
			sum+=sz(a[i]);
		}
	}
	for(int i=1 ; i<=999 ; i++) {
		if(sum+f(i)==i) {
			for(auto x : a) {
				if(x!="$")
					cout << x << ' ';
				else {
					ff(i);
					cout << " ";
				}
			}
			return 0;
		}
	}
}