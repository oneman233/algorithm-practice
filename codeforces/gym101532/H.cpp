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

int _,n,m;
char ch[55][55];

void gao() {
	cin>>n>>m;re(i,1,n) re(j,1,m) cin>>ch[i][j];
	int us=0;
	re(i,2,n-1) re(j,2,m-1) us+=ch[i][j]=='1';
	int tmp=us;
	re(i,1,n) us-=ch[i][1]=='0',us-=ch[i][m]=='0',ch[i][1]=ch[i][m]='1';
	re(j,1,m) us-=ch[1][j]=='0',us-=ch[n][j]=='0';
	if(us>=0) cout<<tmp-us<<endl;
	else cout<<-1<<endl;
}

signed main() {
	FAST
	cin>>_;while(_--) gao();
	return 0;
}
