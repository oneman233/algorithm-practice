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

int n,a[maxn];
map<int,int> pos;
int vis[365];

int f[maxn],cnt[maxn];
int _f(int x) {
	if(f[x]==x) return x;
	else return f[x]=_f(f[x]);
}
void _m(int x,int y) {
	x=_f(x),y=_f(y);
	if(x==y) return;
	f[x]=y;
	cnt[y]+=cnt[x];
}

signed main() {
    FAST
	cin>>n;re(i,1,n) cin>>a[i];
	sort(a+1,a+1+n);re(i,1,n) pos[a[i]]=i;
	int ans=1;
	re(add,1,359) {
		re(i,1,n) f[i]=i,cnt[i]=1;
		re(i,1,n) if(pos[(a[i]+add)%360]!=0) _m(i,pos[(a[i]+add)%360]);
		mem0(vis);
		int tmp=0;
		re(i,1,n) if(!vis[_f(i)]) tmp+=cnt[_f(i)]/2,vis[_f(i)]=1;
		mmax(ans,tmp);
	}
	cout<<ans;
    return 0;
}
/*
7
0 1 2 3 81 80 83

7
0 1 2 3 81 82 83

4
0 359 1 2

7
0 359 1 2 8 9 10
*/
