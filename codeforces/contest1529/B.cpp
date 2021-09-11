#include <bits/stdc++.h>
#define int long long
#define re(i,a,b) for(int i=a;i<=b;++i)
#define fo(i,a,b) for(int i=a;i<b;++i)
#define rre(i,a,b) for(int i=a;i>=b;--i)
#define all(a) a.begin(),a.end()
#define F first
#define S second
#define pub push_back
#define pob pop_back
#define puf push_front
#define pof pop_front
#define nmsl cout<<"NMSL\n"
#define yes cout<<"Yes\n"
#define no cout<<"No\n"
#define FAST ios_base::sync_with_stdio(0);cin.tie(0),cout.tie(0);
#define endl '\n'
#define P pair
#define mkp make_pair
#define V vector
using namespace std;
typedef priority_queue<int> mxq_i;
typedef priority_queue<int,V<int>,greater<int> > mnq_i;
typedef priority_queue<P<int,int> > mxq_p;
typedef priority_queue<P<int,int>,V<P<int,int> >,greater<P<int,int> > > mnq_p;
int read(){char ch=getchar();int s=0,w=1;while(ch<48||ch>57){if(ch=='-')w=-1;ch=getchar();}while(ch>=48&&ch<=57){s=(s<<1)+(s<<3)+ch-48;ch=getchar();}return s*w;}
void write(int x){if(x<0)putchar('-'),x=-x;if(x>9)write(x/10);putchar(x%10+48);}

const int maxn=1e6+5;
const int inf=0x3f3f3f3f3f3f3f3f;
const int mod=1e9+7;

int _,n,a[maxn];
map<int,int> mp;

bool gao() {
	V<int> v;
	int ans=-inf;
	fo(msk,1,(1ll<<n)) {
		v.clear();
		fo(j,0,n)
			if(msk&(1ll<<j))
				v.pub(a[j+1]);
		int mx=-inf;
		for(auto i:v) mx=max(mx,i);
		bool can=1;
		fo(i,0,v.size())
			fo(j,i+1,v.size())
				if(abs(v[i]-v[j])<mx) {
					can=0;
					break;
				}
		if(can) ans=max(ans,(int)v.size());
	}
	cout<<"? "<<ans<<endl;
}

V<int> use;

signed main() {
    FAST
	cin>>_;
	while(_--) {
		mp.clear();
		cin>>n;re(i,1,n) cin>>a[i];
		re(i,1,n) if(a[i]<=0) mp[a[i]]++;
		if(mp.empty()) {
			cout<<1<<endl;
			continue;
		}
		bool can=1;
		for(auto i:mp)
			if(i.S>=2) {
				can=0;
				break;
			}
		int ans=0;
		for(auto i:mp) ans+=i.S;
		if(can) {
			int mn=inf;
			re(i,1,n) if(a[i]>0) mn=min(mn,a[i]);
			bool can2=1;
			use.clear();
			for(auto i:mp) use.pub(i.F);
			fo(i,0,use.size()-1)
				if(abs(use[i]-use[i+1])<mn) {
					can2=0;
					break;
				}
			if(mn==inf) can2=0;
			if(can2) ++ans;
		}
		cout<<min(n,max(ans,1ll))<<endl;
//		gao();
	}
    return 0;
}
/*
3
3
-1 0 3
3
-4 0 3
5
-5 -4 0 1 2

1
1
1

1
2
1 0

1
1
-1
*/
