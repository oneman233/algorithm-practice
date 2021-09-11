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

V<int> v;

int t,n;

signed main() {
    FAST
	re(i,1,9) v.pub(i);
	for(int i=11;i<=99;i+=11) v.pub(i);
	for(int i=111;i<=999;i+=111) v.pub(i);
	for(int i=1111;i<=9999;i+=1111) v.pub(i);
	for(int i=11111;i<=99999;i+=11111) v.pub(i);
	for(int i=111111;i<=999999;i+=111111) v.pub(i);
	for(int i=1111111;i<=9999999;i+=1111111) v.pub(i);
	for(int i=11111111;i<=99999999;i+=11111111) v.pub(i);
	for(int i=111111111;i<=999999999;i+=111111111) v.pub(i);
	cin>>t;
	while(t--) {
		cin>>n;
		int ans=lower_bound(all(v),n)-v.begin();
		if(*lower_bound(all(v),n)==n) ++ans;
		cout<<ans<<endl;
	}
    return 0;
}
