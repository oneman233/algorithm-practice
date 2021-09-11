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
int l[maxn],r[maxn];
int dep[maxn];

int build(int ll,int rr) {
	if(ll>rr) return -1;
	int p=-1,mx=-1;
	re(i,ll,rr) if(a[i]>mx) {
		mx=a[i];
		p=i;
	}
	l[p]=build(ll,p-1);
	r[p]=build(p+1,rr);
	return p;
}

void dfs(int now,int d) {
	dep[now]=d;
	if(l[now]!=-1) dfs(l[now],d+1);
	if(r[now]!=-1) dfs(r[now],d+1);
}

void gao() {
	cin>>n;re(i,1,n) cin>>a[i];
	re(i,1,n) l[i]=r[i]=-1;
	build(1,n);
	int rt=-1;
	re(i,1,n) if(a[i]==n) {
		rt=i;
		break;
	}
	dfs(rt,0);
	re(i,1,n) cout<<dep[i]<<' ';cout<<endl;
}

signed main() {
    FAST
	cin>>_;while(_--) gao();
    return 0;
}
