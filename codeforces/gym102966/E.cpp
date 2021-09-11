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

int n,m,q,rt=-1;
V<int> e[maxn];
int v[maxn],add[maxn],sum[maxn];

void dfs1(int x) {
	for(auto i:e[x])
		dfs1(i),
		add[x]+=add[i];
	v[x]+=add[x];
}

void dfs2(int x) {
	sum[x]+=v[x];
	for(auto i:e[x])
		dfs2(i),
		sum[x]+=sum[i];
}

void gao() {
	dfs1(rt);
	dfs2(rt);
}

signed main() {
    FAST
    cin>>n>>m>>q;
    re(i,1,n) {
		int j;cin>>j;
		if(j!=0) e[j].pub(i);
		else rt=i;
	}
	re(i,1,m) {
		int a,b,c;
		cin>>a>>b>>c;
		if(a==1) v[b]+=c;
		else if(a==2) add[b]+=c;
	}
	gao();
	re(i,1,q) {
		int a,b;
		cin>>a>>b;
		if(a==1) cout<<v[b]<<endl;
		else if(a==2) cout<<sum[b]<<endl;
	}
    return 0;
}
