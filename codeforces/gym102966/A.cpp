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

int n,m,ans=0;
int a[15][15];

bool ok() {
	re(i,1,n-1)
		re(j,1,m-1) {
			int tmp=a[i][j]+a[i+1][j]+a[i][j+1]+a[i+1][j+1];
			if(tmp!=2) return 0;
		}
	return 1;
}

void dfs(int x,int y) {
	if(x==n&&y==m){
		a[x][y]=1;
		if(ok()) ++ans;
		a[x][y]=0;
		if(ok()) ++ans;
		return;
	}
	a[x][y]=1;
	if(y!=m) dfs(x,y+1);
	else dfs(x+1,1);
	a[x][y]=0;
	if(y!=m) dfs(x,y+1);
	else dfs(x+1,1);
}

signed main() {
    FAST
	cin>>n>>m;if(n>m) swap(n,m);
	if(n==1) {cout<<0;return 0;}
	int i=2,j=2,ans=6,add=8;
	while(i<n) ans+=add,add*=2,++i,++j;
	add/=2;
	while(j<m) ans+=add,add*=2,++j;
//	dfs(1,1);
	cout<<ans;
    return 0;
}
