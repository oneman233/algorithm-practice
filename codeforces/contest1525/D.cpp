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

const int maxn=5005;
const int inf=0x3f3f3f3f3f3f3f3f;
const int mod=1e9+7;

int n,a[maxn],dp[maxn][maxn];
V<int> pos[2];

signed main() {
    FAST
	cin>>n;re(i,1,n) cin>>a[i];
	pos[0].pub(-1),pos[1].pub(-1);
	re(i,1,n) pos[a[i]].pub(i);
	memset(dp,0x3f3f,sizeof(dp));
	fo(j,0,pos[0].size()) dp[0][j]=0;
	fo(i,1,pos[1].size())
		fo(j,1,pos[0].size())
			dp[i][j]=min(dp[i-1][j-1]+abs(pos[1][i]-pos[0][j]),dp[i][j-1]);
	cout<<dp[pos[1].size()-1][pos[0].size()-1];
    return 0;
}
