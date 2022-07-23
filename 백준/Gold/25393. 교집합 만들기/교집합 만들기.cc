#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define pii pair<int,int>
int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	int n; cin >> n;
	vector<pii> a(n);
	map<int, int> mpl, mpr;
	set<pii> st;
	for(int i=0 ; i<n ; i++) {
		cin >> a[i].ff >> a[i].ss;
		st.insert(a[i]);
		if(!mpl.count(a[i].ff)) mpl[a[i].ff]=a[i].ss;
		else mpl[a[i].ff]=max(mpl[a[i].ff],a[i].ss);
		if(!mpr.count(a[i].ss)) mpr[a[i].ss]=a[i].ff;
		else mpr[a[i].ss]=min(mpr[a[i].ss],a[i].ff);
	}
	int q; cin >> q;
	while(q--) {
		int l, r; cin >> l >> r;
		if(!mpl.count(l)||!mpr.count(r)) {
			cout<<"-1\n";
			continue;
		}
		if(st.count({l,r})) {
			cout<<1<<'\n';
		}
		else if(mpl[l]>=r&&mpr[r]<=l) {
			cout<<2<<'\n';
		} else {
			cout<<-1<<'\n';
		}
	}
}