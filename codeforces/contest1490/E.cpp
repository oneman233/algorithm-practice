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
V<P<int,int> > v;
int pre[maxn];
V<int> ans;

signed main() {
    FAST
	cin>>_;while(_--) {
		cin>>n;re(i,1,n) cin>>a[i];
		v.clear();
		v.pub({-1,-1});
		re(i,1,n) v.pub({a[i],i});
		sort(all(v));
		n=v.size()-1;
		re(i,1,n) pre[i]=pre[i-1]+v[i].F;
		re(i,1,n) {
			if(v[i].F>pre[i-1])
				while(!ans.empty()) ans.pob();
			ans.pub(v[i].S);
		}
		sort(all(ans));
		cout<<ans.size()<<endl;
		for(auto i:ans) cout<<i<<' ';cout<<endl;
	}
    return 0;
}
/*
4
5
1 1 1 1 1
3
1 1 1000000
5
1 4 5 1 1
5
1 3 5 1 1
*/
