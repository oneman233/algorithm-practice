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
const int mod=998244353;

int n,dp[maxn];
int pre[maxn];

int fac[maxn],low[maxn];
bool isp[maxn];
V<int> p;
void gao3() {
	re(i,2,1e6) {
		if(!isp[i])
			p.pub(i),
			fac[i]=2,
			low[i]=1;
		for(auto j:p) {
			if(j*i>maxn) break;
			isp[j*i]=1;
			if(i%j==0) {
				fac[j*i]=fac[i]/(low[i]+1)*(low[i]+2);
				low[j*i]=low[i]+1;
			}
			else
				fac[j*i]=fac[i]*fac[j],
				low[j*i]=1;
		}
	}
}

void gao() {
	gao3();
	cin>>n;
	dp[1]=1,pre[1]=1;
	dp[2]=3,pre[2]=4;
	dp[3]=6,pre[3]=10;
	re(i,4,n)
		dp[i]=(pre[i-1]+fac[i])%mod,
		pre[i]=(pre[i-1]+dp[i])%mod;
	cout<<dp[n];
}

int m,ans=0;
int lk[maxn];

bool can(P<int,int> a,P<int,int> b) {
	if(a.F<b.F&&a.S>b.S) return 1;
	if(b.F<a.F&&b.S>a.S) return 1;
	if(a.S-a.F==b.S-b.F) return 1;
	return 0;
}

bool ok() {
//	re(i,1,m) cout<<lk[i]<<' ';cout<<endl;
	V<P<int,int> > v;
	re(i,1,m) if(lk[i]>i) v.pub({i,lk[i]});
	fo(i,0,v.size())
		fo(j,0,v.size())
			if(!can(v[i],v[j]))
				return 0;
	return 1;
}

void dfs(int now) {
	if(now==m+1) {
		if(ok()) ++ans;
		return;
	}
	if(lk[now]) {
		dfs(now+1);
		return;
	}
	re(i,now+1,m)
		if(lk[i]==0) {
			lk[now]=i;
			lk[i]=now;
			dfs(now+1);
			lk[now]=lk[i]=0;
		}
}

void gao2() {
	cin>>m;m*=2;
	dfs(1);
	cout<<ans;
}

signed main() {
    FAST
	gao();
//	gao2();
    return 0;
}
