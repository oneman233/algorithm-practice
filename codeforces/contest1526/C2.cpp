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
const int maxn=1e6+5;
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

int n,a[maxn];
int mn[maxn],sum[maxn];
int lzy[maxn];

int ll(int x) {return x*2;}
int rr(int x) {return x*2+1;}

void up(int p) {
	mn[p]=min(mn[ll(p)],mn[rr(p)]);
}

void down(int p) {
	if(lzy[p]!=0) {
		mn[ll(p)]+=lzy[p];
		mn[rr(p)]+=lzy[p];
		lzy[ll(p)]+=lzy[p];
		lzy[rr(p)]+=lzy[p];
		lzy[p]=0;
	}
}

void build(int p=1,int l=0,int r=n) {
	if(l==r) {
		mn[p]=sum[l];
		return;
	}
	int m=(l+r)/2;
	build(ll(p),l,m);
	build(rr(p),m+1,r);
	up(p);
}

void modi(int L,int R,int V,int p=1,int l=0,int r=n) {
	if(L<=l&&r<=R) {
		mn[p]+=V;
		lzy[p]+=V;
		return;
	}
	int m=(l+r)/2;
	down(p);
	if(L<=m) modi(L,R,V,ll(p),l,m);
	if(R>m) modi(L,R,V,rr(p),m+1,r);
	up(p);
}

int aska(int x,int p=1,int l=0,int r=n) {
	if(l==r&&l==x) return mn[p];
	int m=(l+r)/2,tmp;
	down(p);
	if(x<=m) tmp=aska(x,ll(p),l,m);
	else tmp=aska(x,rr(p),m+1,r);
	up(p);
	return tmp;
}

int ask(int L,int R,int p=1,int l=0,int r=n) {
	if(L<=l&&r<=R) {
		return mn[p];
	}
	int m=(l+r)/2,tmp=inf;
	down(p);
	if(L<=m) mmin(tmp,ask(L,R,ll(p),l,m));
	if(R>m) mmin(tmp,ask(L,R,rr(p),m+1,r));
	up(p);
	return tmp;
}

mxq<pii> q;

signed main() {
    FAST
    cin>>n;re(i,1,n) cin>>a[i];
    int ans=0;
    re(i,1,n) ans+=a[i]>=0;
    re(i,1,n) {
		sum[i]=sum[i-1];
		sum[i]+=max(a[i],0ll);
	}
    build();
    re(i,1,n) if(a[i]<0) q.push({a[i],i});
    while(!q.empty()) {
		int val=q.top().F;
		int pos=q.top().S;
		q.pop();
		int s=aska(pos-1);
//		cout<<"pos:"<<pos-1<<endl;
//		cout<<"s:"<<s<<endl;
//		cout<<"mn:"<<ask(pos,n)<<endl;
		if(s>=0&&s+val>=0&&ask(pos,n)+val>=0) {
			++ans;
			modi(pos,n,val);
		}
	}
	cout<<ans;
    return 0;
}
