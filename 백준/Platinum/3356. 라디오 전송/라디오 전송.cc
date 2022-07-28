#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int n; cin>>n;
	string s; cin>>s;
	int j=0;
	vector<int>pi(n);
	for(int i=1;i<n;i++) {
		while(j>0&&s[i]!=s[j]) j=pi[j-1];
		if(s[i]==s[j]) pi[i]=++j;
	}
	cout<<n-pi[n-1];
}