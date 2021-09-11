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

int n,a[505][505];
int row[505],col[505];
V<P<int,int> > ans;
bool r[505],c[505];
map<int,int> delr,delc;

int tr[3][505];
int lb(int x) {return x&-x;}
void add(int id,int x,int y) {
	for(int i=x;i<=n;i+=lb(i))
		tr[id][i]+=y;
}
int sum(int id,int x) {
	int ret=0;
	for(int i=x;i>0;i-=lb(i))
		ret+=tr[id][i];
	return ret;
}

signed main() {
    FAST
	cin>>n;re(i,1,n) re(j,1,n) cin>>a[i][j];
	re(i,1,n) re(j,1,n) row[i]+=a[i][j];
	re(j,1,n) re(i,1,n) col[j]+=a[i][j];
	re(cnt,1,n) {
		int mx=-inf,pi=-1,pj=-1;
		re(i,1,n)
			re(j,1,n) {
				if(r[i]||c[j]) continue;
				if(row[i]+col[j]-a[i][j]>mx)
					mx=row[i]+col[j]-a[i][j],
					pi=i,pj=j;
			}
		r[pi]=c[pj]=1;
		re(i,1,n) if(!r[i]) row[i]-=a[i][pj];
		re(j,1,n) if(!c[j]) col[j]-=a[pi][j];
		ans.pub({pi-sum(1,pi),
				 pj-sum(2,pj)});
		add(1,pi,1),add(2,pj,1);
	}
	for(auto i:ans) cout<<i.F<<' '<<i.S<<endl;
    return 0;
}
