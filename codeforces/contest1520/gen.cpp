#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("in.txt","w",stdout);
	cout<<"2000 2000 1000000000"<<endl;
	int n=2000,m=2000;
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			cout<<1000000000<<" \n"[j==m];
}
