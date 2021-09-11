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

int _,n,m;
char ch[55][55];
int nowx,nowy,box=0;
P<int,int> pos[10];
int dis[10][55][55];
bool vis[10][55][55];
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};
priority_queue<P<int,P<int,int> >, V<P<int,P<int,int> > >,greater<P<int,P<int,int> > > > q;

bool ok(int i,int j) {
	if(i<1||i>n||j<1||j>m) return 0;
	if(ch[i][j]=='#') return 0;
	return 1;
}

void dij(int p) {
	dis[p][pos[p].F][pos[p].S]=0;
	q.push(mkp(0,mkp(pos[p].F,pos[p].S)));
	while(!q.empty()) {
		int x=q.top().S.F;
		int y=q.top().S.S;
		q.pop();
		if(vis[p][x][y]) continue;
		vis[p][x][y]=1;
		fo(i,0,4) {
			int xx=x+dx[i];
			int yy=y+dy[i];
			if(!ok(xx,yy)) continue;
			if(dis[p][x][y]+1<dis[p][xx][yy])
				dis[p][xx][yy]=dis[p][x][y]+1,
				q.push(mkp(dis[p][xx][yy],mkp(xx,yy)));
		}
	}
}

bool can[10];
int cal() {
	int ret=0;
	re(i,0,box) ret+=can[i];
	return ret;
}

void gao() {
	cin>>n>>m;
	box=0;memset(dis,0x3f3f,sizeof(dis));memset(vis,0,sizeof(vis));memset(can,0,sizeof(can));
	re(i,1,n) re(j,1,m) cin>>ch[i][j];
	re(i,1,n) re(j,1,m) {
		if(ch[i][j]=='*') nowx=i,nowy=j;
		else if(isdigit(ch[i][j])) pos[ch[i][j]-'0']={i,j},box=max(box,(int)ch[i][j]-'0');
	}
	re(i,0,box) dij(i);
	int MAX=1e6,ans=0;
	while(MAX--) {
//		cout<<nowx<<' '<<nowy<<endl;
		if(isdigit(ch[nowx][nowy]))
			can[ch[nowx][nowy]-'0']=1;
		if(cal()==box+1) break;
		int mn=inf,nxt=-1;
		re(i,0,box)
			if(!can[i]&&abs(pos[i].F-nowx)+abs(pos[i].S-nowy)<mn)
				mn=abs(pos[i].F-nowx)+abs(pos[i].S-nowy),nxt=i;
		if(dis[nxt][nowx][nowy]==inf) break;
		fo(i,0,4) {
			int xx=nowx+dx[i];
			int yy=nowy+dy[i];
			if(ok(xx,yy)&&dis[nxt][xx][yy]<dis[nxt][nowx][nowy]) {
				nowx=xx;
				nowy=yy;
				++ans;
				break;
			}
		}
	}
	if(cal()!=box+1) cout<<-1<<endl;
	else cout<<ans<<endl;
}

signed main() {
    FAST
	cin>>_;while(_--) gao();
    return 0;
}
/*
3
5 5
0...1
.#.#.
..*..
.#.#.
2...3
5 5
0...1
.#.#.
..*.#
.#.#.
2.#.3
5 5
....1
.####
..*..
####.
0....
*/
