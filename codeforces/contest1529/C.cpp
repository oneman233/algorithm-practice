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

int _,n,l[maxn],r[maxn];
V<int> e[maxn];
int dp[maxn][2];

void dfs(int x,int f) {
	for(auto i:e[x])
		if(i!=f)
			dfs(i,x),
			dp[x][0]+=max(dp[i][0]+abs(l[x]-l[i]),dp[i][1]+abs(l[x]-r[i])),
			dp[x][1]+=max(dp[i][0]+abs(r[x]-l[i]),dp[i][1]+abs(r[x]-r[i]));
}

signed main() {
    FAST
	cin>>_;
	while(_--) {
		cin>>n;re(i,1,n) cin>>l[i]>>r[i];
		re(i,1,n) e[i].clear();
		re(i,1,n-1) {
			int x,y;
			cin>>x>>y;
			e[x].pub(y);
			e[y].pub(x);
		}
		re(i,1,n) dp[i][0]=dp[i][1]=0;
		dfs(1,-1);
		cout<<max(dp[1][0],dp[1][1])<<endl;
	}
    return 0;
}
