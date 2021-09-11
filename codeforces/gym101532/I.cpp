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
#define V vector
using namespace std;
typedef priority_queue<int> mxq_i;
typedef priority_queue<int,V<int>,greater<int> > mnq_i;
typedef priority_queue<P<int,int> > mxq_p;
typedef priority_queue<P<int,int>,V<P<int,int> >,greater<P<int,int> > > mnq_p;
int read(){char ch=getchar();int s=0,w=1;while(ch<48||ch>57){if(ch=='-')w=-1;ch=getchar();}while(ch>=48&&ch<=57){s=(s<<1)+(s<<3)+ch-48;ch=getchar();}return s*w;}
void write(int x){if(x<0)putchar('-'),x=-x;if(x>9)write(x/10);putchar(x%10+48);}

const int maxn=200005;
const int inf=0x3f3f3f3f3f3f3f3f;
const int mod=1e9+7;

int _,n,a[maxn];
int mp[maxn];
vector<int> e[maxn];
int dis[maxn],deg[maxn];
queue<int> q;

void topo() {
	re(i,1,n) dis[i]=inf;
	dis[n]=0;
	q.push(n);
	while(!q.empty()) {
		int f=q.front();
		q.pop();
		for(auto i:e[f]) {
			dis[i]=min(dis[i],dis[f]+1);
			deg[i]--;
			if(!deg[i]) q.push(i);
		}
	}
}

void gao() {
	n=read();re(i,1,n) a[i]=read();
	memset(mp,0,sizeof(mp));
	re(i,1,n) deg[i]=0;
	re(i,1,n) e[i].clear();
	re(i,1,n) {
		if(mp[a[i]]!=0) e[i].pub(mp[a[i]]),deg[mp[a[i]]]++;
		if(i!=1) e[i].pub(i-1),deg[i-1]++;
		mp[a[i]]=i;
	}
	topo();
	write(dis[1]),puts("");
}

signed main() {
	_=read();while(_--) gao();
    return 0;
}
