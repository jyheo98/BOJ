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
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2")
#include <sys/stat.h>
#include <sys/mman.h>
#include <unistd.h>
using pii = pair<int, int>;
using ll = long long;
using ld = long double;
const ll MOD = 1e9 + 7;
const long double PI = acos(-1.0);

/////////////////////////////////////////////////////////////////////////////////////////////
/*
 * Author : jinhan814
 * Date : 2021-05-06
 * Source : https://blog.naver.com/jinhan814/222266396476
 * Description : FastIO implementation for cin, cout. (mmap ver.)
 */
constexpr int SZ = 1 << 20;

class INPUT {
private:
	char* p;
	bool __END_FLAG__, __GETLINE_FLAG__;
public:
	explicit operator bool() { return !__END_FLAG__; }
    INPUT() {
        struct stat st; fstat(0, &st);
        p = (char*)mmap(0, st.st_size, PROT_READ, MAP_SHARED, 0, 0);
    }
	bool IsBlank(char c) { return c == ' ' || c == '\n'; }
	bool IsEnd(char c) { return c == '\0'; }
	char _ReadChar() { return *p++; }
	char ReadChar() {
		char ret = _ReadChar();
		for (; IsBlank(ret); ret = _ReadChar());
		return ret;
	}
	template<typename T> T ReadInt() {
		T ret = 0; char cur = _ReadChar(); bool flag = 0;
		for (; IsBlank(cur); cur = _ReadChar());
		if (cur == '-') flag = 1, cur = _ReadChar();
		for (; !IsBlank(cur) && !IsEnd(cur); cur = _ReadChar()) ret = 10 * ret + (cur & 15);
		if (IsEnd(cur)) __END_FLAG__ = 1;
		return flag ? -ret : ret;
	}
	string ReadString() {
		string ret; char cur = _ReadChar();
		for (; IsBlank(cur); cur = _ReadChar());
		for (; !IsBlank(cur) && !IsEnd(cur); cur = _ReadChar()) ret.push_back(cur);
		if (IsEnd(cur)) __END_FLAG__ = 1;
		return ret;
	}
	double ReadDouble() {
		string ret = ReadString();
		return stod(ret);
	}
	string getline() {
		string ret; char cur = _ReadChar();
		for (; cur != '\n' && !IsEnd(cur); cur = _ReadChar()) ret.push_back(cur);
		if (__GETLINE_FLAG__) __END_FLAG__ = 1;
		if (IsEnd(cur)) __GETLINE_FLAG__ = 1;
		return ret;
	}
	friend INPUT& getline(INPUT& in, string& s) { s = in.getline(); return in; }
} _in;

class OUTPUT {
private:
	char write_buf[SZ];
	int write_idx;
public:
	~OUTPUT() { Flush(); }
	explicit operator bool() { return 1; }
	void Flush() {
        write(1, write_buf, write_idx);
		write_idx = 0;
	}
	void WriteChar(char c) {
		if (write_idx == SZ) Flush();
		write_buf[write_idx++] = c;
	}
	template<typename T> int GetSize(T n) {
		int ret = 1;
		for (n = n >= 0 ? n : -n; n >= 10; n /= 10) ret++;
		return ret;
	}
	template<typename T> void WriteInt(T n) {
		int sz = GetSize(n);
		if (write_idx + sz >= SZ) Flush();
		if (n < 0) write_buf[write_idx++] = '-', n = -n;
		for (int i = sz; i --> 0; n /= 10) write_buf[write_idx + i] = n % 10 | 48;
		write_idx += sz;
	}
	void WriteString(string s) { for (auto& c : s) WriteChar(c); }
	void WriteDouble(double d) { WriteString(to_string(d)); }
} _out;

/* operators */
INPUT& operator>> (INPUT& in, char& i) { i = in.ReadChar(); return in; }
INPUT& operator>> (INPUT& in, string& i) { i = in.ReadString(); return in; }
template<typename T, typename std::enable_if_t<is_arithmetic_v<T>>* = nullptr>
INPUT& operator>> (INPUT& in, T& i) {
	if constexpr (is_floating_point_v<T>) i = in.ReadDouble();
	else if constexpr (is_integral_v<T>) i = in.ReadInt<T>(); return in; }

OUTPUT& operator<< (OUTPUT& out, char i) { out.WriteChar(i); return out; }
OUTPUT& operator<< (OUTPUT& out, string i) { out.WriteString(i); return out; }
template<typename T, typename std::enable_if_t<is_arithmetic_v<T>>* = nullptr>
OUTPUT& operator<< (OUTPUT& out, T i) {
	if constexpr (is_floating_point_v<T>) out.WriteDouble(i);
	else if constexpr (is_integral_v<T>) out.WriteInt<T>(i); return out; }

/* macros */
#define fastio 1
#define cin _in
#define cout _out
#define istream INPUT
#define ostream OUTPUT
/////////////////////////////////////////////////////////////////////////////////////////////

int nk; 
string s = "";

void make_sa() {
	int n = sz(s), m = max(256, n)+1;
	vector<int> r(n+1), nr(n+1);
    vector<int> sa(n), isa(n), cnt(m), idx(n), lcp(n);
    for(int i=0 ; i<n ; i++) sa[i] = i, r[i] = s[i];
    for(int d=1 ; d<n ; d *= 2){
        auto cmp = [&](int i,int j){
            return r[i] < r[j] || (r[i] == r[j] && r[min(n,i+d)] < r[min(n,j+d)]); };

        for(int i=0 ; i<m ; i++) cnt[i] = 0;
        for(int i=0 ; i<n ; i++) cnt[r[min(n,i+d)]]++;
        for(int i=1 ; i<m ; i++) cnt[i] += cnt[i-1];
        for(int i=n-1 ; ~i ; i--) idx[--cnt[r[min(n,i+d)]]] = i;

        for(int i=0 ; i<m ; ++i) cnt[i] = 0;
        for(int i=0 ; i<n ; ++i) cnt[r[i]]++;
        for(int i=1 ; i<m ; ++i) cnt[i] += cnt[i-1];
        for(int i=n-1 ; ~i ; --i) sa[--cnt[r[idx[i]]]] = idx[i];

        nr[sa[0]] = 1;
        for(int i=1 ; i<n ; ++i) nr[sa[i]] = nr[sa[i-1]] + cmp(sa[i-1], sa[i]);
        for(int i=0 ; i<n ; ++i) r[i] = nr[i];

        if(r[sa[n-1]]==n) break;
    }
	for(int i=0 ; i<n ; i++) {
		isa[sa[i]] = i;
	}
    for(int k=0, i=0 ; i<n ; i++) if(isa[i]) {
        for(int j=sa[isa[i]-1]; s[i+k]==s[j+k]; ++k);
        lcp[isa[i]] = (k ? k-- : 0);
    }
    vector<int> what(n);
    int c=0;
    for(int i=0 ; i<n ; i++) {
    	what[i] = c;
    	if(s[i] < 'a' || s[i] > 'z') c++;
    }
    int state = 0;
    vector<int> cnts(nk);
    vector<vector<int>> sparse_table(21, vector<int>(n));
    for(int i=0 ; i<n ; i++) {
    	sparse_table[0][i] = lcp[i];
    }
    vector<int> log(n+1);
   	log[1] = 0;
   	for(int i=2 ; i<=n ; i++)
   		log[i] = log[i/2] + 1;
    for(int pw=1 ; pw<21 ; pw++) {
    	for(int i=0 ; i+(1LL<<(pw-1))<n ; i++) {
    		sparse_table[pw][i] = min(sparse_table[pw-1][i], sparse_table[pw-1][i+(1LL<<(pw-1))]);
    	}
    }
    auto get_min = [&](int s, int e) {
    	int lg = log[e-s+1];
    	return min(sparse_table[lg][s],sparse_table[lg][e-(1<<lg)+1]);
    };
    int lid=0, rid=0;
    int ans = 0;
    while(rid<n) {
		int cur = what[sa[rid]];
		state |= (1<<cur);
		cnts[cur]++;
		if(state == (1<<nk)-1) {
			while(1) {
				if(cnts[what[sa[lid]]] == 1) break;
				cnts[what[sa[lid]]]--; lid++;
			}
			ans = max(ans, get_min(lid+1,rid));
			cnts[what[sa[lid]]]--;
			state ^= (1<<what[sa[lid]]);
			lid++;
		}
		rid++;
    }
    cout << ans << '\n';
}

int main() {
	cin >> nk;
	int tot = (1<<27)-1;
	string shit = "!@#$%^&*()_+[]";
	for(int i=0 ; i<nk ; i++) {
		string t; cin >> t; 
		ll z = 0;
		for(char c : t) z |= (1<<(c-'a'));
		tot &= z;
		t += shit[i];
		s += t;
	}
	if(!tot) {
		cout << 0 << '\n';
		return 0;
	}
	make_sa();
}