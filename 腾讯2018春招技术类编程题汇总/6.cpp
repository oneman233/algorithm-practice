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
const int maxn=250000+5;
const int inf=0x3f3f3f3f3f3f3f3f;
const int mod=1e9+7;
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
int qpow(int x,int y) {
    x%=mod;
    int ret=1;
    while(y) {
		if(y&1) ret=ret*x%mod;
		x=x*x%mod;
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

//////////////////////////////////////////////////

int n,m;
string s[55];
int a[55][55];
vi v;

int cal() {
	int ret=0;
	for(int i=0,j=0;i<v.size();++i) {
		if(v[i]==0) continue;
		++ret;
		j=i;
		while(j<v.size()&&v[j]==1) ++j;
		i=j-1;
	}
	return ret;
}

void dfs(int i,int j,int now) {
	if(i<1||i>n||j<1||j>m) return;
	v.pub(a[i][j]==now||a[i][j]==3);
	if(now==1) {
		dfs(i+1,j-1,now);
	}
	else if(now==2) {
		dfs(i+1,j+1,now);
	}
}

signed main() {
    FAST
    cin>>n>>m;re(i,1,n) cin>>s[i],s[i]='$'+s[i];
    re(i,1,n) re(j,1,m) {
		if(s[i][j]=='B') a[i][j]=1;
    	else if(s[i][j]=='Y') a[i][j]=2;
    	else if(s[i][j]=='G') a[i][j]=3;
	}
//	re(i,1,n) re(j,1,m) cout<<a[i][j]<<" \n"[j==m];
    int ans=0;
    re(i,1,m) v.clear(),dfs(1,i,1),ans+=cal();
    re(i,2,n) v.clear(),dfs(i,m,1),ans+=cal();
    re(i,1,m) v.clear(),dfs(1,i,2),ans+=cal();
    re(i,2,n) v.clear(),dfs(i,1,2),ans+=cal();
    cout<<ans;
    return 0;
}
/*
6 5
XBGBX
YBBYB
BGGXX
XYYBG
XYBGG
YYXYX
*/
