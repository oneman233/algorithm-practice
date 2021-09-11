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

int _,n;
int t[maxn],id[maxn],s[maxn];
int pre[maxn];
stack<P<int,int> > start,sum;
map<int,int> ans;

void gao() {
	cin>>n;
	ans.clear();
	while(!start.empty()) start.pop();
	while(!sum.empty()) sum.pop();
	re(i,1,n) cin>>t[i]>>id[i]>>s[i];
	pre[0]=0;
	re(i,1,n) pre[i]=pre[i-1]+(s[i]==1);
//	re(i,1,n) cout<<pre[i]<<' ';cout<<endl;
	re(i,1,n) {
		if(s[i]==0) start.push({i,t[i]});
		else {
			auto cal=[](int i,int j){return pre[j]-pre[i-1];};
			auto p=start.top();
			start.pop();
			int tot=t[i]-p.S;
			int cnt=cal(p.F,i)-1;
			int t1=tot,t2=cnt;
//			cout<<id[i]<<' '<<cnt<<endl;
			while(!sum.empty()&&cnt!=0) {
				tot-=sum.top().F;
				cnt-=sum.top().S;
				sum.pop();
			}
			assert(cnt==0);
			sum.push({t1,t2+1});
			ans[id[i]]=tot;
		}
	}
//	for(auto i:ans) cout<<i.F<<' '<<i.S<<endl;
	int mx=-inf,p=-1;for(auto i:ans) if(i.S>mx) mx=i.S,p=i.F;cout<<p<<endl;
}

signed main() {
    FAST
	cin>>_;while(_--) gao();
    return 0;
}

