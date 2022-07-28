#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	string s; cin>>s;
	ll k; cin>>k;
	int n=(int)s.size();
	int j=0;
	vector<int> pi(n);
	for(int i=1;i<n;i++) {
		while(j>0&&s[i]!=s[j])j=pi[j-1];
		if(s[i]==s[j])pi[i]=++j;
	}
	ll add=n-pi[n-1];
	cout<<n+(k-1)*add<<'\n';
}
