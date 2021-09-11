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

int _,n,a[105][105];

bool can() {
	auto ok=[](int i,int j) {
		return i<=n&&i>=1&&j<=n&&j<=n;
	};
	re(i,1,n)
		re(j,1,n) {
			if(ok(i+1,j)&&abs(a[i][j]-a[i+1][j])==1) return 0;
			if(ok(i-1,j)&&abs(a[i][j]-a[i-1][j])==1) return 0;
			if(ok(i,j+1)&&abs(a[i][j]-a[i][j+1])==1) return 0;
			if(ok(i,j-1)&&abs(a[i][j]-a[i][j-1])==1) return 0;
		}
	return 1;
}

signed main() {
    FAST
	cin>>_;
	while(_--) {
		cin>>n;
		if(n==1) {
			cout<<1<<endl;
			continue;
		}
		else if(n==2) {
			cout<<-1<<endl;
			continue;
		}
		else if(n==3) {
			cout<<"2 9 7"<<endl;
			cout<<"4 6 3"<<endl;
			cout<<"1 8 5"<<endl;
			continue;
		}
		int now=1,i=1,j=1;
		while(i<=n&&j<=n) {
//			cout<<i<<' '<<j<<endl;
			a[i][j]=now++;
			j+=2;
			if(j>n) ++i,j=1;
		}
		i=1,j=2;
		while(i<=n&&j<=n) {
//			cout<<i<<' '<<j<<endl;
			a[i][j]=now++;
			j+=2;
			if(j>n) ++i,j=2;
		}
		re(i,1,n) re(j,1,n) cout<<a[i][j]<<" \n"[j==n];
//		assert(can);
	}
    return 0;
}
