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

int qpow(int x,int y) {
	int ret=1;
	x%=mod;
	while(y) {
		if(y&1) ret=ret*x%mod;
		x=x*x%mod;
		y>>=1;
	}
	return ret;
}

int _,n,m,ans=0;
int a[14+5][6+5];
unordered_map<int,int> mp;

void dfs(int i,int now) {
	if(i==n/2+1) {
		mp[now]++;
		return;
	}
	re(j,1,6) dfs(i+1,now*a[i][j]%mod);
}

void dfs2(int i,int now) {
	if(i==n+1) {
		int tmp=m*qpow(now,mod-2)%mod;
		if(mp.count(tmp)) ans+=mp[tmp];
		return;
	}
	re(j,1,6) dfs2(i+1,now*a[i][j]%mod);
}

void gao() {
	cin>>n>>m;
	re(i,1,n) re(j,1,6) cin>>a[i][j];
	mp.clear();
	ans=0;
	dfs(1,1);
	dfs2(n/2+1,1);
	write(ans),puts("");
}

signed main() {
    FAST
	cin>>_;while(_--) gao();
    return 0;
}
