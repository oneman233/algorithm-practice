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

int n;
vi tmp,ans;
bool v[10];

void gao(vi& a,vi b) {
	if(a.size()<b.size()) return;
	else if(a.size()>b.size()) {
		a=b;
		return;
	}
	bool can=0;
	fo(i,0,a.size()) {
		if(a[i]>b[i]) {
			can=1;
			break;
		}
		else if(a[i]<b[i]) break;
	}
	if(can) a=b;
}

void dfs(int now) {
	if(now==0) {
		if(ans.empty()) ans=tmp;
		else gao(ans,tmp);
		return;
	}
	re(i,1,9)
		if(v[i]==0&&now>=i)
			tmp.pub(i),
			v[i]=1,
			dfs(now-i),
			tmp.pob(),
			v[i]=0;
}

signed main() {
    FAST
    cin>>n;
    int sum=0;
    re(i,1,9) sum+=i;
//    cout<<sum<<endl;
	if(n>sum) {
		cout<<-1;
		return 0;
	}
	dfs(n);
	for(auto i:ans) cout<<i;
    return 0;
}
