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

int _,n,fac[maxn];

int qpow(int x,int y) {
	int ret=1;
	x%=mod;
	while(y) {
		if(y&1) ret=ret*x%mod;
		x=x*x%mod;
		y>>=1;
	}
	return ret;
}

int c(int n,int m) {
	if(n<m) return 0;
	return (fac[n]*qpow(fac[m],mod-2)%mod*qpow(fac[n-m],mod-2))%mod;
}

int lucas(int n,int m) {
	if(m==0) return 1;
	return c(n%mod,m%mod)*lucas(n/mod,m/mod)%mod;
}

signed main() {
    FAST
    cin>>_;
    fac[0]=1;
    re(i,1,3e5) fac[i]=fac[i-1]*i%mod;
    while(_--) {
		cin>>n;
		--n;
		cout<<lucas(2*n+1,n+1)<<endl;
	}
    return 0;
}
