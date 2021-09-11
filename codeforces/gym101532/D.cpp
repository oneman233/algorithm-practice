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

const int maxn=10005;
const int inf=0x3f3f3f3f3f3f3f3f;
const int mod=1e9+7;

int _,n,m;
char s[maxn];
int pre[30][maxn];

void gao2() {
	fo(j,0,26) pre[j][0]=0;
	fo(i,0,n) {
		if(i!=0)
			fo(j,0,26)
				pre[j][i]=pre[j][i-1];
		pre[s[i]-'a'][i]++;
	}
}

int ask(int j,char c) {
	if(j==-1) return 0;
	c-='a';
	int ret=0;
	ret+=j/n*pre[c][n-1];
	j%=n;
	return ret+pre[c][j];
}

void gao() {
	n=read(),m=read();
	scanf("%s",s);
	gao2();
	re(i,1,m) {
		int l,r;char c;
		l=read(),r=read();
		scanf("%c",&c);
		l--,r--;
		write(ask(r,c)-ask(l-1,c)),puts("");
	}
}

signed main() {
    _=read();while(_--) gao();
    return 0;
}
/*
1
5 4
aaaaa
5 10 a
5 10 b
1 6 a
1 2 a
*/
