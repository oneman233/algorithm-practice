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

int _,l,k;
string s;

void gao() {
	cin>>s>>k;
	l=s.length();
	int kk=0,flg=0;
	fo(i,0,l)
		if(isdigit(s[i])) {
			int j=i;
			while(j<l&&isdigit(s[j])) ++j;
			if(j-i>6) {
				cout<<"unfeasible"<<endl;
				return;
			}
			int tmp=0;
			fo(k,i,j) tmp*=10,tmp+=s[k]-'0';
//			cout<<"! "<<tmp<<endl;
			kk+=tmp;
			flg=1;
		}
		else {
			if(flg) flg=0;
			else ++kk;
		}
//	cout<<"? "<<kk<<endl;
	if(kk>k) {
		cout<<"unfeasible"<<endl;
		return;
	}
	int cnt=1;
	string t="";
	fo(i,0,l) {
		if(isdigit(s[i])) {
			int j=i;
			while(j<l&&isdigit(s[j])) ++j;
			if(j-i>6) {
				cout<<"unfeasible"<<endl;
				return;
			}
			cnt=0;
			fo(k,i,j) cnt*=10,cnt+=s[k]-'0';
		}
		else {
			while(cnt--) t+=s[i];
			cnt=1;
		}
	}
	cout<<t<<endl;
}

signed main() {
    FAST
	cin>>_;while(_--) gao();
    return 0;
}
/*
4
5a2bc 8
5a2bc 7
asdf4x 50
asjkdf10000000000kz 1000000
*/
