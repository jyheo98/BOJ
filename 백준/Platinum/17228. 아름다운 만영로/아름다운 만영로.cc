#include <bits/stdc++.h>

using namespace std;
#define sz(x) (int)x.size()
int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int n; cin >> n;
	vector<vector<pair<int, char>>> g(n);
	vector<set<int>> st(n);
	for(int i=0 ; i<n-1 ; i++) {
		int u, v; cin >> u >> v; u--, v--;
		char c; cin >> c;
		st[u].insert((int)(c-'a'));
		g[u].push_back({v,c});
	}
	string s; cin >> s;
	int j=0;
	vector<int> pi(sz(s));
	for(int i=1 ; i<sz(s) ; i++) {
		while(j>0 && s[i]!=s[j]) j=pi[j-1];
		if(s[i]==s[j]) pi[i]=++j;
	}
	int ans=0;
	queue<int> q; q.push(0);
	vector<int> js(n);
	while(sz(q)) {
		int cur=q.front(); q.pop();
		int curJ = js[cur];
		vector<int> a(26),pt(26);
		for(auto i : st[cur]) {
			int t=curJ;
			while(t>0&&s[t]!=(char)(i+'a')) t=pi[t-1];
			if(s[t]==(char)(i+'a')) {
				a[i]=t+1;
				if(a[i]==sz(s)) pt[i]=1, a[i]=pi[a[i]-1];
			}
		}
		for(auto nxt : g[cur]) {
			if(pt[nxt.second-'a']) ans++;
			js[nxt.first]=a[nxt.second-'a'];
			q.push(nxt.first);
		}
	}
	cout<<ans<<'\n';
}