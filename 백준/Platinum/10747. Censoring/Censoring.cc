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

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	string s,t; cin>>s>>t;	
	int j=0; vector<int>pi(sz(t));
	for(int i=1;i<sz(t);i++) {
		while(j>0&&t[i]!=t[j])j=pi[j-1];
		if(t[i]==t[j])pi[i]=++j;
	}
	vector<int> id(sz(s),-1);
	j=0;
	stack<int> st;
	for(int i=0;i<sz(s);i++) {
		st.push(i);
		while(j>0&&t[j]!=s[i])j=pi[j-1];
		if(t[j]==s[i]){
			id[i]=j;
			j++;
			if(j==sz(t)){
				int x=sz(t);
				while(x--) st.pop();
				if(!st.empty())
					j=id[st.top()]+1;
				else 
					j=0;
			}
		}
	}
	string ans="";
	while(!st.empty()) {
		ans+=s[st.top()];st.pop();
	}
	reverse(all(ans));
	cout<<ans;
}