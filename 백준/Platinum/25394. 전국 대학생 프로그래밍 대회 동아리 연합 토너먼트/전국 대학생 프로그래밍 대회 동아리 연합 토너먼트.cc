#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define ll long long
#define pii pair<int,int>
#define sz(x) (int)x.size()
vector<vector<int>> g;
	int loser = -1;
	int winner = -1;
	int maxdep=-1;
vector<pii> ans;
int bad[1<<21],siz[1<<21],dep[1<<21],intended[1<<21];
void dfs(int v, int b, int intendedsiz) {
	siz[v]=1;
	bad[v]=b;
	for(int nxt : g[v]) {
		dep[nxt]=dep[v]+1;
		dfs(nxt,b,intendedsiz/2);
		siz[v]+=siz[nxt];
	}
	
}void dfs2(int v){
	vector<int> sizes;
	if(dep[v]==maxdep) {
		ans.push_back({v+1,loser+1});
	} else if(dep[v]>maxdep) {
		ans.clear();
		maxdep=dep[v];
		ans.push_back({v+1,loser+1});
	}
	for(auto nxt:g[v]){
		sizes.push_back(siz[nxt]);
	}
	sort(sizes.begin(),sizes.end());
	int w=1;
	int ret=0;
	for(auto i:sizes){
		if(i==w){
			w*=2;
			continue;
		}
	}
	for(auto nxt:g[v]){
		if(siz[nxt]+siz[loser]==w) {
			dfs2(nxt);
		}
	}
}

int main() {
	ios::sync_with_stdio(0);cin.tie(0);
	int n; cin >> n;
	int orign = n;
	n = (1<<n);
	g = vector<vector<int>>(n);
	vector<int> win(n), lose(n);
	vector<pii> edge;
	for(int i=0 ; i<n-2 ; i++) {
		int w, l; cin >> w >> l; w--, l--;
		edge.push_back({w,l});
		win[w]++;
		lose[l]++;
	}
	vector<int> hubo;
	for(int i=0 ; i<n ; i++) {
		if(lose[i] == 0) {
			hubo.push_back(i);
		}
	}
	assert(sz(hubo)==2);
	if(win[hubo[0]] == win[hubo[1]]) {
		if(hubo[0] > hubo[1]) {
			swap(hubo[0], hubo[1]);
		} 
		cout<<hubo[0]+1<<' '<<hubo[1]+1<<'\n';
		cout<<hubo[1]+1<<' '<<hubo[0]+1<<'\n';
		return 0;
	}
	if(win[hubo[0]] > win[hubo[1]]) winner = hubo[0],loser = hubo[1];
	else winner = hubo[1], loser = hubo[0];
	for(int i=0 ; i<sz(edge) ; i++) {
		g[edge[i].ff].push_back(edge[i].ss);	
	}
	vector<bool> vis(n);
	dfs(winner,0,orign);
	dfs(loser,1,-1);
	dfs2(winner);
	//cout<<siz[loser]<<'\n';
	// for(int i=0 ; i<n ; i++) {
	// 	//cout<<dep[i]<<'\n';
	// 	if(bad[i]) continue;
	// 	if(siz[i]+siz[loser]==intendedsiz[i]&&mxdep==dep[i]) {
	// 		ans.push_back({i+1,loser+1});
	// 	} else if(siz[i]+siz[loser]==intend[i]&&mxdep<dep[i]) {
	// 		mxdep=dep[i];
	// 		ans.clear();
	// 		ans.push_back({i+1,loser+1});
	// 	}
	// }
	sort(ans.begin(),ans.end());
	for(auto x : ans ) cout<<x.ff << ' ' <<x.ss<<'\n';
}
