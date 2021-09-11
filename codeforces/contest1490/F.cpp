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

const int maxn=2e5+5;
const int inf=0x3f3f3f3f3f3f3f3f;
const int mod=1e9+7;

int t,n,a[maxn];
map<int,int> mp;
V<int> num;
int l[maxn],r[maxn];
int pre[maxn];

signed main() {
    FAST
	cin>>t;while(t--) {
		mp.clear(),num.clear();
		cin>>n;re(i,1,n) cin>>a[i],mp[a[i]]++;
		num.pub(-1);
		for(auto i:mp) num.pub(i.S);
		int m=num.size()-1;
		sort(all(num));
		memset(l,0,sizeof(l));
		memset(r,0,sizeof(r));
		re(i,1,m) r[num[i]]=i;
		rre(i,m,1) l[num[i]]=i;
		re(i,1,m) pre[i]=pre[i-1]+num[i];
		auto cal=[](int L,int R) {
			if(L>R) return 0ll;
			return pre[R]-pre[L-1];
		};
		mp.clear();
		re(i,1,m) mp[num[i]]=1;
		int ans=inf;
		for(auto ii:mp) {
			int i=ii.F;
//			cout<<i<<' '<<cal(1,l[i]-1)+cal(r[i]+1,m)-(m-r[i])*i<<endl;
			ans=min(ans,cal(1,l[i]-1)+cal(r[i]+1,m)-(m-r[i])*i);
		}
		cout<<ans<<endl;
	}
    return 0;
}
/*
2
5
1 1 1 1 1
5
1 2 3 4 5
*/
