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

const int maxn=4e6+5;
const int inf=0x3f3f3f3f3f3f3f3f;
const int mod=1e9+7;

int n,m,w;
int a[2005][2005];
int from,to;
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
bool vis[2][maxn];
int dis[2][maxn];
queue<int> q;

int ha(int i,int j) {
	return (i-1)*m+j;
}

bool ok(int i,int j) {
	if(i<1||i>n||j<1||j>m) return 0;
	if(a[i][j]==-1) return 0;
	return 1;
}

void bfs(int id,int start) {
	dis[id][start]=0;
	q.push(start);
	while(!q.empty()) {
		int f=q.front();
		q.pop();
		if(vis[id][f]) continue;
		vis[id][f]=1;
		int i=(f-1)/m+1,j=f-(i-1)*m;
		fo(k,0,4) {
			int ii=i+dx[k],jj=j+dy[k];
			if(!ok(ii,jj)) continue;
			dis[id][ha(ii,jj)]=min(dis[id][ha(ii,jj)],dis[id][f]+1);
			if(!vis[id][ha(ii,jj)]) q.push(ha(ii,jj));
		}
	}
}

signed main() {
//	freopen("in.txt","r",stdin);
	n=read(),m=read(),w=read();re(i,1,n) re(j,1,m) a[i][j]=read();
	from=ha(1,1),to=ha(n,m);
	memset(dis,0x3f3f,sizeof(dis));
	bfs(0,from);bfs(1,to);
	int mn=inf,ans=(dis[0][to]==inf?inf:dis[0][to]*w);
	re(i,1,n) re(j,1,m) if(a[i][j]!=0&&a[i][j]!=-1)
		if(dis[0][ha(i,j)]!=inf)
			mn=min(mn,dis[0][ha(i,j)]*w+a[i][j]);
	re(i,1,n) re(j,1,m) if(a[i][j]!=0&&a[i][j]!=-1)
		if(dis[1][ha(i,j)]!=inf)
			ans=min(ans,mn+a[i][j]+dis[1][ha(i,j)]*w);
	write(ans>=inf?-1:ans);
    return 0;
}

