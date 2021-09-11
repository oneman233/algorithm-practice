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

int n,m,a[maxn],b[maxn];

mxq_i q;

signed main() {
    FAST
	cin>>n>>m;re(i,1,n) cin>>a[i];re(i,1,n) cin>>b[i];
	bool can=1;
	int ans=0;
	re(i,1,n) {
		if(m>=a[i])
			m-=a[i],
			q.push(b[i]);
		else {
			while(!q.empty()&&m<a[i]) m+=q.top(),q.pop(),++ans;
			if(m<a[i]) {
				can=0;
				ans=i-1;
				break;
			}
			else m-=a[i],q.push(b[i]);
		}
	}
	if(can) cout<<"WIN"<<endl;else cout<<"LOSE"<<endl;
	cout<<ans;
    return 0;
}
