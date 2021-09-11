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
using namespace std;
typedef double db;
typedef P<int,int> pii;
typedef V<int> vi;
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

int n,a[maxn];
vi e[maxn],discre,pos[maxn];
int fa[maxn][25],dep[maxn];

void dfs(int now,int f) {
	dep[now]=dep[f]+1;
	fa[now][0]=f;
	for(int i=1;(1<<i)<=dep[now];++i)
		fa[now][i]=fa[fa[now][i-1]][i-1];
	for(auto i:e[now])
		if(i!=f)
			dfs(i,now);
}

int lg(int x) {
	int ret=0;
	fo(i,0,25)
		if(x&(1<<i))
			mmax(ret,i);
	return ret;
}
int lca(int x,int y) {
	if(dep[x]<dep[y]) swap(x,y);
	if(dep[x]!=dep[y]) {
		int dif=dep[x]-dep[y];
		for(int i=0;i<=lg(dif);++i)
			if(dif&(1<<i))
				x=fa[x][i];
	}
	if(x==y) return x;
	for(int i=lg(dep[x]);i>=0;--i)
		if(fa[x][i]!=fa[y][i])
			x=fa[x][i],y=fa[y][i];
	return fa[x][0];
}

int dis(int x,int y) {
	return dep[x]+dep[y]-2*dep[lca(x,y)];
}

signed main() {
    FAST
    cin>>n;re(i,1,n) {
		cin>>a[i];
		discre.pub(a[i]);
	}
	uniq(discre);
	re(i,1,n) a[i]=lower_bound(all(discre),a[i])-discre.begin()+1;
	re(i,1,n) pos[a[i]].pub(i);
    re(i,1,n-1) {
		int x,y;cin>>x>>y;
		e[x].pub(y);
		e[y].pub(x);
	}
	dfs(1,1);
	int ans=inf;
	re(i,1,n) {
		if(pos[i].size()<2) continue;
		fo(j,0,pos[i].size()-1)
			fo(k,j+1,pos[i].size())
				mmin(ans,dis(pos[i][j],pos[i][k]));
	}
	cout<<(ans==inf?-1:ans);
    return 0;
}
