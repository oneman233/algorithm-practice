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

int n;
//double a[maxn];
//map<double,int> mp;

int eular(int n)
{
    int ret=1;
    for(int i=2;i*i<=n;i++) {
        if(n%i==0) {
            n/=i,ret*=i-1;
            while(n%i==0) n/=i,ret*=i;
        }
    }
    if(n>1) ret*=n-1;
    return ret;
}

double cal(int x) {
	return (double)eular(x)/x;
}

V<int> a={1,5,29,209,2309,30029,510509,9699689,223092869,6469693229};
V<string> b={"1.000000","0.500000",
			 "0.333333",
			 "0.266667","0.228571",
			 "0.207792","0.191808",
			 "0.180525","0.171024",
			 "0.163588"};

void gao() {
	cin>>n;
    fo(i,0,a.size())
    	if(n<=a[i]) {
			cout<<b[i];
			break;
		}
}

signed main() {
    FAST
//  a[0]=inf;
//	re(i,1,600000) a[i]=cal(i),a[i]=min(a[i],a[i-1]);
//	re(i,1,600000) mp[a[i]]++;
//	for(auto i:mp) cout<<i.F<<' '<<i.S<<endl;
//	fo(i,1,a.size()) a[i]+=a[i-1];for(auto i:a) cout<<i<<',';
//	cout<<1<<' ';
//	fo(i,0,a.size()) cout<<cal(a[i]+1)<<' ';
	gao();
	return 0;
}
