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

int n,g,sum=0;
int p[maxn];
V<int> state;

signed main() {
    FAST
	cin>>n>>g;fo(i,0,n) cin>>p[i],sum+=p[i];
	int mn=inf;
	fo(msk,0,(1ll<<n)) {
		int tot=0,cnt=0;
		fo(i,0,n)
			if(msk&(1ll<<i))
				tot++,cnt+=p[i];
		if(cnt*100/sum>=g) mn=min(mn,tot);
	}
	cout<<mn<<' ';
	fo(msk,0,(1ll<<n)) {
		int tot=0,cnt=0;
		fo(i,0,n)
			if(msk&(1ll<<i))
				tot++,cnt+=p[i];
		if(tot!=mn) continue;
		if(cnt*100/sum>=g) state.pub(msk);
	}
	cout<<state.size()<<endl;
	sort(all(state));
	fo(ii,0,state.size()) {
		int i=state[ii];
		int cnt=0;
		fo(j,0,n)
			if(i&(1ll<<j))
				cnt+=p[j];
		cout<<cnt*100/sum<<' ';
		cnt=0;
		fo(j,0,n)
			if(i&(1ll<<j)) {
				cout<<j+1,++cnt;
				if(cnt==mn) break;
				else cout<<' ';
			}
		if(ii!=state.size()-1) cout<<endl;
	}
    return 0;
}

