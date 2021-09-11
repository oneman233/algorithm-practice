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
const int mod=10000;

//////////////////////////////////////////////////

int _,n,m,a[105][105];
int ans[105][105];
bool vis[105][105];
stack<pii> st;

bool ok(int i,int j) {
	if(i<1||i>n||j<1||j>m) return 0;
	return 1;
}

void dfs(int i,int j,int stp,int fi,int fj) {
	if(stp==-1||vis[i][j]) return;
	if(i!=fi||j!=fj) ans[i][j]=(ans[i][j]+ans[fi][fj])%mod;
	vis[i][j]=1;
	st.push({i,j});
	if(ok(i+1,j)) dfs(i+1,j,stp-1,fi,fj);
	if(ok(i,j+1)) dfs(i,j+1,stp-1,fi,fj);
}

signed main() {
    FAST
    cin>>_;while(_--) {
		cin>>n>>m;re(i,1,n) re(j,1,m) cin>>a[i][j];
		mem0(ans);
		ans[1][1]=1;
		re(i,1,n) re(j,1,m) {
			while(!st.empty()) vis[st.top().F][st.top().S]=0,st.pop();
			dfs(i,j,a[i][j],i,j);
		}
//		re(i,1,n) re(j,1,m) cout<<ans[i][j]<<" \n"[j==m];
		cout<<ans[n][m]<<endl;
	}
    return 0;
}
/*
1
3 3
2 1 1
1 1 1
1 1 1
*/
