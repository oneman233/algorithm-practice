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

const int maxn=1000005;
const int inf=0x3f3f3f3f3f3f3f3f;

int n,m;
int tot=0;
string s;
map<string,int> ha;
V<int> e[maxn],e2[maxn];
int c[maxn];
map<int,int> cnt,vis;

bool dfs(int now,int x) {
	cnt[x]++;
	c[now]=x;
	for(auto i:e2[now]) {
		if(c[now]==c[i]) return 0;
		if(c[i]==0&&!dfs(i,-x)) return 0;
	}
	return 1;
}

void dfs2(int now) {
	if(vis[now]) return;
	vis[now]=1;
	c[now]=-c[now];
	for(auto i:e2[now]) dfs2(i);
}

signed main() {
    FAST
	cin>>n>>m;
	re(i,1,m) {
		int k;cin>>k;
		while(k--) {
			cin>>s;
			if(ha[s]==0) ha[s]=++tot;
			e[ha[s]].pub(i);
		}
	}
	re(i,1,n)
		if(e[i].size()>2) {
			cout<<"NO";
			return 0;
		}
	re(i,1,n)
		if(e[i].size()==2)
			e2[e[i][0]].pub(e[i][1]),
			e2[e[i][1]].pub(e[i][0]);
	bool can=1;
	re(i,1,m)
		if(c[i]==0) {
			cnt.clear();
			if(!dfs(i,1)) {
				can=0;
				break;
			}
			if(cnt[1]<cnt[-1])
				dfs2(i);
		}
	if(!can) {
		cout<<"NO";
		return 0;
	}
	cout<<"YES"<<endl;
	re(i,1,m) cout<<(c[i]==1?"Saturday":"Sunday")<<endl;
    return 0;
}
