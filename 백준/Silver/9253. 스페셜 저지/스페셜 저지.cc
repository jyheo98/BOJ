#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	string s1,s2,v; cin>>s1>>s2>>v;
	int n=s1.size(), m=s2.size(), k=v.size();
	vector<int> pi(k);
	int j=0;
	for(int i=1;i<k;i++) {
		while(j>0&&v[j]!=v[i])j=pi[j-1];
		if(v[j]==v[i])pi[i]=++j;
	}
	j=0;
	bool good1=false,good2=false;
	for(int i=0;i<n;i++) {
		while(j>0&&v[j]!=s1[i])j=pi[j-1];
		if(v[j]==s1[i]) {
			j++;
			if(j==k) {
				good1=true;
				break;
			}
		}
	} 
	j=0;
	for(int i=0;i<m;i++) {
		while(j>0&&v[j]!=s2[i])j=pi[j-1];
		if(v[j]==s2[i]) {
			j++;
			if(j==k) {
				good2=true;
				break;
			}
		}
	} 	
	if(good1&&good2)puts("YES");
	else puts("NO");
}