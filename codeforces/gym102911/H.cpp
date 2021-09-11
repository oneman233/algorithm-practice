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

int n,a[maxn],b[maxn];

V<int> v;

int tr[maxn];
int lb(int x) {return x&-x;}
void add(int x,int y) {
	for(int i=x;i<=n;i+=lb(i))
		tr[i]+=y;
}
int sum(int x) {
	int ans=0;
	for(int i=x;i>0;i-=lb(i))
		ans+=tr[i];
	return ans;
}

signed main() {
    FAST
	cin>>n;re(i,1,n) cin>>a[i],v.pub(a[i]);re(i,1,n) cin>>b[i];
	sort(all(v));
	re(i,1,n) a[i]=lower_bound(all(v),a[i])-v.begin()+1;
	int ans=0;
	re(i,1,n) {
		ans+=b[i]*(sum(n)-sum(a[i]));
		add(a[i],b[i]);
	}
	cout<<ans<<endl;
    return 0;
}
