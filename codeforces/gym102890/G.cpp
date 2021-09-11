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

int n,g[maxn],a[maxn],b[maxn];

int dp[maxn],tr[maxn];

int ll(int x){return x<<1;}
int rr(int x){return x<<1|1;}
void up(int p){tr[p]=max(tr[ll(p)],tr[rr(p)]);}
int mm(int x,int y){return x+y>>1;}

int ask(int L,int R,int p=1,int l=1,int r=n) {
	if(L<=l&&r<=R) return tr[p];
	int m=mm(l,r),tmp=-inf;
	if(L<=m) tmp=max(tmp,ask(L,R,ll(p),l,m));
	if(R>m) tmp=max(tmp,ask(L,R,rr(p),m+1,r));
	return tmp;
}

void modi(int X,int V,int p=1,int l=1,int r=n) {
	if(l==r&&l==X) {
		tr[p]=max(tr[p],V);
		return;
	}
	int m=mm(l,r);
	if(X<=m) modi(X,V,ll(p),l,m);
	else modi(X,V,rr(p),m+1,r);
	up(p);
}

signed main() {
    FAST
	cin>>n;re(i,1,n) cin>>g[i]>>a[i]>>b[i];
	int ans=-inf;
	rre(i,n,1) {
		int l=i+a[i],r=i+b[i];
		dp[i]=g[i];
		ans=max(ans,dp[i]);
		if(l>n) {
			modi(i,dp[i]);
			continue;
		}
		r=min(r,n);
		dp[i]+=ask(l,r);
		modi(i,dp[i]);
		ans=max(ans,dp[i]);
	}
//	re(i,1,n) cout<<dp[i]<<' ';cout<<endl;
	cout<<ans;
    return 0;
}
/*
5
1 1 1
1 1 1
3 1 2
5 2 3
10 1 1

8
7 3 5
2 3 5
1 3 5
3 3 5
9 3 5
2 3 5
1 3 5
3 3 5
*/
