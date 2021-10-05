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
#define frt front
#define bak back
#define nmsl cout<<"NMSL\n"
#define yes cout<<"YES\n"
#define no cout<<"NO\n"
#define FAST ios_base::sync_with_stdio(0);cin.tie(0),cout.tie(0);
#define endl '\n'
#define P pair
#define V vector
#define memmx(a) memset(a,0x3f3f,sizeof(a))
#define mem0(a) memset(a,0,sizeof(a))
#define memmn(a) memset(a,-0x3f3f,sizeof(a))
#define lbd lower_bound
using namespace std;
typedef double db;
typedef P<int,int> pii;
typedef V<int> vi;
typedef V<pii> vp;
template<class T> using mxq=priority_queue<T>;
template<class T> using mnq=priority_queue<T,V<T>,greater<T> >;
template<typename T> T R(T& x) {
	char ch=getchar();
	int s=0,w=1;
	while(ch<48||ch>57)
		w=(ch=='-'?-1:1),
		ch=getchar();
	while(ch>=48&&ch<=57)
		s=(s<<1)+(s<<3)+ch-48,
		ch=getchar();
	x=s*w;
	return s*w;
}
template<typename T> void W(T x) {
	if(x<0) putchar('-'),x=-x;
	if(x>9) W(x/10);
	putchar(x%10+48);
}
void uniq(V<int> &v) {
	sort(all(v));
	v.resize(unique(all(v))-v.begin());
}
int qpow(int x,int y,int MOD) {
    x%=MOD;
    int ret=1;
    while(y) {
		if(y&1) ret=ret*x%MOD;
		x=x*x%MOD;
		y>>=1;
	}
	return ret;
}
template <typename T> void debug(const T &t) {cout<<t<<endl;}
template <typename T,typename...Args>
void debug(const T &t, const Args&...rest) {cout<<t<<' ';debug(rest...);}
void debug(vi v) {
	cout<<"DEBUG"<<endl;
	for(auto i:v) cout<<i<<' ';
	cout<<endl;
}
template <typename T> void mmin(T& a,T b) {a=min(a,b);}
template <typename T> void mmax(T& a,T b) {a=max(a,b);}
template <typename T> P<T,T> mkp(T a,T b) {return make_pair(a,b);}
template <typename T> P<T,P<T,T> > mkp(T a,T b,T c) {return make_pair(a,make_pair(b,c));}

const int maxn=1e6+5;
const int inf=0x3f3f3f3f3f3f3f3f;
const int mod=1e9+7;

//////////////////////////////////////////////////

int n,m,q;
string a[1005];
int dis[1005][1005];
bool vis[1005][1005];

int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};

bool ok(int x,int y) {
	if(x<1||x>n||y<1||y>m||a[x][y]=='#'||a[x][y]=='X') return 0;
	return 1;
}

void gao() {
	memmx(dis);
	queue<P<int,int> > q;
	int sx,sy;
	re(i,1,n) re(j,1,m) if(a[i][j]=='E') sx=i,sy=j;
	q.push({sx,sy});
	dis[sx][sy]=0;
	while(!q.empty()) {
		int x=q.front().F;
		int y=q.front().S;
		q.pop();
		if(vis[x][y]) continue;
		vis[x][y]=1;
		fo(i,0,4)
			if(ok(x+dx[i],y+dy[i])&&!vis[x+dx[i]][y+dy[i]]) {
				mmin(dis[x+dx[i]][y+dy[i]],dis[x][y]+1);
				q.push({x+dx[i],y+dy[i]});
			}
	}
}

signed main() {
    FAST
	cin>>n>>m;re(i,1,n) cin>>a[i],a[i]="$"+a[i];
	cin>>q;
	gao();
	while(q--) {
		int x,y;cin>>x>>y;
		switch(a[x][y]) {
			case '#':
				cout<<'W'<<endl;
				break;
			case 'E':
				cout<<'E'<<endl;
				break;
			case 'X':
				cout<<'X'<<endl;
				break;
			case '.':
				if(dis[x][y]==inf) {
					cout<<'?'<<endl;
					break;
				} else {
					int mn=dis[x][y];
					char ch='$';
					if(dis[x][y-1]<mn)
						mn=dis[x][y-1],
						ch='L';
					else if(dis[x+1][y]<mn)
						mn=dis[x+1][y],
						ch='D';
					else if(dis[x][y+1]<mn)
						mn=dis[x][y+1],
						ch='R';
					else if(dis[x-1][y]<mn)
						mn=dis[x-1][y],
						ch='U';
					cout<<ch<<endl;
					break;
				}
		}
	}
    return 0;
}
