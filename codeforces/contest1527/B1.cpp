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

void gao() {
	cin>>n>>s;
	int cnt=0;
	for(auto i:s) cnt+=i=='0';
	if(cnt==0) cout<<"DRAW"<<endl;
	else if(cnt==1) cout<<"BOB"<<endl;
	else if(cnt==2) cout<<"BOB"<<endl;
	else if(cnt==3) cout<<"ALICE"<<endl;
	else {
		if(cnt%2==0) {
//			cnt/=2;
//			if(cnt%2==0) cout<<"DRAW"<<endl;
//			else 
			cout<<"BOB"<<endl;
		}
		else {
			cout<<"ALICE"<<endl;
		}
	}
}

signed main() {
    FAST
	cin>>_;
	while(_--) gao();
    return 0;
}
