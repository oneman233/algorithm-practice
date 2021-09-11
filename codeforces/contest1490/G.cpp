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

int _,n,m,a[maxn],x[maxn];
int ans[maxn];

int mn[maxn];
V<P<int,int> > v;

bool cmp(P<int,int> a,P<int,int> b) {
	return a.F<b.F;
}

void gao1() {
	int sum=0;
	v.clear();
	re(i,1,m) v.pub({x[i],i});
	sort(all(v));
//	for(auto i:v) cout<<i.F<<' '<<i.S<<endl;
	fo(i,0,m) mn[i]=inf;
	re(i,1,n) {
		sum+=a[i];
		int j=upper_bound(all(v),mkp(sum,-1),cmp)-v.begin();
//		cout<<"sum:"<<sum<<' '<<j<<endl;
		if(j==0) continue;
		--j;
//		cout<<"mn:"<<j<<'='<<i-1<<endl;
		mn[j]=min(mn[j],i-1);
	}
	rre(i,m-2,0) mn[i]=min(mn[i],mn[i+1]);
	fo(i,0,m) ans[v[i].S]=(mn[i]==inf?-1:mn[i]);
}

int add[maxn];
void gao2() {
//	nmsl;
	re(i,1,m) add[i]=0;
	int sum=0,mx=-inf;
	re(i,1,n) sum+=a[i],mx=max(mx,sum);
	re(i,1,m) if(x[i]>mx) {
		if(sum<0) {
			x[i]=-1;
			add[i]=-1;
			continue;
		}
		int k=(x[i]-mx)/sum;
		if((x[i]-mx)%sum!=0) ++k;
		add[i]=k*n;
		x[i]-=sum*k;
	}
	gao1();
	re(i,1,m)
		if(add[i]!=-1) ans[i]+=add[i];
		else ans[i]=-1;
}

void gao() {
	int sum=0;
	cin>>n>>m;re(i,1,n) cin>>a[i],sum+=a[i];re(i,1,m) cin>>x[i];
	re(i,1,m) ans[i]=0;
	if(sum==0) gao1();
	else gao2();
	re(i,1,m) cout<<ans[i]<<' ';cout<<endl;
}

signed main() {
    FAST
	cin>>_;while(_--) gao();
    return 0;
}
/*
1
5 4
1 1 1 -1 -2
3 2 1 5

2 1 0 -1

1
3 5
1 0 -2
-1 -2 1 2 0

0 0 0 -1 0
*/
