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
string s;
V<int> p;
int pre[maxn];
int ans,sz;

int sum(int l,int r) {
	if(l==0) return pre[r];
	return pre[r]-pre[l-1];
}

int add(int l,int r) {
	return (l+r)*(r-l+1)/2;
}

signed main() {
    FAST
	cin>>_;
	while(_--) {
		cin>>n>>s;
		s='$'+s;
		p.clear();
		re(i,1,n) if(s[i]=='*') p.pub(i);
		if(p.empty()) {
			cout<<0<<endl;
			continue;
		}
		ans=inf,sz=p.size();
		pre[0]=p[0];
		fo(i,1,sz) pre[i]=pre[i-1]+p[i];
		auto cal=[](int id) {
			return sum(id,sz-1)-(sz-id)*p[id]-add(id,sz-1)+(sz-id)*id+
				   id*p[id]-sum(0,id-1)-id*id+add(0,id-1);
		};
//		fo(i,0,sz) cout<<cal(i)<<endl;
		fo(i,0,sz) ans=min(ans,cal(i));cout<<ans<<endl;
	}
    return 0;
}
/*
1
4
*..*
*/
