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

const int maxn=100005;
const int inf=0x3f3f3f3f3f3f3f3f;
const int mod=1e9+7;

int _,n;
vector<P<int,int> > v;
int mem[maxn];

void gao() {
	v.clear();
	n=read();re(i,1,n) v.pub({read(),i});
	sort(all(v));
	fo(i,0,v.size()) {
		int w=v[i].F,id=v[i].S,ans=-inf;
		int p1=lower_bound(all(v),mkp(mod-w,-inf))-v.begin();
		int p2=p1-1;
		if(p1==i) ++p1;
		if(p2==i) --p2;
		if(p1>=0&&p1<v.size()) ans=max(ans,(w+v[p1].F)%mod);
		if(p2>=0&&p2<v.size()) ans=max(ans,(w+v[p2].F)%mod);
		if(i!=v.size()-1) ans=max(ans,(w+v.back().F)%mod);
		else ans=max(ans,(w+v[v.size()-2].F)%mod);
		mem[id]=ans;
	}
	re(i,1,n) write(mem[i]),printf(" ");
	puts("");
}

signed main() {
    _=read();while(_--) gao();
    return 0;
}
/*
100
3
1 2 1000000007
*/
