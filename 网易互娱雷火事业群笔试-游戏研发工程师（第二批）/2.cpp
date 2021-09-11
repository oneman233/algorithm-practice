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

int n,m;
struct node {
	int a,b,c;
	node(){}
	bool inter(node d) {
		int cnt=0;
		if(a==d.a||a==d.b||a==d.c) ++cnt;
		if(b==d.a||b==d.b||b==d.c) ++cnt;
		if(c==d.a||c==d.b||c==d.c) ++cnt;
		return cnt>=2;
	}
	bool hav(int x,int y) {
		return a==x&&b==y||
			   b==x&&c==y||
			   c==x&&a==y;
	}
	bool dif(node d) {
		if(d.hav(a,b)||d.hav(b,c)||d.hav(c,a)) return 1;
		return 0;
	}
	void lft() {
		int tmp=a;
		a=b;
		b=c;
		c=tmp;
	}
	void rev(){swap(a,c);}
};
node nd[805];
bool vis[805];
queue<int> q;

signed main() {
    FAST
	cin>>n>>m;
	re(i,1,m) cin>>nd[i].a>>nd[i].b>>nd[i].c;
	while(nd[1].a!=min({nd[1].a,nd[1].b,nd[1].c})) nd[1].lft();
	q.push(1);
	while(!q.empty()) {
		int f=q.front();
		q.pop();
		if(vis[f]) continue;
		vis[f]=1;
		re(i,1,m)
			if(!vis[i]&&nd[f].inter(nd[i])) {
				if(nd[f].dif(nd[i])) nd[i].rev();
				while(nd[i].a!=min({nd[i].a,nd[i].b,nd[i].c})) nd[i].lft();
				q.push(i);
			}
	}
	re(i,1,m) assert(vis[i]);
	re(i,1,m) cout<<nd[i].a<<' '<<nd[i].b<<' '<<nd[i].c<<endl;
    return 0;
}
/*
6 4
1 5 2
6 1 5
6 4 5
4 5 3
*/
