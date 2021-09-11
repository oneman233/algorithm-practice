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

int _,n,r[maxn],c[maxn];
V<P<int,int> > v;

int add(P<int,int> p) {
	return p.F+p.S;
}

int cal(P<int,int> from,P<int,int> to) {
	if(from==to) return 0;
	if(add(from)%2==0) to.F-=from.F-1,to.S-=from.S-1,from.F=from.S=1;
	else to.F-=from.F-2,to.S-=from.S-1,from.F=2,from.S=1;
//	cout<<from.F<<','<<from.S<<"->"<<to.F<<','<<to.S<<endl;
	if(to.S==to.F) return to.F-from.F;
	if(to.S==to.F-1) return 0;
	return (to.F-to.S)/2;
}

void gao() {
	v.clear();
	v.push_back({1,1});
	cin>>n;re(i,1,n) cin>>r[i];re(i,1,n) cin>>c[i];
	re(i,1,n) v.pub({r[i],c[i]});
	sort(all(v));
	int ans=0;
	fo(i,0,v.size()-1) ans+=cal(v[i],v[i+1]);
	cout<<ans<<endl;
}

int dis[1005][1005];
void gao2() {
	memset(dis,0x3f3f,sizeof(dis));
	dis[1][1]=0;
	re(i,1,1000)
		re(j,1,i)
			if((i+j)%2==0)
				dis[i+1][j]=min(dis[i+1][j],dis[i][j]),
				dis[i+1][j+1]=min(dis[i+1][j+1],dis[i][j]+1);
			else
				dis[i+1][j]=min(dis[i+1][j],dis[i][j]+1),
				dis[i+1][j+1]=min(dis[i+1][j+1],dis[i][j]);
	re(i,1,30) re(j,1,i) cout<<dis[i][j]<<" \n"[j==i];
	re(i,1,30) re(j,1,i) cout<<cal({1,1},{i,j})<<" \n"[j==i];
}

signed main() {
    FAST
//  gao2();
	cin>>_;while(_--) gao();
    return 0;
}
/*
1
8
14 15 8 4 13 3 1 10
6 6 5 2 6 1 1 6

1
6
10 11 7 12 4 3
9 9 6 10 4 3
*/
